#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a,b,c,x,y,d;

void extendedEuclid(ll n,ll m){
  ll r0 = n, r1 = m;
  ll s0 = 1, s1 = 0;
  ll t0 = 0, t1 = 1;

  while(r1!=0){
    ll q = r0/r1;
    ll r = r0 - q*r1; r0 = r1; r1 = r;
    ll s = s0 - q*s1; s0 = s1; s1 = s;
    ll t = t0 - q*t1; t0 = t1; t1 = t;
  }
  d = r0;
  x = s0;
  y = t0; 
}

int main(){

 
  while(1){
    scanf("%lld %lld %lld",&a,&b,&c);
    if(a==0 && b==0 & c==0) break;
   
    extendedEuclid(a,b);
    if(c%d!=0) puts("Unquibable!");
    else{
      a/=d;
      b/=d;
      c/=d;

      //(x*c)%b = ((x%b)*(c%b)) % b
      x = (((x%b)*(c%b)%b) + b)%b; //inverso modular
      y = (c-a*x)/b;

      if(y<0) puts("Unquibable!");
      else{
	if(x==1) printf("%lld foom and ",x);
	else printf("%lld fooms and ",x);
	if(y==1) printf("%lld foob for a twob!\n",y);
	else printf("%lld foobs for a twob!\n",y);
      }
    }
  }
  return 0;
}
