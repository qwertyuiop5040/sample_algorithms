/*
	Performance on a 2.7 Ghz computer:
	n=10e5 -> 0.01 seconds
	n=10e6 -> 0.16 seconds
	n=5*10e6 -> 1.27 seconds
	n=10e7 -> 3.15 seconds
*/
#include<vector>
vector<int> sieve(int n){
	vector<int>p;
	p.push_back(2);
	p.push_back(3);
	for(int i=5;i<n;i+=2){
		bool good=true;
		for(int j=0;j<p.size()&&p[j]*p[j]<i;j++){
			if(i%p[j]==0){
				good=false;
				break;
			}
		}
		if(good)p.push_back(i);
	}
	return p;
}
