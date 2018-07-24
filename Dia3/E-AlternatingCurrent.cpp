#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  stack<char> st;
  st.push(s[0]);
  for(int i=1;i<s.size();i++){
    if(st.size()==0){ 
      st.push(s[i]);
      continue;
    }
    if(s[i]==st.top())
      st.pop();
    else st.push(s[i]);
  }
  if(st.size()==0) cout<<"Yes"<<endl;
  else cout <<"No"<<endl;

  return 0;
}
