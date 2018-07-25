#include <bits/stdc++.h>

using namespace std;


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

int dfs( TrieNode *tn,int car){
  //cout<<car<<" "<<tn->p<<endl;
  int cont =tn->p*car;
	
  for(int i=0;i<ALPHABET_SIZE;i++){
    if(tn->children[i]!=NULL){
      cont=max(cont,dfs(tn->children[i],car+1));
    }
  }
  return cont;
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

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    struct TrieNode *head=getNode();
    for(int i=0;i<n;i++){
      string s;
      cin >> s;
      insert(head,s);
    }
    cout<<dfs(head,0)<<endl;
  }
  return 0;
}
