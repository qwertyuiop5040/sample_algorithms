/*
	O(nh)
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
vector<int> convex_hull;
set<int>seen[20002];
int pos[100001]={0};
double dist(pll a, pll b){return pow((a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se),0.5);}
void gift_wrap(){//returns convex hull pts in order.
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
	convex_hull.pb(idxSmallestY);
	bool loopedAround=false;
	int curIdx=idxSmallestY;
	double lastTheta=M_PI;
	double dst=-1;
	while(!loopedAround){
		double bestThetaRelative=1000000;
		double bestTheta=1000000;
		int bestIdx=-1;
		forn(i,n){
			if(i==curIdx)continue;
			double curTheta=(atan2((pts[i].se-pts[curIdx].se),(pts[i].fi-pts[curIdx].fi)));
			if(curTheta<0)curTheta=2*M_PI+curTheta;
			double curThetaRelative=(lastTheta-curTheta>=0)?lastTheta-curTheta:(2*M_PI+lastTheta-curTheta);
			assert(curThetaRelative>=0.0);
			if(curThetaRelative<bestThetaRelative||(curThetaRelative==bestThetaRelative&&dist(pts[i],pts[curIdx])>dst)){
				bestThetaRelative=curThetaRelative;
				bestTheta=curTheta;
				bestIdx=i;
				dst=dist(pts[i],pts[curIdx]);
			}
		}
		if(bestIdx!=-1){
			convex_hull.pb(bestIdx);
			curIdx=bestIdx;
			lastTheta=bestTheta;
		}
		if(curIdx==idxSmallestY)loopedAround=true;
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
    	gift_wrap();
    	double totDist=0;
    	forn1(i,convex_hull.size()-1)totDist+=dist(pts[convex_hull[i]],pts[convex_hull[i-1]]);
    	cout<<totDist<<"\n";
    	cout<<pos[convex_hull[0]]+1;
    	for(int i=convex_hull.size()-2;i>=1;i--){
    		cout<<" "<<pos[convex_hull[i]]+1;
    	}cout<<"\n";
    	cout<<"\n";
    	convex_hull.clear();
    	forn(i,n){
    		int j=seen[pts[i].fi+10000].erase(pts[i].se);
    		assert(j==1);
    	}
 	}
	return 0;
}