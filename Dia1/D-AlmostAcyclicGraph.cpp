#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
vector<int> visited;
vector<int> camino;
stack<int> st;

bool ciclo = false;
int U,V;
bool dfs(int nodo){
  visited[nodo]=1;
  for(int i=0;i<g[nodo].size();i++){
    int vecino = g[nodo][i];
    if(nodo==U && vecino==V){
      continue;
    }
    if(visited[vecino]==0){
      if(dfs(vecino)){
	st.push(vecino);
	return true;
      }
    }else if(visited[vecino]==1){
      ciclo = true;
      st.push(vecino);
      return true;	
    }
  }
  visited[nodo]=2;
  return false;
}

int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  g.assign(n,vector<int>());
  U=V=-100;
  for(int i=0;i<m;i++){
    int u,v;
    scanf("%d %d",&u,&v);
    u--;v--;
    g[u].push_back(v);
  }
  visited.assign(n,0);
  for(int i=0;i<n &&!ciclo;i++){
    if(!visited[i]){
      dfs(i);
    }
  }
  if(!ciclo){
    puts("YES");
    return 0;
  }else{
    while(!st.empty()){
      camino.push_back(st.top());
      st.pop();
    }
    camino.push_back(camino[0]);
		
    for(int i=0;i<camino.size()-1;i++){
      U=camino[i];
      V=camino[i+1];
      ciclo = false;
      visited.assign(n,0);
      for(int j=0;j<n &&!ciclo;j++){
	if(!visited[j]){
	  dfs(j);
	}
      }
      if(!ciclo){
	puts("YES");
	return 0;
      }
    }
  }
  puts("NO");
  return 0;
}
