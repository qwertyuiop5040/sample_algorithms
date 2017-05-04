struct UnionFind{
    int*setSize=NULL;
    int*parent=NULL;
    UnionFind(int totSets){
        setSize=new int[totSets];
        parent=new int[totSets];
        for(int i=0;i<totSets;i++){
            parent[i]=0;
            setSize[i]=1;
        }
    }
    int find(int s){
        if(parent[s]!=NULL){
            parent[s]=find(parent[s]);
            return parent[s];
        }
        else
            return s;
    }
    bool connected(int s,int j){
        return find(s)==find(j);
    }
    void u(int i, int j){//union
        int ii=find(i),jj=find(j);
        if(setSize[ii]>=setSize[jj]){
            setSize[ii]+=setSize[jj];
            parent[jj]+=ii;
        }else{
            setSize[jj]+=setSize[ii];
            parent[ii]=jj;
        }
    }
};
