#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef vector<ll> vi;

ll gcd(ll a, ll b){ return b==0 ?  a : gcd(b,a%b);}
class SegmentTree{
private: 
  vi tree, lazy;
  ll n;
  void build_tree(int node, int a, int b) {
    if(a > b) return;    
    if(a == b) {
      tree[node] = 0; 
      return;
    }
    build_tree(node*2, a, (a+b)/2); 
    build_tree(node*2+1, 1+(a+b)/2, b);  
    tree[node] = gcd(tree[node*2], tree[node*2+1]); 
  }

  void update_tree(int node, int a, int b, int i, int j, int value) {
    if(lazy[node] != 0) { 
      tree[node] += lazy[node]; 
      if(a != b) {
	lazy[node*2] += lazy[node]; 
	lazy[node*2+1] += lazy[node];
      }
      lazy[node] = 0;
    }
  
    if(a > b || a > j || b < i) return;    
    if(a >= i && b <= j) { 
      tree[node] = value;
      if(a != b) { 
	lazy[node*2] = value;
	lazy[node*2+1] = value;
      }
      return;
    }
    update_tree(node*2, a, (a+b)/2, i, j, value); 
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);
    tree[node] = gcd(tree[node*2], tree[node*2+1]); 
  }

  int query_tree(int node, int a, int b, int i, int j) {
    if(a > b || a > j || b < i) return 0;
    if(lazy[node] != 0) { 
      tree[node] = lazy[node]; 
      if(a != b) {
	lazy[node*2] = lazy[node];
	lazy[node*2+1] = lazy[node];
      }
      lazy[node] = 0; 
    }

    if(a >= i && b <= j) return tree[node];
    int q1 = query_tree(node*2, a, (a+b)/2, i, j);
    int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); 
    int res = gcd(q1, q2);  
    return res;
  }

public:
  SegmentTree(int N){
    n = N;
    tree.assign(4*n,0);
    lazy.assign(4*n,0);
    build_tree(1,0,n-1);  		
  }

  ll rmq(ll i, ll j){ return query_tree(1,0,n-1,i,j);}
  void update(ll i, ll j, ll val){update_tree(1,0,n-1,i,j,val);}
};

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin>>N;
  int index = 0;
  
  SegmentTree st(N);
  unordered_map<int,stack<ll>> mp;
  string str;
  ll aux;
  
  for(int i=0;i<N;i++){
    cin>>str;
    cin>>aux;
    if(str[0]=='+'){
      st.update(index,index,aux);
      mp[aux].push(index);
      index++;
      ll res = st.rmq(0,N-1);
      if(res!=0)cout<<res<<"\n";
      else cout<<"1\n";
    }
    else{
      int indice = mp[aux].top();
      mp[aux].pop();
      st.update(indice,indice,0);
      ll res = st.rmq(0,N-1);
      if(res!=0)cout<<res<<"\n";
      else cout<<"1\n";
    }
  }
  return 0;
}
