/*
	Programming Assignment 2
	By Hanqing Wang, 9594458
	This is a Prim's algorithm O(|E|log|V|) implementation to find the MST of a graph.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <cmath>
#define forn(i,n) for(int i=0;i<n;i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pq priority_queue
using namespace std;
typedef pair<int,int> pii;
typedef pair<double,int> pdi;

struct Point{
public:
	double x,y;
	Point(double x,double y):x(x),y(y){}
	Point(){}
};

double distSquared(Point p1,Point p2){//distance squared vs distance doesn't matter, distance squared is easier to compute
	double dx=(p1.x-p2.x);
	double dy=(p1.y-p2.y);
	return dx*dx+dy*dy;
}

int main(){
	int n,m;
	cin>>n;
	Point*vertices=new Point[n];
	forn(i,n)
		cin>>vertices[i].x>>vertices[i].y;
	cin>>m;
	vector<pdi>*adjMatrix=new vector<pdi>[n];//adjacency matrix: is a vector of pair<double,int> where the double is the distance, int is the vertex that adjMatrix[i] is connected to.
	forn(i,m){//adding edges here
		int idx1,idx2;
		cin>>idx1>>idx2;
		double distSq=distSquared(vertices[idx1],vertices[idx2]);
		adjMatrix[idx1].push_back(mp(distSq,idx2));
		adjMatrix[idx2].push_back(mp(distSq,idx1));
	}
	if(m==0){//special case, fully connected graph
		forn(i,n){
			forn(j,i){
				double distSq=distSquared(vertices[i],vertices[j]);
				adjMatrix[i].push_back(mp(distSq,j));
				adjMatrix[j].push_back(mp(distSq,i));
			}
		}
	}
	bool*alreadyVisited=new bool[n];//vertices already added to mst
	fill(alreadyVisited,alreadyVisited+n,false);
	int currentEdgeIndex=0;//last vertex added to mst, start with vertex 0
	int edgesVisited=0;//number of vertices already added to mst
	pq<pair<double,pii>,vector<pair<double,pii> >,greater<pair<double,pii> > >edges;//priority_queue ===== pq, pii ==== pair<int,int>
	bool badInput=false;//mst was incomplete
	pq<pii,vector<pii>,greater<pii> >mst;
	while(edgesVisited<n){
		alreadyVisited[currentEdgeIndex]=true;
		edgesVisited++;
		forn(i,adjMatrix[currentEdgeIndex].size()){//This loop is O(|E|) over all iterations because there are only O(|E|) edges to add
			pdi temp=adjMatrix[currentEdgeIndex][i];
			if(!alreadyVisited[temp.se])
				edges.push(mp(temp.fi,mp(currentEdgeIndex,temp.se)));
		}
		bool foundNextEdge=false;
		while(!edges.empty()&&!foundNextEdge){//This loop is O(|E|log|E|)=O(|E|log|V|) over all iterations of the outer loop because there are only O(|E|) edges,
			pair<double,pii> temp=edges.top();//and one edge is removed every iteration of this loop
			if(!alreadyVisited[temp.se.se]){//temp.se is a pair of indexes containing src and dest. We know for sure src has already been visited.
				foundNextEdge=true;//wrap
				int bigger=max(temp.se.fi,temp.se.se);
				int smaller=min(temp.se.fi,temp.se.se);
				mst.push(mp(smaller,bigger));
				currentEdgeIndex=temp.se.se;
			}
			edges.pop();
		}
		if(!foundNextEdge&&edgesVisited<n){//no more adjacent edges and mst isn't complete
			badInput=true;
			break;
		}
	}
	if(badInput){
		cout<<"The inputed data is invalid or does not have a MST."<<endl;
	}else{
		while(!mst.empty()){
			pii temp=mst.top();
			cout<<temp.fi<<" "<<temp.se<<endl;
			mst.pop();
		}
	}
	delete [] vertices;
	delete [] adjMatrix;
	delete [] alreadyVisited;
	return 0;
}