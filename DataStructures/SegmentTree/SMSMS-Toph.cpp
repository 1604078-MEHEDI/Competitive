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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
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
const int N = 90006;
const int M = 303;
#define inf 10000000000000
int vis[M][M], cell[M][M];

int idx = 0, row, col;
ll a[N];
struct info
{
  ll ls, rs, sm, ms;
} sg[3 * N];

int valid(int n, int m) {
  if (n > row || m > col || vis[n][m] || n < 1 || m < 1)return false;
  return 1;
}

void go(int n, int m, int d) {
  vis[n][m] = ++idx;
  a[idx] = cell[n][m];
  if (idx == row * col)return;
  ll r, c;
  r = n + dx[d];
  c = m + dy[d];
  if (valid(r, c))go(r, c, d);
  else {
    if (d == 3)go(n + dx[0], m + dy[0], 0);
    else go(n + dx[d + 1], m + dy[d + 1], d + 1);
  }
}

info query(ll node, ll s, ll e, ll i, ll j) {
  if (s > j || e < i)return { -inf, -inf, -inf, -inf};
  if (s >= i && s <= j)return sg[node];

  ll l = 2 * node;
  ll r = l + 1;
  ll mid = (s + e) / 2;
  info q1 = query(l, s, mid, i, j);
  info q2 = query(r, mid + 1, e, i, j);

  info Q;
  Q.sm = q1.sm + q2.sm;
  Q.ls = max({q1.ls, q1.sm, q1.sm + q2.ls});
  Q.rs = max({q2.rs, q2.sm, q2.sm + q1.rs});

  Q.ms = max({q1.rs, q2.ls, q1.rs + q2.ls});
  Q.ms = max({Q.ms, q1.ms, q2.ms});
  Q.ms = max({Q.ms, q1.sm, q2.sm});
  return Q;
}

void update(ll node, ll s, ll e, ll i, ll newValue) {
  if (s > i || e < i)return;
  if (s >= i && e <= i) {
    sg[node].ls = sg[node].rs = sg[node].sm = sg[node].ms = newValue;
    return;
  }

  ll l = 2 * node;
  ll r = l + 1;
  ll mid = (s + e) / 2;
  update(l, s, mid, i, newValue);
  update(r, mid + 1, e, i, newValue);

  sg[node].sm = sg[l].sm + sg[r].sm;

  sg[node].ls = max({sg[l].ls, sg[l].sm, sg[r].ls + sg[l].sm});
  sg[node].rs = max({sg[r].rs, sg[r].sm, sg[l].rs + sg[r].sm});

  sg[node].ms = max({sg[l].rs, sg[r].ls, sg[l].rs + sg[r].ls});
  sg[node].ms = max({sg[node].ms, sg[l].ms, sg[r].ms});
  sg[node].ms = max({sg[node].ms, sg[l].sm, sg[r].sm});
}


///https://toph.co/p/problem---smsms
///https://cp-algorithms.com/data_structures/segment_tree.html
///https://codeforces.com/blog/entry/56416

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
  int T;
  T = 1;
  //scanf("%d", &T);
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    memset(vis, 0, sizeof vis);
    memset(sg, 0, sizeof sg);
    idx = 0;
    cin >> row >> col;
    int q;
    cin >> q;
    ll n = row * col;
    for (int i = 1; i <= row; i++)
      for (int j = 1; j <= col; j++)cin >> cell[i][j];

    go(1, 1, 0);
    for (int i = 1; i <= n; i++) {
      ll x = a[i];
      update(1, 1, n, i, x);
    }
    cout << "Case " << cs << ":\n";
    while (q--) {
      int typ;
      cin >> typ;
      if (typ == 1) {
        info Q = query(1, 1, n, 1, n);
        ll x = max(Q.ls, Q.rs);
        ll y = max(Q.sm, Q.ms);
        ll ans = max(x, y);
        if (ans < 0)cout << 0 << "\n";
        else cout << ans << "\n";
      }
      else {
        int i, j, x;
        cin >> i >> j >> x;
        update(1, 1, n, vis[i][j], x);
      }
    }
  }
  return 0;
}
