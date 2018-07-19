#include <bits/stdc++.h>

using namespace std;

vector<bool> DFS(vector<vector<int> > &graph,int s, int omitir){
  vector<bool> visited(graph.size(), false);
  stack<int> stack;
  stack.push(s);  
  while (!stack.empty()){
    s = stack.top();
    stack.pop();
    if (!visited[s]) visited[s] = true;
    
    for (auto i = graph[s].begin(); i != graph[s].end(); ++i)
      if (!visited[*i])
	if(*i!=omitir) stack.push(*i);
  }
  return visited;
}

int main(){

  int T,N;
  cin>>T;
  for(int X = 1; X<=T;X++){
    cin>>N;    
    vector<vector<int> > g;
    g.resize(N);
    int aux;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	cin>>aux;
	if(aux==1) g[i].push_back(j); 
      }
    }
    vector<bool> inicial = DFS(g,0,-1);

    printf("Case %d:\n",X);
    printf("+");
    for(int i=0;i<2*inicial.size()-1;i++) printf("-");
    puts("+");
    for(int i=0;i<inicial.size();i++){
      if(inicial[i]==true) cout<<"|Y";
      else cout<<"|N";
    }
    puts("|");
    

    printf("+");
    for(int i=0;i<2*inicial.size()-1;i++) printf("-");
    puts("+");
    
    for(int i = 1; i<N;i++){
      vector<bool> res = DFS(g,0,i);
      for(int j=0;j<res.size();j++){
	if(inicial[j]==res[j]) cout<<"|N";
	else cout<<"|Y";
      }
      puts("|");
      
      printf("+");
      for(int i=0;i<2*inicial.size()-1;i++) printf("-");
      puts("+");  
    }
  }
  return 0;
}
