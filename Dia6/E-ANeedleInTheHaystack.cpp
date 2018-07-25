#include <bits/stdc++.h>
using namespace std;
int n,m;
char *P;
vector<int> b;
void kmpPreproceess(){
  int i=0,j=-1;b[0]=-1;
  while(i<m){
    while(j>=0 && P[i]!=P[j]) j=b[j];
    i++;j++;
    b[i]=j;
  }
}

void kmpSearch(){
  int i=0,j=0;
  char x;
  scanf("%c",&x);
  while(x!='\n'){
    while(j>=0 && x!=P[j]) j=b[j];
    i++;j++;
    scanf("%c",&x);
    if(j==m){
      printf("%d\n",i-j);
      j=b[j];
    }
  }
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  bool caca=false;
  while(scanf("%d",&n)==1){

    getchar();
    if(!caca) caca=true;
    else printf("\n");
    P=(char*)malloc((n+10)*sizeof(char));
    b.resize(n+10);
    m=n;
    scanf("%[^\n]",P);
    getchar();
    kmpPreproceess();
    kmpSearch();
  }

  return 0;
}
