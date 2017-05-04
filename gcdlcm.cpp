int gcd(int i,int j){
  int k;
  while(i!=0){
     k=i;
     i=j%i;
     j=k;
  }
  return j;
}
int lcm(int i,int j){return i/gcd(i,j)*j;}
