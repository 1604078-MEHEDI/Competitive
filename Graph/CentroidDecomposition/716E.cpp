
///https://codeforces.com/contest/716/problem/E
#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 1000005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
ll mod ;//= 1e9 + 7;

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
const int N = 1e5 + 5;
bool isprime[N];
vector<ll> primes;
vector<pair<int, int> > g[N];
int subsize[N];
bool visited[N];
int treesize;
vector<int> clrlist;
ll up[N];
ll down[N];
int h[N];
int PHI;
int dp[N];
ll n;

void sieve(int n)
{
  primes.push_back(2);
  for (int i = 3; i < N; i++) {
    if (!isprime[i]) {
      primes.push_back(i);
      for (int j = 2 * i; j < N; j += i) {
        isprime[j] = true;
      }
    }
  }
}

int phi(int n)
{
  ll num = 1;
  ll num2 = n;
  for (ll i = 0; primes[i]*primes[i] <= n; i++) {
    if (n % primes[i] == 0) {
      num2 /= primes[i];
      num *= (primes[i] - 1);
    }
    while (n % primes[i] == 0) {
      n /= primes[i];
    }
  }
  if (n > 1) {
    num2 /= n;
    num *= (n - 1);
  }
  num *= num2;
  return num;
}

ll inv(ll a)
{
  return modPow(a, PHI - 1);
}

void dfs(int u, int p)
{
  if (p == -1) clrlist.clear();
  subsize[u] = 1;
  clrlist.push_back(u);
  for (auto it : g[u]) {
    int v = it.first;
    if (visited[v] || v == p)continue;
    dfs(v, u);
    subsize[u] += subsize[v];
  }
  if (p == -1) treesize = subsize[u];
}

int centroid(int u, int p)
{
  for (auto v : g[u]) {
    if (visited[v.first] || v.first == p)continue;
    if (subsize[v.first] * 2 > treesize) return centroid(v.first, u);
  }
  return u;
}
int parts;

void Fill(int u, int p, int C)
{
  if (p == C) {
    dp[u] = parts;
    parts++;
  }
  else if (p != -1) {
    dp[u] = dp[p];
  }
  for (auto it : g[u]) {
    int v = it.first;
    int w = it.second;
    if (v == p || visited[v])continue;
    down[v] = modAdd(modMul(down[u], 10), w);
    up[v] = modAdd(up[u], modMul(modPow(10, h[u]), w));
    h[v] = h[u] + 1;
    Fill(v, u, C);
  }
}

ll go(int C)
{
  for (int i = 0; i < (int)clrlist.size(); i++) {
    up[clrlist[i]] = 0;
    down[clrlist[i]] = 0;
    h[clrlist[i]] = 0;
  }

  parts = 0;
  Fill(C, -1, C);
  parts--;
  dp[C] = -1;
  map<ll, ll> tot; // only count up
  vector<map<ll, ll> > vec; // count up in specific subtree
  vec.resize(parts + 1);
  tot[0]++;
  for (auto u : clrlist) {
    if (u == C) continue;
    tot[up[u]]++;
    vec[dp[u]][up[u]]++;
  }

  ll ans = 0;
  for (auto u : clrlist) {
    int ht = h[u];
    int pt = dp[u];
    if (u == C) {
      ans += (tot[0] - 1); //exclude cent as the vertex
    }
    else {
      ll val = ((-down[u]) % mod + mod) % mod;
      val = modMul(val, inv(modPow(10, ht)));
      ans += (tot[val] - vec[pt][val]);
    }
  }
  return ans;
}

ll decompose(int u)
{
  dfs(u, -1);
  int C = centroid(u, -1);
  ll  ans = go(C);
  visited[C] = true;
  for (auto v : g[C]) {
    if (!visited[v.first]) ans += decompose(v.first);
  }
  return ans;
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
  cin >> n >> mod;
  if (mod == 1) {
    cout << n*(n - 1);
    return 0;
  }
  sieve(N);
  PHI = phi(mod);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  cout << decompose(0) << endl;
  return 0;
}
