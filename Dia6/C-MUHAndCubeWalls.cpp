#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> P;
vector<int> T;
vector<int> b;
void kmpPreproceess(){
  int i=0,j=-1;b[0]=-1;
  while(i<m){
    while(j>=0 && P[i]!=P[j]) j=b[j];
    i++;j++;
    b[i]=j;
  }
}

int kmpSearch(){
  int i=1,j=0;
  char x;
  int cont=0;
  while(i<n){
    while(j>=0 && T[i]!=P[j]) j=b[j];
    i++;j++;
    if(j==m){
      cont++;
      j=b[j];
    }
  }
  return cont;
}

int main(){
	
  scanf("%d",&n);
  scanf("%d",&m);
  T.resize(n);
  int aux;
  scanf("%d",&aux);
  for(int i=1;i<n;i++){
    int x;
    scanf("%d",&x);
    T[i]=aux-x;
    aux=x;

  }
  scanf("%d",&aux);
  P.resize(m+10);
  b.resize(m+10);
  for(int i=0;i<m-1;i++){
    int x;
    scanf("%d",&x);
    P[i]=aux-x;
    aux=x;
  }
  m--;
  if(m==0) printf("%d\n",n);
  else{
    kmpPreproceess();
    printf("%d\n",kmpSearch());
  }

  return 0;
}
