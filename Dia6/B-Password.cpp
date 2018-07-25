#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define invrep(i,n) for(int i=n-1;i>=0;--i)
#define d 256

typedef unsigned long long ull;

ull mod[] = {(int)1e9+7, (int)1e9+9};

int maxstrlen = 1e6;
using namespace std;

class RH {
  static vector<ull> x[2];
  vector<ull> h[2];
  string str;
  int n;
  ull hash(int a, int start, int len) {
    ull ans = 0, end = start + len;
    ans += h[a][start] - h[a][end]*x[a][len] %mod[a] + mod[a];
    return ans %mod[a];
  }
 
public: RH() {}
  RH(const string &str) { 
    this->str = str;
    n = str.size();
    if (x[0].empty()) rep(a, 2) {
	x[a].assign(maxstrlen+1, 1);
	rep(i, maxstrlen) x[a][i+1] = x[a][i]*127 %mod[a];
      }
    rep(a, 2) {
      h[a].assign(n+1, 0);
      invrep(i, n) h[a][i] = (h[a][i+1]*127 + str[i]) %mod[a];
    }
  }
 
  ull hash(int start, int len) { // complejidad: O(1)
    return hash(0, start, len) << 32 | hash(1, start, len);
  }
 
};
vector<ull> RH::x[2]; 
bool search(string pat, string txt, int q){
  int M = pat.size();
  int N = txt.size();
  int i, j;
  int p = 0; 
  int t = 0; 
  int h = 1;
 
  for (i = 0; i < M-1; i++)
    h = (h*d)%q;
 
  for (i = 0; i < M; i++)
    {
      p = (d*p + pat[i])%q;
      t = (d*t + txt[i])%q;
    }
 
  for (i = 0; i <= N - M; i++)
    {
      if ( p == t )
        {
	  for (j = 0; j < M; j++)
            {
	      if (txt[i+j] != pat[j])
		break;
            }
 
	  if (j == M) return true;
        }
 
      if ( i < N-M )
        {
	  t = (d*(t - txt[i]*h) + txt[i+M])%q;
 
	  if (t < 0)
            t = (t + q);
        }
    }
  return false;
}

int main(){
  int q = 0;
  string s,a = "",b = "";
  cin >> s;
  if( s.size() <= 2){
    puts("Just a legend");
    return 0;    
  }
  RH comp(s);
  string meter = s.substr(1,s.size()-2);
  bool imprimi = false;
  for(int i = s.size()-3; i >=0; i--){
    if(comp.hash(0,i+1)== comp.hash(s.size()-1-i,i+1)){
      for(q = 0; q < i+1; q++){
        if(s[0+q] != s[s.size()-1-i+q])break;
      }
      if(q == i+1){
	if(search(s.substr(0,i+1),meter,101)){
	  imprimi = true;
	  cout << s.substr(0,i+1)<<endl;
	  break;
	}
      }
    } 
  }

  if(!imprimi)puts("Just a legend");
  return 0;
}
