#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){

  int t;
  scanf("%d",&t);
  for(int casos=1;casos<=t;casos++){
    ll n;
    scanf("%lld",&n);
    vector<ll> m(n);
    ll wea=1;

    ll mod = 1e8+7;
    scanf("%lld",&m[0]);
    for(int i=1;i<n;i++){
      ll a;
      scanf("%lld",&a);
      m[i]=a;
      wea*=2;
      wea%=mod;
    }
    ll resp = 0;
    for(int i=0;i<n;i++){
      resp+=m[i]*wea;
      resp%=mod;
    }
    printf("Case %d: %lld\n",casos,resp);

  }




  return 0;
}
