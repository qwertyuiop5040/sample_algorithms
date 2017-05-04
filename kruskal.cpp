struct union_find{
    int*setSize=NULL;
    int*parent=NULL;
    union_find(int totSets){
        setSize=new int[totSets];
        parent=new int[totSets];
        iota(parent,parent+totSets,0);
        fill(setSize,setSize+totSets,1);
    }
    ~union_find(){
    	if(setSize!=NULL)delete [] setSize;
    	if(parent!=NULL)delete [] parent;
    }
    int find(int s){
        if(parent[s]!=s){
            parent[s]=find(parent[s]);
            return parent[s];
        }
        return s;
    }
    bool connected(int s,int j){
        return find(s)==find(j);
    }
    void u(int i, int j){//union
        int ii=find(i),jj=find(j);
        if(setSize[ii]>=setSize[jj]){
            setSize[ii]+=setSize[jj];
            parent[jj]=ii;
        }else{
            setSize[jj]+=setSize[ii];
            parent[ii]=jj;
        }
    }
};
/*
    te[0]=value te[1]=src te[2]=dest
    p[i]=position of the ith biggest edge
    nE=number edges, nN=number nodes
*/
int te[20][3];
int p[20];
int kruskal(int nE,int nN){
    iota(p,p+nE,0);
    sort(p,p+nE,[](int j,int k){return te[j][0]<te[k][0];});
    union_find uf(nN);
    int mst=0;
    forn(i,nE){
        int idx=p[i];
        int a=te[idx][1],b=te[idx][2];
        if(!uf.connected(a-1,b-1)){
            mst+=te[idx][0];
            uf.u(a-1,b-1);
        }
    }
    return mst;
}
