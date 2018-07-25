#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
vector<bool> vis;

void dfs(int node){
  vis[node]=true;
  for(int i=0;i<g[node].size();i++){
    if(!vis[g[node][i]]){
      dfs(g[node][i]);
    }
  }
}

int main(){
  int n,m;
  ios::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  g.assign(n,vector<int>());
  vector<int> conoce(n,0);
  vector<vector<bool> > w(n,vector<bool>(m,false));
  for(int i=0;i<n;i++){
    int z;
    cin>>z;
    conoce[i]=z;
    for(int j=0;j<z;j++){
      int aux;
      cin>>aux;
      w[i][aux-1]=true;	
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(j==i) continue;
      for(int k=0;k<m;k++){
	if(w[i][k] && w[j][k]){
	  g[i].push_back(j);
	  g[j].push_back(i);
	}
      }
    }
  }
  vis.assign(n,false);
  int solos =0;
  int componentes = 0;
  for(int i=0;i<n;i++){
    if(conoce[i]==0){
      solos++;
      continue;
    }
    if(!vis[i]){
      dfs(i);
      componentes++;;
    }
  }
  int total = solos+componentes;
  if(componentes!=0) total--;
  cout<<total<<endl;
  return 0;
}
