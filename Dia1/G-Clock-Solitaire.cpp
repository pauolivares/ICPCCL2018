#include <bits/stdc++.h>
using namespace std;

bool solve(vector<char> &cards,vector<int> &acum, int pos, int l){
  if(l==52) return true;
  if(acum[pos]==4) return false;
  char carta = cards[4*pos + acum[pos]];
  acum[pos]++;
  if(carta>='2' && carta<='9'){
    return solve(cards,acum,carta-'1',l+1);
  }
  if(carta=='J'){
    return solve(cards,acum,0,l+1);
  }
  if(carta=='T'){
    return solve(cards,acum,9,l+1);
  }
  if(carta=='A'){
    return solve(cards,acum,10,l+1);
  }
  if(carta=='Q'){
    return solve(cards,acum,11,l+1);
  }
  if(carta=='K'){
    return solve(cards,acum,12,l+1);
  }
}

int main(){
  char c;
  while(cin >> c){
    if(c=='0') break;
    vector<char> cards(52);
    cards[0] = c;
    for(int i=1;i<52;i++){
      cin >> cards[i];
    }
    int resp = 0;
    for(int i=0;i<52;i++){
      vector<int> acum(13,0);
      vector<char> aux(52);
      int k=0;
      for(int j=i;j<52;j++,k++){
	aux[k]=cards[j];
      }
      for(int j=0;j<i;j++,k++){
	aux[k]=cards[j];
      }
      if(solve(aux,acum,12,0))
	resp++;
    }

    cout << resp << endl;
  }

  return 0;
}
