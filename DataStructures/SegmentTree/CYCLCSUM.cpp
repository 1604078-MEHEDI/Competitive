///https://www.codechef.com/problems/CYCLCSUM
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


const int N = 1000001;
ll seg[4 * N][4], a[N];

void build(int idx, int s, int e)
{
  if (s == e) {
    seg[idx][0] = seg[idx][1] = seg[idx][2] = seg[idx][3] = a[s];
    return;
  }

  int mid = (s + e) / 2;
  int l = idx * 2 + 1;
  int r = idx * 2 + 2;
  build(l, s, mid);
  build(r, mid + 1, e);
  seg[idx][0] = max(seg[l][0], seg[r][0]);
  seg[idx][0] = max(seg[idx][0], seg[l][2] + seg[r][1]);
  seg[idx][1] = max(seg[l][1], seg[l][3] + seg[r][1]);
  seg[idx][2] = max(seg[r][2], seg[r][3] + seg[l][2]);
  seg[idx][3] = seg[l][3] + seg[r][3];
}

void query(int idx, int s, int e, int l, int r, ll res[4])
{
  if (s == l && e == r) {
    for (int i = 0; i < 4; i++) res[i] = seg[idx][i];
    return;
  }

  int mid = (s + e) / 2;
  int p = idx * 2 + 1;
  int q = idx * 2 + 2;
  if (r <= mid)query(p, s, mid, l, r, res);
  else if (l > mid)query(q, mid + 1, e, l, r, res);
  else {
    ll lft[4], rgt[4];
    query(p, s, mid, l, mid, lft);
    query(q, mid + 1, e, mid + 1, r, rgt);

    res[0] = max(lft[0], rgt[0]);
    res[0] = max(res[0], lft[2] + rgt[1]);
    res[1] = max(lft[1], lft[3] + rgt[1]);
    res[2] = max(rgt[2], rgt[3] + lft[2]);
    res[3] = lft[3] + rgt[3];
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
  int T;
  //scanf("%d", &T);
  T = 1;
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i + n] = a[i];
    }
    build(0, 1, 2 * n);
    ll res[4];
    for (int i = 1; i <= n; i++) {
      if (i > 1)cout << " ";
      query(0, 1, 2 * n, i, i + n - 1, res);
      cout << res[0];
    }
    if (cs < T)cout << endl;
  }
  return 0;
}
