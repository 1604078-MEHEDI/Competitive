///https://codeforces.com/gym/100570/problem/F
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

const int N  = 2e5 + 5;
typedef pair<ll, ll> pll;
vector<pll>g[N], Q[N];
vector<ll> me, tot, nodes;
int cnt[N], bc[N], ans[N];
ll h[N];
bool mark[N];
int dfs(int v, bool c = 0, int p = -1, ll dis = 0)
{
  h[v] = dis;
  cnt[v] = 1;
  bc[v] = 0;
  me.push_back(dis);
  nodes.push_back(v);
  if (c)tot.push_back(dis);
  for (auto to : g[v]) {
    int u = to.first;
    if (u != p && !mark[u]) {
      cnt[v] += dfs(u, c, v, dis + to.second);
      if (!bc[v] || cnt[bc[v]] < cnt[u])
        bc[v] = u;
    }
  }
  return cnt[v];
}

void go(int v)
{
  dfs(v);
  int n = cnt[v];
  while (cnt[bc[v]] * 2 > n) v = bc[v];
  tot.clear();
  dfs(v, 1);
  mark[v] = 1;
  sort(tot.begin(), tot.end());
  for (auto it : Q[v]) {
    ll w = it.first;
    int i = it.second;
    ans[i] += upper_bound(tot.begin(), tot.end(), w) - tot.begin() - 1;
  }

  for (auto to : g[v]) {
    if (!mark[to.first]) {
      me.clear();
      nodes.clear();
      dfs(to.first, 0, v, to.second);
      sort(me.begin(), me.end());
      for (auto u : nodes) {
        for (auto q : Q[u]) {
          ll w = q.first;
          int i = q.second;
          ans[i] += upper_bound(tot.begin(), tot.end(), w - h[u]) - tot.begin();
          ans[i] -= upper_bound(me.begin(), me.end(), w - h[u]) - me.begin();
        }
      }
    }
  }

  for (auto u : g[v]) {
    if (!mark[u.first])go(u.first);
  }
  mark[v] = 0;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i < n; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back(make_pair(v, w));
    g[v].push_back(make_pair(u, w));
  }
  for (int i = 0; i < q; i++)
  {
    long long v, w;
    cin >> v >> w;
    Q[v].push_back(make_pair(w, i));
  }
  go(1);
  for (int i = 0; i < q; i++)
    cout << ans[i] + 1 << endl;
}
