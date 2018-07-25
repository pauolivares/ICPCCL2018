#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){ return b==0 ? a : gcd(b,a%b);}
int lcm(int a,int b){ return a*(b/gcd(a,b));}

int main(){

  int x,y,a,b;
  cin>>x>>y>>a>>b;
  int MCM = lcm(x,y);
  cout<<(b/MCM)-((a-1)/MCM)<<endl;

  return 0;
}
