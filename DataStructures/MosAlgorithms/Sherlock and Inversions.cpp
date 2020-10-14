/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/


/*
https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/sherlock-and-inversions/description/
https://www.codechef.com/problems/IITI15
*/
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
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
const ll N = 100006;
ll n, a[N], q;
typedef pair<ll, ll> pii;
pair<pii, ll> Q[N];
ll data[N];
ll ans[N];
ll sm[N], sm2[N];
const ll K = 150;
ll k;
void add(ll pos, ll val)
{
  for (; pos < k; pos |= (pos + 1))
    sm[pos] += val;
}

ll fnd(ll pos)
{
  ll ans = 0;
  for (; pos >= 0; (pos &= (pos + 1))--)ans += sm[pos];
  return ans;
}

void add2(ll pos, ll val)
{
  for (; pos >= 0; (pos &= (pos + 1))--)
    sm2[pos] += val;
}

ll fnd2(ll pos)
{
  ll ans = 0;
  for (; pos < k; (pos |= (pos + 1)))ans += sm2[pos];
  return ans;
}

inline bool cmp(const pair<pii, ll> &a, const pair<pii, ll> &b)
{
  if (a.first.second / K != b.first.second / K)return a.first.second / K < b.first.second / K;
  return a.first.first < b.first.first;
}

int main()
{
  //FASTIO
  ///*
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
//*/
  sl(n);
  sl(q);
  for (ll i = 0; i < n; i++) {
    sl(a[i]);
    data[i] = a[i];
  }
  sort(data, data + n);
  k = unique(data, data + n) - data;

  for (ll i = 0; i < n; i++)
    a[i] = lower_bound(data, data + k, a[i]) - data;

  for (ll i = 0; i < k; i++)sm[i] = sm2[i] = 0;

  for (ll i = 0; i < q; i++) {
    ll l, r;
    sll(l, r);
    --l;
    --r;
    Q[i] = {{l, r}, i};
  }
  sort(Q, Q + q, cmp);

  ll l = 0;
  ll r = -1;
  ll res = 0;
  for (ll i = 0; i  < q; i++) {
    ll Right = Q[i].first.second;
    ll Left = Q[i].first.first;
    ll ID = Q[i].second;
    while (r < Right) {
      ++r;
      add(a[r], 1);
      add2(a[r], 1);
      res += fnd2(a[r] + 1);
    }

    while (r > Right) {
      add(a[r], -1);
      add2(a[r], -1);
      res -= fnd2(a[r] + 1);
      --r;
    }

    while (l > Left) {
      --l;
      add(a[l], 1);
      add2(a[l], 1);
      res += fnd(a[l] - 1);
    }

    while (l < Left) {
      add(a[l], -1);
      add2(a[l], -1);
      res -= fnd(a[l] - 1);
      ++l;
    }
    ans[ID] = res;
  }

  for (ll i = 0; i < q; i++) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
