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
#include <climits>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
#define forn1(i,n) for(int i=1;i<=n;i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n,m;
vector<ll>e[5001];
ll r[5001][5001];
ll maxFlow=0;
int s,t;//MUST GUARANTEE that s=1, t=n (|V|)
ll h[5001]={0};
ll of[5001]={0};
ll p[5001];
int hc[20000]={0};
void push(int u,int v){
	ll toAdd=min(of[u],r[u][v]);
	r[u][v]-=toAdd;
	r[v][u]+=toAdd;
	of[u]-=toAdd;
	of[v]+=toAdd;
}
void relabel(int u){
	ll minH=-1;
	hc[h[u]]--;
	forn(i,e[u].size())
		if((minH==-1||minH>h[e[u][i]])&&r[u][e[u][i]]>0)
			minH=h[e[u][i]];
	h[u]=minH+1;
	hc[h[u]]++;
}
void discharge(int u){
	int v=0;//current index, e[u] guaranteed to have at least one element if discharge is called
	bool gap=true;
	int oldHeight;
	while(of[u]>0){
		oldHeight=h[u];
		if(hc[h[u]]==1&&h[u]!=0&&gap){
			int minGap=h[u];
			if(minGap<n){
				for(int i=2;i<n;i++){
				 	if(h[i]>minGap){
				 		int oh=h[i];
				 		hc[h[i]]--;
				 		h[i]=max(h[i],ll(n+1));
				 		hc[h[i]]++;
				 	}
				}
			}
			gap=false;
			v=e[u].size();
		}
		if(v>=e[u].size()){
			relabel(u);
			v=0;
		}else{
			if(u!=e[u][v]&&r[u][e[u][v]]>0&&h[u]==h[e[u][v]]+1)push(u,e[u][v]);
			v++;
		}
	}
}
void relabelToFront(){
	int s=1,t=n;
	ll sRS=0;//source resid sum;
	hc[0]=n-1;
	hc[n]=1;
	forn(i,e[s].size()){
		int idx=e[s][i];
		sRS+=r[s][idx];
		of[s]+=r[s][idx];
		push(s,idx);
	}
	of[s]-=sRS;
	h[s]=n;
	iota(p,p+n+1,0);
	int cur=s+1;
	while(cur!=t){
		int idx=p[cur];
		ll oh=h[idx];
		discharge(idx);
		if(h[idx]>oh){
			int idx1=s+1;
			int idx2=cur;
			ll v1=p[idx2];
			for(int i=idx2;i>idx1;i--)p[i]=p[i-1];
			p[idx1]=v1;
			cur=s+1;
		}
		cur++;
	}
	maxFlow=of[t];
}
int main(){
	cin>>n>>m;
	forn1(i,n)
		forn1(j,n)
			r[i][j]=0;
	forn(i,m){
		int a,b;
		cin>>a>>b;
		ll x;
		cin>>x;
		if(a!=b){
			e[a].push_back(b);
			e[b].push_back(a);
			r[a][b]+=x;
			r[b][a]+=x;
		}
	}
	relabelToFront();
	cout<<maxFlow<<endl;
	return 0;
}