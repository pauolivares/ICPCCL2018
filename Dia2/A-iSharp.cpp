#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  bool t = false;
  while(getline(cin,s)){
    if(!t) t=true;
    else cout<<"\n";
    string patron;
    int i=0;
    while(s[i]!=' '){
      patron+=s[i];
      i++;
    }
    ++i;
    string pal;
    string nom;
    for(;i<s.size();i++){
      if(s[i]==' ') continue;
      if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
	nom+=s[i];
      }
      else{
	if(s[i]==']') pal+='[';
	else if(s[i]=='[') pal+=']';
	else if(s[i]==',' || s[i]==';'){
	  reverse(pal.begin(),pal.end());
	  cout << patron << pal<<" "<<nom<<";"<<'\n';
	  nom="";
	  pal="";
	}
	else{
	  pal+=s[i];
	}
      }
    }


  }


  return 0;
}
