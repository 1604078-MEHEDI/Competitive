/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
using pii = pair<int, int>;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
//const ll mod = 998244353;


inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a * b) % mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a + b) % mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while (p) { if (p & 1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define ps(ch) printf("%s",ch)
#define F(i,a,b)      for(int i= a; i <= b; i++)
#define R(i,b,a)      for(int i= b; i >= a; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
int kx8[] = {1, 1, 2, 2, -1, -1, -2, -2};
int ky8[] = {2, -2, 1, -1, 2, -2, 1, -1};
/* for Random Number generate
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
*/
///**
template < typename F, typename S >ostream& operator << ( ostream& os, const pair< F, S > & p ) {return os << "(" << p.first << ", " << p.second << ")";}
template < typename T >ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{"; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", "; os << *it;} return os << "}";}
template < typename T >ostream &operator << ( ostream & os, const set< T > &v ) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin()) os << ", "; os << *it;} return os << "]";}
template < typename F, typename S >ostream &operator << ( ostream & os, const map< F, S > &v ) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", "; os << it -> first << " = " << it -> second ;} return os << "]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
void faltu () { cerr << endl; }
template <typename T>void faltu( T a[], int n ) {for (int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl;}
template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) { cerr << arg << ' '; faltu(rest...); }

// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less 
using namespace __gnu_pbds;

// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;
// find_by_order(k) – ফাংশনটি kth ordered element এর একটা পয়েন্টার রিটার্ন করে। অর্থাৎ তুমি চাইলেই kth ইন্ডেক্সে কি আছে, সেটা জেনে ফেলতে পারছো!
// order_of_key(x) – ফাংশনটি x এলিমেন্টটা কোন পজিশনে আছে সেটা বলে দেয়।
//*//**___________________________________________________**/
const int N = 1000006;



///Support distances up to representative


pii parent[N];
int size[N];
void make_set(int v) {
  parent[v] = make_pair(v, 0);
  size[v] = 0;
}

pii find_set(int v) {
  if (v != parent[v].first) {
    int len = parent[v].second;
    parent[v] = find_set(parent[v].first);
    parent[v].second += len;
  }
  return parent[v];
}

void Union(int a, int b) {
  a = find_set(a).first;
  b = find_set(b).first;
  if (a != b) {
    if (size[a] < size[b])swap(a, b);
    parent[b] = make_pair(a, 1);
    if (size[a] == size[b])size[a]++;
  }
}




////Support the parity of the path length / Checking bipartiteness online

pii par[N];
int Rank[N], bipartiteness[N];
void Make(int x) {
  par[x] = make_pair(x, 0);
  Rank[x] = 0;
  bipartiteness[x] = true;
}

pii get(int x) {
  if (x != par[x].first) {
    int parity = par[x].second;
    par[x] = get(par[x].first);
    par[x].second ^= parity;
  }
  return par[x];
}

void add_edge(int a, int b) {
  pii pa = get(a);
  a = pa.first;
  int x = pa.second;

  pii pb = get(b);
  b = pb.first;
  int y = pb.second;

  if (a == b) {
    if (x == y)bipartiteness[a] = false;
  }
  else {
    if (Rank[a] < Rank[b])swap(a, b);
    par[b] = make_pair(a, x ^ y ^ 1);
    bipartiteness[a] &= bipartiteness[b];
    if (Rank[a] == Rank[b])Rank[a]++;
  }
}

bool is_bipartite(int x) {
  return bipartiteness[get(x).first];
}






//Offline RMQ (range minimum query) in O(α(n))
//on average / Arpa's trick


struct Query
{
  int L, R, idx;
};
int n;
int a[N];
int P[N];
vector<int>ans;
vector<vector<Query>> container;

int _find_set(int x){return x;};

void go() {
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.top() > a[i]]) {
      P[st.top()] = i;
      st.pop();
    }
    st.push(i);
    for (Query q : container[i]) {
      ans[q.idx] = a[_find_set(q.L)];
    }
  }
}




////Storing the DSU explicitly in a set list / Applications of this idea when merging various data structures

vector<int> lst[N];
int Parent[N];

void Make_Set(int v) {
  lst[v] = vector<int> (1, v);
  Parent[v] = v;
}

int Find_set(int v) {
  return Parent[v];
}

void Union_sets(int a, int b) {
  a = Find_set(a);
  b = Find_set(b);

  if (a != b) {
    if (lst[a].size() < lst[b].size())
      swap(a, b);
    while (!lst[b].empty()) {
      int v = lst[b].back();
      Parent[v] = a;
      lst[a].push_back(v);
    }
  }
}


int main()
{
  FASTIO
  ///*
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
//*/
  ///https://cp-algorithms.com/data_structures/disjoint_set_union.html#toc-tgt-5


  return 0;
}
