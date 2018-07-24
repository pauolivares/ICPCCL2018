#include <bits/stdc++.h>
using namespace std;

int dp[1010][1010];
int n,m;
vector<int> nums;
int solve(int num,int mod,bool agarre){
  if(num>n) return false;
  if(num==n && mod==0 ){
    return agarre;
  }
  if(dp[num][mod]!=-1) return dp[num][mod];
  return dp[num][mod] = solve(num+1,(mod+nums[num])%m,true) | solve(num+1,mod,agarre);
}

int main(){
  scanf("%d %d",&n,&m);
  //vector<bool> acum(m,false);
  //acum[0]=true;
  nums.assign(n,0);
  for(int i=0;i<n;i++){
    scanf("%d",&nums[i]);
  }
  if(n>m){
    printf("YES\n");
    return 0;
  }
  for(int i=0;i<1010;i++)
    for(int j=0;j<1010;j++)
      dp[i][j]=-1;
  if(solve(0,0,false)){
    puts("YES");
  }else{
    puts("NO");
  }
  return 0;

}
