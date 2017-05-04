#include <algorithm>
using namespace std;
void quickSort(int* a,int b,int e){
    int p=(b+e)/2;
    int l=b,r=e;
    while(l<r){
        if(a[l]>=a[p]&&a[r]<=a[p]){
            if(a[l]==a[p])p=r;
            else if(a[r]==a[p])p=l;
            swap(a[l],a[r]);
        }
        if(a[l]<a[p])l++;
        if(a[r]>a[p])r--;
    }
    if(p-b>1)quickSort(a,b,p);
    if(e-p>1)quickSort(a,p,e);
}
