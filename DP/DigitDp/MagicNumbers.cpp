
///https://codeforces.com/contest/628/problem/D
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
ll d, m;
string a, b;
const int N = 2020;
ll dp[N][N][2];


ll go(string s)
{
  int n = s.size();
  memset(dp, 0, sizeof dp);
  dp[0][0][1] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 2; k++) {
        for (int p = 0; p <= (k ? (int)(s[i] - '0') : 9); p++) {
          if ((i & 1) && p != d) continue;
          if (!(i & 1) && p == d) continue;
          if (!i && !p) continue;
          int Ni = i + 1;
          int Nj = (j * 10 + p) % m;
          int Nk = k && (p == (int)s[i] - '0');
          dp[Ni][Nj][Nk] = modAdd(dp[Ni][Nj][Nk], dp[i][j][k]);
        }
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < 2; i++) ans = modAdd(ans, dp[n][0][i]);
  return ans;
}

bool good(string s)
{
  int ret = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    int p = (int)(s[i] - '0');
    if ((i & 1) && p != d) return false;
    if (!(i & 1) && p == d) return false;
    ret = (ret * 10 + p) % m;
  }
  return !ret;
}
void solve()
{
  ll ans = 0;
  ans = modAdd(ans, go(b));
  ans = modSub(ans, go(a));
  ans = modAdd(ans, good(a));
  cout << ans << endl;
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
  int T;
  //scanf("%d", &T);
  T = 1;
  for (int cs = 1; cs <= T; cs++) {
    cin >> m >>  d  >> a >> b;
    solve();
  }
  return 0;
}

/*
2nd solution:
const int N = 2020;
ll m, d;
int dp[N][N][2][2];
string a, b;

ll solve(int pos, int rem, bool l, bool r)
{
  if (pos == (int)a.size()) return rem == 0;
  int &ret = dp[pos][rem][l][r];
  if (ret != -1) return ret;

  ret = 0;
  for (int i = 0; i <= 9; i++) {
    if (i < a[pos] - '0' && l == 0) continue;
    if (i > b[pos] - '0' && r == 0) continue;
    if (pos % 2 == 1 && i != d) continue;
    if (pos % 2 == 0 && i == d) continue;
    ret = modAdd(ret, solve(pos + 1, (rem * 10 + i) % m, l || i > a[pos] - '0', r || i < b[pos] - '0'));
  }
  return ret;
}

int main()
{
//   FASTIO
//   ///*
// #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
//   freopen("error.txt", "w", stderr);
// #endif
// //
  cin >> m >> d;
  cin >> a >> b;
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0, 0, 0) << endl;
}
*/
