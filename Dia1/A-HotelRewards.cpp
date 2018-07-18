#include <bits/stdc++.h>

using namespace std;

int main(){

  int N,K;
  while(cin>>N>>K){
    vector<int> vec;
    int suma=0;
    for(int i=0;i<N;i++){
      int aux;
      cin>>aux;
      vec.push_back(aux);
      suma+=aux;
    }
    priority_queue<int> pq; 
    for(int i=K;i<N;i++){
      if(i==K) pq.push(-vec[K]);
      int size = (i+1)/(K+1);
      if(size>pq.size()) pq.push(-vec[i]);
      else if(vec[i]>-pq.top()) {
	pq.pop();
	pq.push(-vec[i]);
      }

    }
    while(!pq.empty()) {
      suma -= -pq.top();
      pq.pop();
    }
    cout<<suma<<endl;
  }
  return 0;
}
