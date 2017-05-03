#include <vector>
#include <string>
using namespace std;
vector<long long> digits(long long n){
	vector<long long> d;
	long long mod=10;
	while(mod<=n)mod*=10;
	while(mod>1){ 
		d.push_back((n%mod-n%(mod/10))/(mod/10));
		mod/=10;
	}
	return d;
}
vector<int> digits(string s){
	vector<int>d;
	for(int i=0;i<s.length();i++)d.push_back(s[i]-'0');
	return d;
}
int sumDigits(long long n){
	int ctr=0;
	long long mod=10;
	while(mod<=n)mod*=10;
	while(mod>1){ 
		ctr+=(n%mod-n%(mod/10))/(mod/10);
		mod/=10;
	}
	return ctr;
}
int sumDigits(string s){
	int ctr=0;
	for(int i=0;i<s.length();i++)ctr+=(s[i]-'0');
	return ctr;
}
int main(){
  return 0;
}
