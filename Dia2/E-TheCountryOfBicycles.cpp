#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct UnionFind{
  vector<int> p,rank;
  UnionFind(int N){
    rank.assign(N,0);
    p.assign(N,0);
    for(int i=0;i<N;i++)
      p[i]=i;

  }
  int findSet(int i){return (p[i]==i)? i:(p[i]=findSet(p[i]));}
  bool isSameSet(int i, int j){return findSet(i)==findSet(j);}
  void unionSet(int i, int j){
    if(!isSameSet(i,j)){
      int x = findSet(i),y=findSet(j);
      if(rank[x]>rank[y]) p[y]=x;
      else{
	p[x]=y;
	if(rank[x]==rank[y]) rank[y]++;
      }
    }
  }
};

ll dfs(vector<bool> &rev,vector<vector<pair<int,ll> > > &graph, int s, int d){
  if(s==d) return LLONG_MIN+1;
  ll MAX=LLONG_MIN+1;
	
  for(int i=0;i<graph[s].size();i++){
    if(!rev[graph[s][i].first]){
      rev[graph[s][i].first]=true;
      MAX=dfs(rev,graph,graph[s][i].first,d);
      if(MAX!=LLONG_MIN)
	return max(MAX,graph[s][i].second);
    }
  }
  return LLONG_MIN;
}

int main(){
  int n,m;
  int h=1;
  while(scanf("%d %d",&n,&m)==2){
    if(n==0 && m==0) break;
    vector<pair<ll,pair<int,int> > > EdgeList(m);
    for(int i=0;i<m;i++){
      int u,v;
      ll w;
      scanf("%d %d %lld",&u,&v,&w);
      u--,v--;
      EdgeList[i]=make_pair(w,make_pair(u,v));
    }
    sort(EdgeList.begin(),EdgeList.end());
    UnionFind UF(n);
    vector<vector<pair<int,ll> > > graph(n);
    for(int i=0;i<m;i++){
      pair<ll,pair<int,int> >front = EdgeList[i];
      if(!UF.isSameSet(front.second.first,front.second.second)){
	//printf("%d\n",front.first);
	UF.unionSet(front.second.first,front.second.second);
	graph[front.second.second].push_back(make_pair(front.second.first,front.first));
	graph[front.second.first].push_back(make_pair(front.second.second,front.first));
      }
    }

    int k;
    scanf("%d",&k);
    printf("Instancia %d\n",h++);
    while(k--){
      vector<bool> rev(graph.size(),false);
      int s,d;
			
      scanf("%d %d",&s,&d);
      s--,d--;
      if(s==d) printf("0\n");
      else 
	printf("%lld\n",dfs(rev,graph,s,d));
    }
    printf("\n");
  }


  return 0;
}
