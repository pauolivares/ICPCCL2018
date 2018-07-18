#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj;
vector<int> ts,dfs_num;
bool dfs(int u){
  dfs_num[u]=1;
  for(int j=0;j<adj[u].size();j++){
    if(dfs_num[adj[u][j]]==1){
      return false;
    }
    if(dfs_num[adj[u][j]]==0){
      if(!dfs(adj[u][j])){
	return false;
      }
    }
		
  }
  dfs_num[u]=2;
  ts.push_back(u);
  return true;
}
int main(){

  int n;
  cin >> n;
  dfs_num.resize(26,0);
  vector<string> p(n);
  for(int i=0;i<n;i++){
    cin >> p[i];
  }
  adj.resize(26);
  for(int i=0;i<n-1;i++){
    for(int k=i+1;k<n;k++){
      bool wea = false;
      for(int j=0;j<min(p[i].size(),p[k].size());j++){
	if(p[i][j]!=p[k][j]){
	  wea = true;
	  adj[p[i][j]-'a'].push_back(p[k][j]-'a');
	  break;
	}
      }
      if(!wea && p[i].size()>p[k].size()){
	cout<<"Impossible"<<endl;
	return 0;
      }
    }
		
  }
	
  for(int i=25;i>=0;i--)
    if(dfs_num[i]==0)
      if(!dfs(i)){
	cout<<"Impossible"<<endl;
	return 0;
      }
  for(int i=ts.size()-1;i>=0;i--){
    cout<<(char)(ts[i]+'a');
  }
  cout<<endl;
  return 0;
}
