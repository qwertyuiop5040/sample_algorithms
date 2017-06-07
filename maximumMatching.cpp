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
#include <unordered_map>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
#define forn1(i,n) for(int i=1;i<=n;i++)
#define mp make_pair
#define pb push_back
#define ins insert
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n,m;
#define BASE_VERTEX -2
#define NOT_VISITED -1
vector<ll>e[100005];
unordered_map<int,ll>r[100005];
ll maxFlow=0;
int s,t;
int lv[100005];//last visited, can backtrack
bool bfs(){
	forn(i,n+m+2)lv[i]=NOT_VISITED;
	lv[s]=BASE_VERTEX;
	queue<ll>path;
	path.push(s);
	while(!path.empty()){
		int cur=path.front();
		path.pop();
		for(pair<int,ll> i:r[cur]){
			// cout<<cur<<" "<<i.fi<<" "<<i.se;
			int to=i.fi;
			if(lv[to]==NOT_VISITED&&i.se!=0){
				// cout<<" pushed";
				path.push(to);
				lv[to]=cur;
			}
			// cout<<endl;
		}
	}
	return lv[t]!=NOT_VISITED;
}
void edmondkarp(){
	while(bfs()){
		int mn=-1;
		int cur=t;
		while(lv[cur]!=BASE_VERTEX){
			r[lv[cur]].find(cur)->se=0;
			r[cur].find(lv[cur])->se=1;
			cur=lv[cur];
		}
		maxFlow++;
	}
}
int main(){
	s=0;
	int p;
	cin>>n>>m>>p;
	t=n+m+1;
	forn(i,p){
		int a,b;
		cin>>a>>b;
		b+=n;
		r[a].ins(mp(b,1));
		r[b].ins(mp(a,0));
		// cout<<a<<" "<<b<<endl;
	}
	forn1(i,n){
		r[s].ins(mp(i,1));
		r[i].ins(mp(s,0));
	}
	for(int i=n+1;i<=n+m;i++){
		r[t].ins(mp(i,0));
		r[i].ins(mp(t,1));
	}
	// forn(i,n+m+2){
	// 	for(auto j:r[i]){
	// 		cout<<j.fi<<" "<<j.se<<"  ";
	// 	}cout<<endl;
	// }
	edmondkarp();
	cout<<maxFlow<<endl;
	return 0;
}