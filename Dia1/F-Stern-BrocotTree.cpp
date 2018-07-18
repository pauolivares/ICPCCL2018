#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    ll l1=0,l2=1,r1=1,r2=0,a1=1,a2=1;
    for(int j=0;j<s.size();j++){
      if(s[j]=='R'){
	l1=a1,l2=a2;
	a1+=r1;
	a2+=r2;
      }
      else{
	r1=a1,r2=a2;
	a1+=l1;
	a2+=l2;
      }
    }
    cout<<a1<<"/"<<a2<<endl;
  }


  return 0;
}
