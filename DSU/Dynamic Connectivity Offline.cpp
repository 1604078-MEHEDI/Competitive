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
const int N = 300006;

int p[N], sz[N], ans;
stack<int> st;

int n, k;
int u[N << 1], v[N << 1], o[N << 1];

char op[N << 1];
map<pii, int> mp;
int find(int u) {
  while (p[u] != u) u = p[u]; // Notice: No path compression. Path Compression will make the algorithm O(n^2)
  return u;
}

void Union(int u, int v) {
  u = find(u); v = find(v);
  if (u == v) return;
  if (sz[u] > sz[v]) swap(u, v); // Attach small tree to larger, to keep height O(log n)
  p[u] = v;
  sz[v] += sz[u];
  ans--;
  st.push(u); // this means u was attached to p[u]
}

void Rollback(int t) { // Rollback updates until stack size is t.
  while ((int)st.size() > t) {
    int u = st.top(); st.pop();
    sz[p[u]] -= sz[u];
    p[u] = u; ans++;
  }
}

void solve(int l, int r) {
  // Possible optimization: If no queries in range -> return;
  if (l == r) {
    if (op[l] == '?')
      printf("%d\n", ans);
    return;
  }

  int m = (l + r) >> 1;
  int now = st.size();// Backup the size of stack 'now'


  // For remove queries in [m+1,r], if it was added before l, then union it to dsu.
  for (int i = m + 1; i <= r; i++)
    if (o[i] < l) Union(u[i], v[i]);
  solve(l, m); // Go to solve left side
  Rollback(now);// Remove previously added edges.


  // For add queries in [l, m], if it won't be removes in [m+1,r], then add it to dsu.
  for (int i = l; i <= m; i++)
    if (o[i] > r) Union(u[i], v[i]);
  solve(m + 1, r); // Solve right side.
  Rollback(now); // Rollback
}
///https://codeforces.com/edu/course/2/lesson/7/3/practice/contest/289392/problem/C
//https://codeforces.com/gym/100551/problem/A


void Input(string s) {
  if (fopen((s + ".in").c_str(), "r")) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

///Credit: Rezwan.Arefin01

int main()
{
  FASTIO
  //*
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  //*/
 // Input("connect");
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    p[i] = i; sz[i] = 1;
  }
  if (!k)return 0;

  for (int i = 1; i <= k; i++) {
    cin >> op[i];
    if (op[i] == '?')continue;
    cin >> u[i] >> v[i];
    if (u[i] > v[i])swap(v[i], u[i]);


    pii x(u[i], v[i]);
    if (mp.count(x)) {
      o[i] = mp[x]; // o[i] = other end of i-th query; for remove query when it was added and vice versa.
      o[o[i]] = i;
      mp.erase(x);
    }
    else {
      mp[x] = i;
    }
  }

  int idx = k;
  for (auto it : mp) { // For convenience, remove existing add queries.
    o[it.second] = ++idx;
    o[idx] = it.second;
    op[idx] = '.';
    tie(u[idx], v[idx]) = it.first;
  }
  ans = n;
  solve(1, idx);
  return 0;
}
