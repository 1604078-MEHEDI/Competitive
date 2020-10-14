
///https://toph.co/p/city-of-burgerland
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
const ll N = 1e5 + 5;
ll a[N];
vector<ll> seg[3 * N], cum[3 * N];

void Build(ll l, ll r, ll node)
{
  //dbg(l, r);
  if (l == r) {
    seg[node].push_back(a[l]);
    cum[node].push_back(a[l]);
    return;
  }
  ll m = (l + r) / 2;
// dbg(l, r);
  Build(l, m, 2 * node);
 // dbg(l, r);
  Build(m + 1, r, 2 * node + 1);
  //dbg(l, r);
  merge(seg[2 * node].begin(), seg[2 * node].end() , seg[2 * node + 1].begin(), seg[2 * node + 1].end(), back_inserter(seg[node]));
  ll sm = 0;
  for (auto it : seg[node]) {
    sm += it;
    cum[node].push_back(sm);
  }
  //dbg(l, r);
}

ll Query(ll node, ll b, ll e, ll l, ll r, ll x)
{
  if (r < b || l > e) return 0;
  if (b >= l && e <= r) {
    //(l, r);
    ll idx = upper_bound(seg[node].begin(), seg[node].end(), x) - seg[node].begin();
    //dbg(seg[node]);
    //dbg(idx, node);
    //dbg(cum[node]);
    ll sum = cum[node][idx - 1];
    //dbg(idx, sum);
    if (idx == 0)return 0;
    ll ans = x * idx - sum;
   // dbg(ans);
    return ans;
  }
  ll m = (b + e) / 2;
  ll ls  = Query(2 * node, b, m, l, r, x);
  ll rs = Query(2 * node + 1, m + 1, e, l, r, x);
  return ls + rs;
}


int main()
{
 // FASTIO
  ///*
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
//*/
  ll n, q;
  scanf("%lld %lld", &n, &q);
  for (ll i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  //dbg(q);
  Build(1, n, 1);
  //dbg(q);
  while (q--) {
    ll l, r, x;
    scanf("%lld %lld %lld", &l, &r, &x);

    printf("%lld\n", Query(1, 1, n, l, r, x));
    //dbg(l, r, x);
  }

}
