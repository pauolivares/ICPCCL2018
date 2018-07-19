#include <bits/stdc++.h>

using namespace std;


vector<vector<pair<long long,long long> > > graph;
vector<long long> p;
void printPath(long long u){
  if (u==0){
    printf("1");
    return;
  }
  printPath(p[u]);
  printf(" %lld",u+1);
}
void dijkstra(long long s,vector<long long> &dist){
  dist[s]=0;
  priority_queue<pair<long long,long long>, vector<pair<long long,long long> >, greater<pair<long long,long long> > > pq;
  pq.push(make_pair(0,s));
  p.resize(graph.size(),-1);
  while(!pq.empty()){
    pair<long long,long long> front = pq.top();
    pq.pop();
    long long d = front.first, u = front.second;
    if(d> dist[u]) continue;
    
    for(auto it = graph[u].begin(); it!=graph[u].end();++it){
      pair<long long,long long> v = make_pair(it->first,it->second);
      if(dist[u] + v.second < dist[v.first]){
	dist[v.first] = dist[u] + v.second;
	p[v.first] = u;
	pq.push(make_pair(dist[v.first], v.first));
      }
    }
  }
  if(p[graph.size()-1]==-1) puts("-1");
  else 
    printPath(graph.size()-1), puts("");
}
int main(){

  long long V,E;
  cin>>V>>E;
  graph.resize(V);
  vector<long long> dist(graph.size(),1000000000000000000LL);

  for(long long i=0;i<E;i++){
    long long n,m,w;
    cin>>n>>m>>w;
    n--;
    m--;
    graph[n].push_back(make_pair(m,w));
    graph[m].push_back(make_pair(n,w));    
  }

  dijkstra(0,dist);
 
  return 0;

}
