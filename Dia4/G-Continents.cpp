#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m;
  while(cin>>m>>n){
    vector<vector<char> > ma(m,vector<char>(n));
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++){
	cin>>ma[i][j];
      }
    int x,y;
    cin >> x >> y;
    char l=ma[x][y];
    int contador=0;
    vector<int> cont;
    vector<vector<int> > rev(m,vector<int>(n,-1));
    vector<pair<int,int> > vec(4);
    vec[0] = make_pair(0,1);
    vec[1] = make_pair(0,-1);
    vec[2] = make_pair(1,0);
    vec[3] = make_pair(-1,0);

    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
	if(ma[i][j]==l && rev[i][j]==-1){
	  queue<pair<int,int> > cola;
	  cola.push(make_pair(i,j));
	  rev[i][j]=contador;
	  cont.push_back(1);
	  while(!cola.empty()){
	    pair<int,int> top=cola.front();
	    cola.pop();
	    for(int k=0;k<4;k++){
	      int f = top.first+vec[k].first;
	      int c = top.second+vec[k].second;
	      if(f < 0 || f==m) continue;
	      if(c < 0) c+=n;
	      else if(c==n) c =0;
	      if(ma[f][c]==l && rev[f][c]==-1){
		cont[cont.size()-1]++;
		rev[f][c]=contador;
		cola.push(make_pair(f,c));
	      }
	    }

	  }
	  contador++;
	}
      }
    }
		

		
    int no=rev[x][y];
    int MAX = 0;
    for(int i=0;i<cont.size();i++){
      if(i==no) continue;
      MAX = max(MAX,cont[i]);
    }
    cout << MAX << endl;
  }

  return 0;
}
