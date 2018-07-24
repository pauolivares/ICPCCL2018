#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  int M=n;
  set<int> nums;
  for(int i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    nums.insert(-a);
    while(!nums.empty()){
      int aux=-(*nums.begin());
      if(aux==M){
	M--;
	printf("%d ",aux);
	nums.erase(-aux);
      }
      else break;
    }
    printf("\n");
  }


  return 0;
}
