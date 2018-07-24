#include <bits/stdc++.h>

using namespace std;

template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }

const int MAX = 100;

struct Point { double x, y; };
struct Segment { Point a, b; };

Segment seg[MAX];
inline double direction(Point &pi, Point &pj, Point &pk) {
  return (pk.x-pi.x)*(pj.y-pi.y)-(pj.x-pi.x)*(pk.y-pi.y);
}

inline bool onsegment(Point &pi, Point &pj, Point &pk) {
  return (inside(min(pi.x,pj.x),pk.x,max(pi.x,pj.x)) && inside(min(pi.y,pj.y),pk.y,max(pi.y,pj.y)));
}

inline bool intersect(Point &p1, Point &p2, Point &p3, Point &p4) {
  double d1, d2, d3, d4;
  d1 = direction(p3, p4, p1);
  d2 = direction(p3, p4, p2);
  d3 = direction(p1, p2, p3);
  d4 = direction(p1, p2, p4);
  if(((d1>0 && d2<0)||(d1<0 && d2>0)) && ((d3>0 && d4<0)||(d3<0 && d4>0))) return true;
  if(!d1 && onsegment(p3, p4, p1)) return true;
  if(!d2 && onsegment(p3, p4, p2)) return true;
  if(!d3 && onsegment(p1, p2, p3)) return true;
  if(!d4 && onsegment(p1, p2, p4)) return true;
  return false;
}

int main(){
  int n;
  while(scanf("%d",&n)!=EOF){
    if(n==0) break;
    for(int i=0;i<n;i++){
      scanf("%lf %lf %lf %lf",&seg[i].a.x,&seg[i].a.y,&seg[i].b.x,&seg[i].b.y);
    }
    long long wea = 0;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        for(int k=j+1;k<n;k++){
          if(intersect(seg[i].a,seg[i].b,seg[j].a,seg[j].b)
	     && intersect(seg[i].a,seg[i].b,seg[k].a,seg[k].b)
	     && intersect(seg[k].a,seg[k].b,seg[j].a,seg[j].b)){
            wea++;
          }
        }
      }
    }
    printf("%lld\n",wea );
  }
  return 0;
}
