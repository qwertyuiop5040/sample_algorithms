/*
	Random points
*/
#include <bits/stdc++.h>
using namespace std;
int t=1,n=100000;

int main(){
	cout<<t<<endl;
	srand(time(NULL));
	cout<<n<<endl;
	for(int i=0;i<n;i++){
		cout<<rand()%20001-10000<<" "<<rand()%20001-10000<<endl;
	}
}