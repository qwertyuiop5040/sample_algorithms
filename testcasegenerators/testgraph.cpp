/*
  n=|V|, m=|E|, edit c function for better graphs 
*/
#include <iostream>
#include <time.h>
using namespace std;
int n=5000;
int m=30000;
int main(){
	cout<<n<<" "<<m<<"\n";
	srand(time(NULL));
	for(int i=0;i<m;i++){
		int a=1+rand()%n;
		int b=1+rand()%n;
		int c=rand()%2000000000+1000000000;
		cout<<a<<" "<<b<<" "<<c<<"\n";
	}
	return 0;
}
