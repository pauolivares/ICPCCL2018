#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
class UnionFind {
private:
  vi p, rank, setSize;
  ll numSets;
public:
  UnionFind(ll N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (ll i = 0; i < N; i++) p[i] = i; }
  ll findSet(ll i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(ll i, ll j) { return findSet(i) == findSet(j); }
  void unionSet(ll i, ll j) {  
    if (!isSameSet(i, j)) { numSets--;  
    ll x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  ll numDisjollSets() { return numSets; }
  ll sizeOfSet(ll i) { return setSize[findSet(i)]; }
};


int main(){
	ll n,m;
	scanf("%lld %lld",&n,&m);
	ll total = 0;
	priority_queue<pair<ll,pair<ll,ll> > > pq;
	ll res =0;
	UnionFind UF(n+10);
	for(ll i=0;i<m;i++){
		ll a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		total += c;
		pq.push(make_pair(c,make_pair(a,b)));
	}
	ll mod = 1e9;
	while(!pq.empty()){
		ll u = pq.top().second.first,v = pq.top().second.second,w = pq.top().first;
		pq.pop();
		if(!UF.isSameSet(u,v)){
			res += UF.sizeOfSet(u)*UF.sizeOfSet(v)*total;
		}

		UF.unionSet(u,v);
		total -= w;
		res%=mod;
	}
	cout<<res<<endl;
	return 0;
}
