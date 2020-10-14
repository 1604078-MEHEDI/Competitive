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

const int N = 100010;

struct Point
{
  int x, y;
  Point() {x = y = 0;}

  Point(int _x, int _y): x(_x), y(_y) {}

  bool operator *(Point b) {
    return ((ll)x * b.y - (ll)b.x * y) <= 0;
  }

  bool operator < (Point b) const {
    return b * *this;
  }

  Point operator - (Point b) {
    return Point(x - b.x, y - b.y);
  }
};

vector<Point> lh[4 * N];
vector<Point> pts;

void build(int v, int l, int r)
{
  if (r - l == 1) {
    lh[v].push_back(pts[l]);
    return;
  }

  int m = (l + r) / 2;
  build(2 * v, l, m);
  build(2 * v + 1, m, r);
  lh[v] = lh[2 * v];
  for (int i = 0; i < (int)lh[2 * v + 1].size(); i++) {
    while (lh[v].size() > 1 &&
           ((lh[2 * v + 1][i] - lh[v][lh[v].size() - 2]) *
            (lh[v][lh[v].size() - 1] - lh[v][lh[v].size() - 2])))
      lh[v].pop_back();
    lh[v].push_back(lh[2 * v + 1][i]);
  }
}

bool ok(int v, int fv, int ev, int l, int r, Point a, Point b)
{
  if (fv >= r || l >= ev) return false;
  if (fv >= l && ev <= r) {
    int f = 0, e = lh[v].size();
    while (f < e) {
      int m = (f + e) / 2;
      if ((a - b) * (lh[v][m] - b)) {
        return true;
      }
      if (m == 0 || lh[v][m] - lh[v][m - 1] < a - b)
        f = m + 1;
      else e = m;
    }
    return false;
  }
  int m = (fv + ev) / 2;
  return ok(2 * v, fv, m, l, r, a, b) || ok(2 * v + 1, m, ev, l, r, a, b);
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
  int k, m;
  cin >> k >> m;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    pts.push_back(Point(x, y));
  }
  sort(pts.begin(), pts.end());
  build(1, 0, k);
  for (int i = 0; i < m; i++) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Point a(x1, y1), b(x2, y2);
    if (b < a) swap(a, b);

    int r = upper_bound(pts.begin(), pts.end(), b) - pts.begin();
    int l = lower_bound(pts.begin(), pts.end(), a) - pts.begin();

    if (ok(1, 0, k, l, r, a, b))
      cout << "Y\n";
    else cout << "N\n";
  }
}
