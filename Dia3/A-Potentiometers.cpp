#include <bits/stdc++.h>
#define LSOne(S) (S & (-S))

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;

class FenwickTree{

private:
  vi ft;
public:
  FenwickTree(){}
  FenwickTree(ll n) {ft.assign(n+1,0);}
  ll rsq(ll b) { ll sum = 0; for(;b;b-=LSOne(b)) sum += ft[b]; return sum;}
  ll rsq(ll a, ll b) { return rsq(b) - (a==1 ? 0 : rsq(a-1));}
  void adjust(ll k, ll v){ for(;k<(ll) ft.size(); k += LSOne(k)) ft[k] +=v;}
};

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  int caso = 1;
  bool flag= false;
  while(1){
    cin>>N;
    if(N==0) return 0;
    
    if(!flag) flag = true;
    else cout<<"\n";
    cout<<"Case "<<caso++<<":"<<"\n";
    FenwickTree ft(N);
    for(int i=1;i<=N;i++){
      int aux;
      cin>>aux;
      ft.adjust(i,aux);
    }
    while(1){
      string str;
      int x,y;
      cin>>str;
      
      if(str[0]!='E') cin>>x>>y;
      if(str[0]=='S'){
	ft.adjust(x,-ft.rsq(x,x));
	ft.adjust(x,y);
      }
      else if (str[0]=='M'){
	cout<<ft.rsq(x,y)<<"\n";
      }
      else if (str[0]=='E'){
	break;
      }
    }
  }
  return 0;
} 
  
