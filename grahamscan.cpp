/*
	O(nlogn)
*/
#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
#define forn1(i,n) for(int i=1;i<=n;i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
# define M_PIl 3.141592653589793238462643383279502884L
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int t,n;
pll pts[100001];
double theta[100001];
double thetaRelative[100001];
stack<int>convex_hull;
set<int>seen[20002];
int pos[100001]={0};
int posTheta[100001]={0};
double dist(pll a, pll b){return pow((a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se),0.5);}
double angleBetween(int a, int piv){
	double curTheta=(atan2((pts[a].se-pts[piv].se),(pts[a].fi-pts[piv].fi)));
	if(curTheta<0)curTheta=2*M_PI+curTheta;
	return curTheta;
}
void grahamscan(){//returns convex hull pts in order.
	int idxSmallestY=0;
	ll smallestY=pts[0].se;
	ll smallestX=pts[0].fi;
	forn(i,n){
		if(pts[i].se<smallestY||(pts[i].se==smallestY&&pts[i].fi<smallestX)){
			smallestY=pts[i].se;
			smallestX=pts[i].fi;
			idxSmallestY=i;
		}
	}
	forn(i,n){
		if(i==idxSmallestY)theta[i]=0;
		else theta[i]=angleBetween(i,idxSmallestY);
		posTheta[i]=i;
	}
	sort(posTheta,posTheta+n,[idxSmallestY](int j, int k){
		if(theta[j]!=theta[k])return theta[j]<theta[k];
		return dist(pts[j],pts[idxSmallestY])<dist(pts[k],pts[idxSmallestY]);
	});
	convex_hull.push(idxSmallestY);
	thetaRelative[idxSmallestY]=0;
	forn(i,n){
		int ii=posTheta[i];
		if(ii==idxSmallestY)continue;
		bool leftTurn=false;
		while(convex_hull.size()>1&&!leftTurn){
			int recentIdx=convex_hull.top();
			double curTheta=angleBetween(ii,recentIdx);
			double lastTheta=thetaRelative[recentIdx];
			double curThetaRelative=(2*M_PI+curTheta-lastTheta);
			curThetaRelative=curThetaRelative-2*M_PI*double(int(curThetaRelative/(2*M_PI)));
			assert(curThetaRelative>=0.0);
			if(curThetaRelative<=1e-12||curThetaRelative>=M_PI)convex_hull.pop();//1e-12 only if needed
			else leftTurn=true;
		}
		thetaRelative[ii]=angleBetween(ii,convex_hull.top());
		convex_hull.push(ii);
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cout<<setprecision(2)<<fixed;
 	cin>>t;
 	forn1(testNum,t){
 		cin>>n;
 		int ctr=0;
 		forn(i,n){
 			cin>>pts[ctr].first>>pts[ctr].second;
 			if(seen[pts[ctr].fi+10000].find(pts[ctr].se)==seen[pts[ctr].fi+10000].end()){
 				seen[pts[ctr].fi+10000].insert(pts[ctr].se);
 				pos[ctr]=i;
 				ctr++;
 			}
 		}
 		n=ctr;
    	grahamscan();
    	double totDist=0;
    	vector<int>chidx;
    	while(!convex_hull.empty()){
    		chidx.pb(convex_hull.top());
    		convex_hull.pop();
    	}
    	forn(i,chidx.size())totDist+=dist(pts[chidx[i]],pts[chidx[(i+1)%chidx.size()]]);
    	cout<<totDist<<"\n";
    	cout<<pos[chidx[chidx.size()-1]]+1;
    	for(int i=chidx.size()-2;i>=0;i--)cout<<" "<<pos[chidx[i]]+1;
    	cout<<"\n\n";
    	chidx.clear();
    	forn(i,n){
    		int j=seen[pts[i].fi+10000].erase(pts[i].se);
    		assert(j==1);
    	}
 	}
	return 0;
}