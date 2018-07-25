#include <bits/stdc++.h>
using namespace std;

int main(){
  int f1,c1,f2,c2;
  char x;
  cin>>x>>c1;
  f1=x-'a';
  cin>>x>>c2;
  f2=x-'a';
  cout << max(abs(f1-f2),abs(c1-c2))<<endl;
  while(f1!=f2 && c1!=c2){
    if(f1<f2){ 
      cout<<"R";
      f1++;
    }
    else{
      cout<<"L";
      f1--;
    }

    if(c1<c2){
      cout<<"U";
      c1++;
    }
    else{
      cout<<"D";
      c1--;
    }
    cout << endl;
  }
  while(f1!=f2){
    if(f1<f2){ 
      cout<<"R";
      f1++;
    }
    else{
      cout<<"L";
      f1--;
    }

    cout << endl;
  }
  while(c1!=c2){
		
    if(c1<c2){
      cout<<"U";
      c1++;
    }
    else{
      cout<<"D";
      c1--;
    }
    cout << endl;
  }

  return 0;
}
