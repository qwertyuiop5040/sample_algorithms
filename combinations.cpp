#include <iostream>
using namespace std;
void comb(int n, int r, int*arr, int sz, int*sel, int sOn){
	for(int i=sz-n;i<sz;i++){
		sel[sOn]=arr[i];
		if(r>1){
			comb(sz-i-1,r-1,arr,sz,sel,sOn+1);
		}else{
      /*
        Or whatever function we need to perform, sel contains all the selected array elements.
      */
			for(int j=0;j<=sOn;j++){
				cout<<sel[j]<<" ";
			}
			cout<<endl;
		}
	}
}
void combination(int n, int r, int*arr){
	if(r==0)return;
	const int rr=r;
	int temp[rr];
	comb(n,rr,arr,n,temp,0);
}

int main(){
	int aS=8;
	int a[aS]={8,7,6,5,4,4,2,1};
	int c=3;
	combination(aS,c,a);
  return 0;
}
