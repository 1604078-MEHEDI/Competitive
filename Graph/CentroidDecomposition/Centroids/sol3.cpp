/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/
///https://codeforces.com/contest/708/problem/C
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
int n;
vector<vector<int> > g;
vector<int> cnt;

int mn = mod;
int Center = -1;

void dfs(int u, int p)
{
  cnt[u] = 1;
  int mx = 0;
  for (auto v : g[u]) {
    if (v == p)continue;
    dfs(v, u);
    cnt[u] += cnt[v];
    mx = max(mx, cnt[v]);
  }
  mx = max(mx, n - cnt[u]);
  if (mx < mn) {
    mn = mx;
    Center = u;
  }
}

vector<pair<int, int>> subtrees;
vector<bool>ans;

void go(int u, int p, int sum_other, int prv)
{
  if (sum_other <= n / 2) ans[u] = 1;
  for (int i = 0; i < 2 && i < (int)subtrees.size(); i++) {
    if (subtrees[i].second == prv)continue;

    if (n - cnt[u] - subtrees[i].first <= n / 2)
      ans[u] = 1;
  }
  for (auto v : g[u]) {
    if (v == p)continue;
    go(v, u, sum_other, prv);
  }
}

void solve()
{
  cin >> n;
  g.resize(n);
  cnt.assign(n, 0);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, 0);
  ans.assign(n, 0);
  ans[Center] = 1;
  dfs(Center, Center);
  int sum_all = 0;
  for (auto v : g[Center]) {
    subtrees.push_back({cnt[v], v});
    sum_all += cnt[v];
  }
  sort(subtrees.rbegin(), subtrees.rend());
  for (auto v : g[Center]) {
    go(v, Center, n - cnt[v], v);
  }
  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n - 1];
  return;
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
  solve();
}
