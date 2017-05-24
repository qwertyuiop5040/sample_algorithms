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
