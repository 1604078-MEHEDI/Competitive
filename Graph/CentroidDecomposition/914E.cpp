/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/
//https://codeforces.com/problemset/problem/914/E
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
vector<int> g[N];
int letter[N], sz[N], treesz;
bool vis[N];

int dfs(int u, int p)
{
  sz[u] = 1;
  for (auto v : g[u]) {
    if (vis[v] || v == p)continue;
    sz[u] += dfs(v, u);
  }
  if (p == -1) treesz = sz[u];
  return sz[u];
}

int findCenter(int u, int p)
{
  for (auto v : g[u]) {
    if (vis[v] || v == p)continue;
    if (sz[v] * 2 > treesz)return findCenter(v, u);
  }
  return u;
}

ll sm, ans[N];
int Timer;
int when[(1 << 21) + 5], cnt[(1 << 21) + 5];

void dfs1(int u, int p, int mask, int val)
{
  mask ^= letter[u];
  if (when[mask] != Timer) {
    when[mask] = Timer;
    cnt[mask] = 0;
  }
  cnt[mask] += val;
  for (auto v : g[u]) {
    if (vis[v] || v == p)continue;
    dfs1(v, u, mask, val);
  }
}

ll dfs2(int u, int p, int mask)
{
  ll res = 0;
  mask ^= letter[u];
  for (auto v : g[u]) {
    if (!vis[v] && v != p)res +=  dfs2(v, u, mask);
  }
  if (when[mask] == Timer) res += cnt[mask];
  if (mask == 0) {
    sm++;
    res++;
  }
  for (int i = 0; i < 21; i++) {
    int need = mask ^ (1 << i);
    if (when[need] == Timer) res += cnt[need];
    if (need == 0) {
      res++;
      sm++;
    }
  }
  ans[u] += res;
  return res;
}

void solve(int center)
{
  Timer++;
  sm = 0;
  for (auto v : g[center]) {
    if (!vis[v])dfs1(v, center, 0, 1);
  }
  for (int v : g[center]) {
    if (vis[v])continue;
    dfs1(v, center, 0, -1);
    sm += dfs2(v, center, letter[center]);
    dfs1(v, center, 0, 1);
  }
  sm /= 2;
  ans[center] += sm;
}

void compsolve(int u)
{
  dfs(u, -1);
  int center = findCenter(u, -1);
  solve(center);
  vis[center] = true;
  for (auto v : g[center]) {
    if (!vis[v])compsolve(v);
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
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  string s;
  cin >> s;
  for (int i = 0; i < n; i++)
    letter[i + 1] = (1 << (s[i] - 'a'));
  compsolve(1);
  for (int i = 1; i <= n; i++)
    cout << ans[i] + 1 << " ";
  cout << endl;
  return 0;
}
