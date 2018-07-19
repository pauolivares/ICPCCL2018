#include <bits/stdc++.h>

using namespace std;

long long dp[101][101];
long long mod = 1001113;
long long solve(long long a,long long b){
  if(a==0 && b== 0) return 1;
  if(b==0 ) return 1;
  if(b>=a) return 0;
  if(dp[a][b]!=-1) return dp[a][b];
  return dp[a][b] = (((a-b)*solve(a-1,b-1))%mod + ((b+1)*solve(a-1,b))%mod)%mod;
}

int main(){
  long long t;
  for(long long i=0;i<101;i++){
    for(long long j=0;j<101;j++){
      dp[i][j]=-1;
    }
  }
  dp[1][0]=1;
  dp[1][1]=1;
  cin>>t;
  while(t--){
    long long a,b,c;
    cin>>a>>b>>c;
    cout<<a<<" "<<solve(b,c)<<endl;
  }
  return 0;
}
