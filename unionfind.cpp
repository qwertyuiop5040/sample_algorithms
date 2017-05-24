#include<numeric>
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
