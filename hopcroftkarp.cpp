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
#include <ctime>
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
int dist[100005]={0};
bool touched[100005]={0};
bool dfs(int idx){
	touched[idx]=true;
	for(pair<int,ll>pr:r[idx]){
		if(pr.fi==t){
			if(pr.se==0)continue;
			r[idx].find(t)->se=0;
			r[t].find(idx)->se=1;
			return true;
		}else if(dist[pr.fi]==dist[idx]+1){
			if(!touched[pr.fi]){
				if(pr.se!=0&&dfs(pr.fi)){
					r[idx].find(pr.fi)->se=0;
					r[pr.fi].find(idx)->se=1;
					return true;
				}
			}
		}
	}
	return false;
}
bool bfs(){
	forn(i,n+m+2){
		lv[i]=NOT_VISITED;
		dist[i]=10000000;
		touched[i]=0;
	}
	lv[t]=BASE_VERTEX;
	bool tIsReachable=false;
	lv[s]=BASE_VERTEX;
	queue<ll>path;
	path.push(s);
	dist[s]=0;
	while(!path.empty()){
		int cur=path.front();
		path.pop();
		for(pair<int,ll> i:r[cur]){
			int to=i.fi;
			if(i.se!=0&&to==t){
				tIsReachable=true;
			}
			else if(lv[to]==NOT_VISITED&&i.se!=0){
				path.push(to);
				lv[to]=cur;
				dist[to]=dist[cur]+1;
			}
		}
	}
	return tIsReachable;
}
void hopcroftkarp(){
	while(bfs()){
		for(pair<int,ll>pr:r[s]){
			if(pr.se!=0&&(dfs(pr.fi))){
				r[s].find(pr.fi)->se=0;
				r[pr.fi].find(s)->se=1;
				maxFlow++;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
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
	}
	forn1(i,n){
		r[s].ins(mp(i,1));
		r[i].ins(mp(s,0));
	}
	for(int i=n+1;i<=n+m;i++){
		r[t].ins(mp(i,0));
		r[i].ins(mp(t,1));
	}
	hopcroftkarp();
	cout<<maxFlow<<endl;
	return 0;
}