/* O(ElogV) implementation */
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
vector<pll>e[100005];
pll dp[100005];//dp[0]=dist,dp[1]=index it comes from
vector<ll>path;
bool v[100005]={0};//visited
void djikstra(){
	priority_queue<pll,vector<pll>,greater<pll>>vrtx;
	vrtx.push(mp(0,1));
	forn1(i,n)dp[i]=mp(LLONG_MAX,-1);
	dp[1]=mp(0,-1);
	while(!vrtx.empty()){
		int idx=vrtx.top().se;
		if(idx==n)break;
		vrtx.pop();
		if(v[idx])continue;
		v[idx]=true;
		forn(i,e[idx].size()){
			ll edge=e[idx][i].fi,weight=e[idx][i].se;
			if(v[edge])continue;
			if(dp[idx].fi+weight<dp[edge].fi){
				dp[edge]=mp(dp[idx].fi+weight,idx);
				vrtx.push(mp(dp[edge].fi,edge));
			}
		}
	}
	int curr=n;
	if(dp[n].se!=-1)path.pb(n);
	else path.pb(-1);
	while(dp[curr].se!=-1){
		curr=dp[curr].se;
		path.pb(curr);
	}
}
int main(){
	cin>>n>>m;
	forn(i,m){
		ll a,b,c;
		cin>>a>>b>>c;
		e[a].push_back(mp(b,c));
		e[b].push_back(mp(a,c));
	}
	djikstra();
	for(int i=path.size()-1;i>=0;i--){
		printf("%d ",path[i]);//~1% faster
	}cout<<endl;
	return 0;
}
