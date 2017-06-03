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
#define BASE_VERTEX -2
#define NOT_VISITED -1
vector<ll>e[1001];
ll r[1001][1001];
ll maxFlow=0;
int s,t;
int lv[1001];//last visited, can backtrack
bool bfs(){
	forn(i,n)lv[i]=NOT_VISITED;
	lv[s]=BASE_VERTEX;
	queue<ll>path;
	path.push(s);
	while(!path.empty()){
		int cur=path.front();
		path.pop();
		forn(i,e[cur].size()){
			int to=e[cur][i];
			if(lv[to]==NOT_VISITED&&r[cur][to]!=0){
				path.push(to);
				lv[to]=cur;
			}
		}
	}
	return lv[t]!=NOT_VISITED;
}
void fordfulkerson(){
	while(bfs()){
		int mn=-1;
		int cur=t;
		while(lv[cur]!=BASE_VERTEX){
			if(mn==-1||r[lv[cur]][cur]<mn)mn=r[lv[cur]][cur];
			cur=lv[cur];
		}
		cur=t;
		while(lv[cur]!=BASE_VERTEX){
			r[lv[cur]][cur]-=mn;
			r[cur][lv[cur]]+=mn;
			cur=lv[cur];
		}
		maxFlow+=mn;
	}
}
