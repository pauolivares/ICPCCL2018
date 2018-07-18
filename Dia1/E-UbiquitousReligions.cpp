#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
vector<bool> visited;

void dfs(int nodo){
  visited[nodo]=true;
  for(int i=0;i<g[nodo].size();i++){
    int next = g[nodo][i];
    if(!visited[next]){
      dfs(next);
    }
  }
}

int main(int argc, char const *argv[]){
  int n,m;
  int caso = 0;
  while(1){
    caso++;
    scanf("%d %d",&n,&m);
    if(n==0 && m==0){
      break;
    }
    g.assign(n,vector<int>());
    visited.assign(n,false);
    int u,v;
    for(int i=0;i<m;i++){
      scanf("%d %d",&u,&v);
      u--,v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int weas = 0;
    for(int i=0;i<n;i++){
      if(!visited[i]){
	dfs(i);
	weas++;
      }
    }
    printf("Case %d: %d\n",caso,weas );
  }
	
  return 0;
}
