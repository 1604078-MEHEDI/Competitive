/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/
//https://wcipeg.com/problem/ioi1112
#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 1000005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;

inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a * b) % mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a + b) % mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while (p) { if (p & 1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }


/* for Random Number generate
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
*/
///**
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
  return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if ( it != v.begin() ) os << ", ";
    os << *it;
  }
  return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if ( it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if ( it != v.begin() ) os << ", ";
    os << it -> first << " = " << it -> second ;
  }
  return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

void faltu () { cerr << endl; }

template <typename T>
void faltu( T a[], int n ) {
  for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
  cerr << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) { cerr << arg << ' '; faltu(rest...); }
// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less 
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

// find_by_order(k) – ফাংশনটি kth ordered element এর একটা পয়েন্টার রিটার্ন করে। অর্থাৎ তুমি চাইলেই kth ইন্ডেক্সে কি আছে, সেটা জেনে ফেলতে পারছো!
// order_of_key(x) – ফাংশনটি x এলিমেন্টটা কোন পজিশনে আছে সেটা বলে দেয়।

//*//**___________________________________________________**/

const int N = 2e5 + 5;
const int M = 1e6 + 6;
const int inf = mod;

set<pair<int, int>> g[N];
int n, k;
int sz[N], exits[M], edgecnt[M], tt;

int dfs(int u, int p)
{
  sz[u] = 1;
  for (auto it : g[u]) {
    if (it.first == p)continue;
    sz[u] += dfs(it.first, u);
  }
  return sz[u];
}

int centroid(int u, int p, int nn)
{
  for (auto it : g[u]) {
    if (it.first == p)continue;
    if (sz[it.first] > nn / 2) return centroid(it.first, u, nn);
  }
  return u;
}

int dfs2(int u, int p, int d, int cnt, int t, vector<pair<int, int> >& v)
{
  int want = k - d;
  int ans = inf;
  if (want >= 0 && exits[want] == t) {
    ans = min(ans, cnt + edgecnt[want]);
  }
  if (d <= k) {
    v.push_back({d, cnt});
    for (auto it : g[u]) {
      if (it.first == p)continue;
      ans = min(ans, dfs2(it.first, u, d + it.second, cnt + 1, t, v));
    }
  }
  return ans;
}

int solve(int u, int p)
{
  int nn = dfs(u, p);
  int C = centroid(u, p, nn);
  int ans = inf;
  int t = ++tt;
  exits[0] = t;
  edgecnt[0] = 0;
  for (auto it : g[C]) {
    vector<pair<int, int> > vec;
    ans = min(ans, dfs2(it.first, C, it.second, 1, t, vec));
    for (auto x : vec) {
      if (exits[x.first] != t || (exits[x.first] == t && edgecnt[x.first] > x.second)) {
        exits[x.first] = t;
        edgecnt[x.first] = x.second;
      }
    }
  }
  vector<pair<int, int>> vec(g[C].begin(), g[C].end());
  for (auto it : vec) {
    g[C].erase(it);
    g[it.first].erase({C, it.second});
    ans = min(ans, solve(it.first, C));
  }
  return ans;
}

void go()
{
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].insert({v, w});
    g[v].insert({u, w});
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
  tt = 0;
  go();
  int ans = solve(0, -1);
  if (ans == inf) ans = -1;
  cout << ans << endl;
  return 0;
}
