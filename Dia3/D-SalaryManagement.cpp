#include <bits/stdc++.h>
#define inf 0x7fffffff
#define LSOne(S) (S & (-S))

using namespace std;

typedef vector<long long int > vi;
long long int  N,q;
vector <long long int > sueldos;
vector < long long int > total;
vector < vector <long long int > > adj;
vector <long long int > pre_order;
vector <long long int > cantidad;
vector <long long int > indices;
vector <long long int > arr;
vector <long long int > tree;
vector <long long int > lazy;

class FenwickTree {
private:
  vi ft;
public:
  FenwickTree() {}
  FenwickTree(long long int  n) { ft.assign(n + 1, 0); }
  long long int  rsq( long long int  b){  long long int  sum = 0; for (; b; b -= LSOne(b)) sum += ft[b]; return sum; }
  long long int  rsq( long long int   a, long long int  b){ return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }
  void adjust(long long int  k,long long int  v){ for (; k < (long long int )ft.size(); k += LSOne(k)) ft[k] += v; }
};

void build_tree(long long int  node, long long int  a, long long int  b) {
  if(a > b) return;    
  if(a == b) {
    tree[node] = arr[a]; 
    return;
  }
  build_tree(node*2, a, (a+b)/2); 
  build_tree(node*2+1, 1+(a+b)/2, b);  
  tree[node] = min(tree[node*2], tree[node*2+1]); 
}

void update_tree(long long int  node, long long int  a, long long int  b, long long int  i, long long int  j, long long int  value) {
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
    tree[node] += value;
    if(a != b) { 
      lazy[node*2] += value;
      lazy[node*2+1] += value;
    }
    return;
  }
  update_tree(node*2, a, (a+b)/2, i, j, value); 
  update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);
  tree[node] = min(tree[node*2], tree[node*2+1]); 
}

long long int  query_tree(long long int  node, long long int  a, long long int  b, long long int  i, long long int  j) {
  if(a > b || a > j || b < i) return inf;
  if(lazy[node] != 0) { 
    tree[node] += lazy[node]; 
    if(a != b) {
      lazy[node*2] += lazy[node];
      lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0; 
  }

  if(a >= i && b <= j) return tree[node];
  long long int  q1 = query_tree(node*2, a, (a+b)/2, i, j);
  long long int  q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); 
  long long int  res = min(q1, q2);  
  return res;
}

void suma_dfs(long long int  monto, long long int  nodo){
  long long int  i,l;
  sueldos[nodo]+=monto;
  l=adj[nodo].size();
  for(i=0;i<l;i++){
    suma_dfs(monto,adj[nodo][i]);
  }
}

void hijos_dfs(long long int  nodo){
  long long int  i,l;
  pre_order.push_back(nodo);
  l=adj[nodo].size();
  for(i=0;i<l;i++){
    hijos_dfs(adj[nodo][i]);
  }
}

long long int  dp_hijos( long long int  nodo ){
  long long int  i,l,count;
  if(cantidad[nodo]!=-1) return cantidad[nodo];
  count=1;
  l=adj[nodo].size();
  for(i=0;i<l;i++){
    count+= dp_hijos(adj[nodo][i]);
  }
  cantidad[nodo]=count;
  return count;
}

long long int  dp_sl( long long int  nodo ){
  long long int  i,l,count;
  if(total[nodo]!=-1) return total[nodo];

  count=sueldos[nodo];
  l=adj[nodo].size();
  for(i=0;i<l;i++){
    count+=dp_sl(adj[nodo][i]);
  }
  total[nodo]=count;
  return count;
}

int  main(){
  long long int  T;
  long long int  i,j,x,id,p,k;
  long long int  mm;  
  scanf("%lld",&T);
  for(i=0;i<T;i++){
    printf("Case %d:\n",i+1);

    tree.clear();
    sueldos.clear();
    adj.clear();
    arr.clear();
    lazy.clear();
    total.clear();
    pre_order.clear();
    cantidad.clear();
    indices.clear();
    
    scanf("%lld %lld",&N,&q);
    sueldos.resize(N+5);
    adj.resize(N+5);
    total.resize(N+5,-1);
    indices.resize(N+5);
    cantidad.resize(N+5,-1);
    arr.resize(N+5);
    lazy.resize(20*N,0);
    tree.resize(20*N);
    sueldos[0]=0;
    for(j=1;j<=N;j++){
      scanf("%lld %lld",&p,&sueldos[j]);
      adj[p].push_back(j);
    }

    pre_order.push_back(-1);
    hijos_dfs(1);
    dp_hijos(1);
    dp_sl(1);
    for(j=1;j<=N;j++){
      indices[pre_order[j]]=j;
    }
    arr[0]=0;
    for(j=1;j<=N;j++){
      arr[j]=sueldos[pre_order[j]];
    }

    FenwickTree ft(N+5);	 
    FenwickTree ft2(N+5);
    for(long long int  v=1;v<=N;v++){
      long long int  a=v;
      long long int  b=v;
      long long int  c=arr[v];
      ft.adjust(a,c);
      ft.adjust(b+1,-c);
      ft2.adjust(a,c*(a-1));
      ft2.adjust(b+1,-c*b);      
    }

    build_tree(1, 0, N+2);
 
    x=0;
    for(j=0;j<q;j++){
      scanf("%lld %lld",&p,&id);
      if(p==1){
	if(x) sueldos[0]=dp_sl(0);
        mm=0;
	long long int  a = indices[id];
	long long int  b = indices[id] + cantidad[id]-1;	
	long long int  chapaculiao = ft.rsq(b)*b - ft2.rsq(b) - ft.rsq(a-1)*(a-1) + ft2.rsq(a-1); 
	cout<<chapaculiao<<endl;
      }
      else{
	long long int  a = indices[id];
	long long int  b = indices[id] + cantidad[id]-1;
	
	mm=query_tree(1, 0,N+2, a, b);
	
	if(mm>1000) mm=1000;
	update_tree(1, 0, N+2, a, b, mm);

	ft.adjust(a,mm);
        ft.adjust(b+1,-mm);
        ft2.adjust(a,mm*(a-1));
        ft2.adjust(b+1,-mm*b);   
	mm=query_tree(1, 0,N, a,b);
	x=1;
      }
    }
  }  
  return 0;
}
