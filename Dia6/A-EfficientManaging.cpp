#include <bits/stdc++.h>

using namespace std;

string tobin(int aux){
  string s = "";
  for(int i=0;i<32;i++){
    if(aux&1){
      s+="1";
    }else{
      s+="0";
    }
    aux>>=1;
  }
  reverse(s.begin(), s.end());
  return s;
}

const int ALPHABET_SIZE = 2;

struct TrieNode{
  struct TrieNode *children[ALPHABET_SIZE];
  int p;
};

struct TrieNode *getNode(){
  struct TrieNode *pNode = new TrieNode;
  pNode->p = 0;
  for(int i=0;i<ALPHABET_SIZE;i++){
    pNode->children[i] = NULL;
  }
  return pNode;
}

int dfs( TrieNode *tn,string busco){
  int pille = 0;
  for(int i=0;i<32;i++){
    int intento = busco[i]-'0';
    if(tn->children[intento]==NULL){
      intento = !intento;
    }
		
    pille*=2;
    pille+=(intento);
    tn=tn->children[intento];
  }
  return pille;
}

void insert (struct TrieNode *root,string key){
  struct TrieNode *pCrawl = root;
  for(int i=0;i<key.length();i++){
    int index = key[i]-'0';
    if(!pCrawl->children[index])
      pCrawl->children[index] = getNode();
    pCrawl->p++;
    pCrawl = pCrawl->children[index];
  }
  pCrawl->p++;
}
vector<vector<pair<int,int> > > g;
vector<bool> vis;
vector<int> c;
void ddfs(int nodo,int chor){
  vis[nodo]=true;
  c[nodo]=chor;
  for(int i=0;i<g[nodo].size();i++){
    int v = g[nodo][i].first;
    int wea = g[nodo][i].second;
    if(!vis[v]){
      ddfs(v,chor^wea);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  int n;
  while(cin>>n){
    struct TrieNode *head=getNode();
    g.assign(n,vector<pair<int,int> >());
    c.assign(n,0);
    vis.assign(n,false);
    for(int i=0;i<n-1;i++){
      int a,b,c;
      cin>>a>>b>>c;
      a--;b--;
      g[a].push_back(make_pair(b,c));
      g[b].push_back(make_pair(a,c));
    }
    ddfs(0,0);
    for(int i=0;i<n;i++){
      insert(head,tobin(c[i]));
    }
    for(int i=0;i<n;i++){
      int coso = dfs(head,tobin(~c[i]));
      cout<<(coso^c[i])<<endl;
    }
		
  }
	
  return 0;
}
