#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <sstream>
#include <numeric>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
#define forn1(i,n) for(int i=1;i<=n;i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
int t,n;
#define MAXN 100001
#define SQN 320
#define MAXQ 100001
int v[MAXN];//values array
int p[MAXN];//position array
pii lr[MAXQ];//queries
int ans[MAXQ];//answer arraw
int bS;//bucket size
int nBS;//number of buckets
int lB;//last bucket size
int nLB;//number of last buckets (at most 1)
bool compSeFi(int j,int k){
	if(lr[j].se!=lr[k].se)
		return lr[j].se<lr[k].se;
	return lr[j].fi<lr[k].fi;
}
int bucket(int num){return num/bS;}
int main(){
		cin>>n;
		forn(i,n)cin>>v[i];
		bS=ceil(pow((double)n,0.5));
		nBS=n/bS;
		lB=n%bS;
		nLB=(lB!=0);//total buckets= nBS+nLB
		int q;cin>>q;
		forn(i,q)cin>>lr[i].fi>>lr[i].se;
		iota(p,p+q,0);
		sort(p,p+q,[](int j,int k){return lr[j]<lr[k];});
		int sIdx=0;//startindex
		int eIdx=0;
		forn(i,nBS){
			eIdx=sIdx;//endindex
			while(eIdx<q-1&&lr[p[eIdx]].fi<bS*(i+1))eIdx++;
			sort(p+sIdx,p+eIdx,compSeFi);
			sIdx=eIdx;
		}
		if(nLB!=0)sort(p+eIdx,p+q,compSeFi);
		fill(ans,ans+q,-1);
		int left=0;
		int right=-1;
		forn(i,q){
			int lGoal=lr[p[i]].fi;
			int rGoal=lr[p[i]].se;
			if(right<rGoal){
				while(right<rGoal){
					right++;//increment first
					int vr=v[right];//F(n)
					int bkt=bucket(vr);//bucket of vr
				}
			}else{
				while(right>rGoal){
					int vr=v[right];//F(n)
					right--;//increment last
				}
			}
			if(left<lGoal){
				while(left<lGoal){
					int vl=v[left];//F(n)
					left++;//increment last
				}
			}else{
				while(left>lGoal){
					left--;//increment first
					int vl=v[left];//F(n)
				}
			}
			//postprocessing here
		}
		forn(i,q)cout<<ans[i]<<endl;
	return 0;
}