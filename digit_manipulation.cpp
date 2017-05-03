#include <vector>
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
int main(){
  return 0;
}
