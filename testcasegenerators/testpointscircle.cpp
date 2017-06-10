/*
	Circle
*/
#include <bits/stdc++.h>
#define M_PIl 3.141592653589793238462643383279502884L
using namespace std;
int t=1,n=100000;

int main(){
	cout<<t<<endl;
	srand(time(NULL));
	cout<<n<<endl;
	for(int i=0;i<n;i++){
		int x=int(10000.0*cos(double(i)/double(n/2)*M_PIl));
		int y=int(10000.0*sin(double(i)/double(n/2)*M_PIl));
		cout<<x<<" "<<y<<endl;
	}
}
