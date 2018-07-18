#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj;
vector<int> ts,dfs_num;
void dfs(int u){
  dfs_num[u]=1;
  for(int j=0;j<adj[u].size();j++){
    if(dfs_num[adj[u][j]]!=1)
      dfs(adj[u][j]);
  }
}
bool dfs2(int u){
  dfs_num[u]=2;
  for(int j=0;j<adj[u].size();j++){
    if(dfs_num[adj[u][j]]==0)
      dfs2(adj[u][j]);
  }
  ts.push_back(u);
}
int main(){

  int n,m,s;
  scanf("%d %d %d",&n,&m,&s);
  adj.resize(n+1);
  dfs_num.resize(n+1,0);
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    adj[a].push_back(b);
  }
  dfs(s);
  for(int i=1;i<n+1;i++){
    if(dfs_num[i]==0)
      dfs2(i);
  }
  int r=0;
  for(int i=ts.size()-1;i>=0;i--){
    if(dfs_num[ts[i]]!=1){
      r++;
      dfs(ts[i]);
    }
  }
  printf("%d\n",r);
  return 0;
}
