#include <bits/stdc++.h>
#define inf 0x7fffffff
using namespace std;


typedef long long ll;
typedef vector<ll> vi;

class SegmentTree{
private: 
  vi arr, tree, lazy;
  ll n;
  void build_tree(long long int  node, long long int  a, long long int  b) {
    if(a > b) return;    
    if(a == b) {
      tree[node] = 0; 
      return;
    }
    build_tree(node*2, a, (a+b)/2); 
    build_tree(node*2+1, 1+(a+b)/2, b);  
    //tree[node] = min(tree[node*2], tree[node*2+1]);
    tree[node] = tree[node*2] | tree[node*2+1];
  }

  void update_tree(long long int  node, long long int  a, long long int  b, long long int  i, long long int  j, long long int  value) {
    if(lazy[node] != 0) { 
      tree[node] |= lazy[node]; 
      if(a != b) {
	lazy[node*2] |= lazy[node]; 
	lazy[node*2+1] |= lazy[node];
      }
      lazy[node] = 0;
    }
  
    if(a > b || a > j || b < i) return;    
    if(a >= i && b <= j) { 
      tree[node] |= value;
      if(a != b) { 
	lazy[node*2] |= value;
	lazy[node*2+1] |= value;
      }
      return;
    }
    update_tree(node*2, a, (a+b)/2, i, j, value); 
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);
    tree[node] = tree[node*2] | tree[node*2+1]; 
  }

  long long int  query_tree(long long int  node, long long int  a, long long int  b, long long int  i, long long int  j) {
    if(a > b || a > j || b < i) return 0;
    if(lazy[node] != 0) { 
      tree[node] |= lazy[node]; 
      if(a != b) {
	lazy[node*2] |= lazy[node];
	lazy[node*2+1] |= lazy[node];
      }
      lazy[node] = 0; 
    }

    if(a >= i && b <= j) return tree[node];
    long long int  q1 = query_tree(node*2, a, (a+b)/2, i, j);
    long long int  q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); 
    long long int  res = q1 | q2;  
    return res;
  }

public:
  SegmentTree(const vi&_A){
    arr = _A;
    n = arr.size();
    tree.assign(4*n,0);
    lazy.assign(4*n,0);
    build_tree(1,0,n-1);  		
  }

  ll rmq(ll i, ll j){ return query_tree(1,0,n-1,i,j);}
  void update(ll i, ll j, ll val){update_tree(1,0,n-1,i,j,val);}
};


class SegmentTree2{
private: 
  vi arr, tree, lazy;
  ll n;
  void build_tree(long long int  node, long long int  a, long long int  b) {
    if(a > b) return;    
    if(a == b) {
      tree[node] = arr[a]; 
      return;
    }
    build_tree(node*2, a, (a+b)/2); 
    build_tree(node*2+1, 1+(a+b)/2, b);  
    //tree[node] = min(tree[node*2], tree[node*2+1]);
    tree[node] = tree[node*2] & tree[node*2+1];
  }

  void update_tree(long long int  node, long long int  a, long long int  b, long long int  i, long long int  j, long long int  value) {
    if(lazy[node] != -1) { 
      tree[node] & lazy[node]; 
      if(a != b) {
	lazy[node*2] & lazy[node]; 
	lazy[node*2+1] & lazy[node];
      }
      lazy[node] = -1;
    }
  
    if(a > b || a > j || b < i) return;    
    if(a >= i && b <= j) { 
      tree[node] & value;
      if(a != b) { 
	lazy[node*2] & value;
	lazy[node*2+1] & value;
      }
      return;
    }
    update_tree(node*2, a, (a+b)/2, i, j, value); 
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);
    tree[node] = tree[node*2] & tree[node*2+1]; 
  }

  long long int  query_tree(long long int  node, long long int  a, long long int  b, long long int  i, long long int  j) {
    if(a > b || a > j || b < i) return -1;
    if(lazy[node] != -1) { 
      tree[node] & lazy[node]; 
      if(a != b) {
	lazy[node*2] & lazy[node];
	lazy[node*2+1] & lazy[node];
      }
      lazy[node] = -1; 
    }

    if(a >= i && b <= j) return tree[node];
    long long int  q1 = query_tree(node*2, a, (a+b)/2, i, j);
    long long int  q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); 
    long long int  res = q1 & q2;  
    return res;
  }

public:
  SegmentTree2(const vi&_A){
    arr = _A;
    n = arr.size();
    tree.assign(4*n,0);
    lazy.assign(4*n,-1);
    build_tree(1,0,n-1);  		
  }

  ll rmq(ll i, ll j){ return query_tree(1,0,n-1,i,j);}
  void update(ll i, ll j, ll val){update_tree(1,0,n-1,i,j,val);}
};



int main(){

  int n,m;
  scanf("%d %d",&n,&m);
  vector<ll> arr(n+1,(1<<30) -1);
  vector<pair<pair<ll,ll>,ll> > q(m);
  SegmentTree ST1(arr);
  for(int i=0;i<m;i++){
    ll a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    ST1.update(a,b,c);
    q[i]=make_pair(make_pair(a,b),c);
  }
  for(int i=1;i<=n;i++){
    arr[i]=ST1.rmq(i,i);
  }
  SegmentTree2 ST2(arr);
  for(int i=0;i<m;i++){
    if(ST2.rmq(q[i].first.first,q[i].first.second)!=q[i].second){
      printf("NO\n");
      return 0;
    }
  }

  printf("YES\n");
  for(int i=1;i<=n;i++)
    printf("%d ",arr[i]);
  puts("");

  return 0;
}
