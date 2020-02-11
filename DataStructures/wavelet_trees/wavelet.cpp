//https://ideone.com/GN4A4V

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

const int N = 3e6;
const int M = 1e6;

vector<int> g[N];
int a[N];

struct wavelet_tree
{
  int lo, hi;
  wavelet_tree *l, *r;

  vector<int> b;
  vector<int> c;// c holds the prefix sum of elements

  // nos are in range [x,y]
  // array indices ar [from, to]

  wavelet_tree(int *from, int *to, int x, int y)
  {
    lo = x;
    hi = y;

    if (from >= to) return;
    if (hi == lo) {
      b.reserve(to - from + 1);
      b.push_back(0);
      c.push_back(to - from + 1);
      c.push_back(0);
      for (auto it = from; it != to; it++) {
        b.push_back(b.back() + 1);
        c.push_back(c.back() + *it);
      }
      return;
    }

    int mid = (lo + hi) / 2;
    auto f = [mid](int x) {
      return x <= mid;
    };

    b.reserve(to - from + 1);
    b.push_back(0);
    c.reserve(to - from + 1);
    c.push_back(0);

    for (auto it = from; it != to; it++) {
      b.push_back(b.back() + f(*it));
      c.push_back(c.back() + *it);
    }
    // see how lamda function is used here
    auto pivot  = stable_partition(from, to, f);
    l = new wavelet_tree(from, pivot, lo, mid);
    r = new wavelet_tree(pivot, to, mid + 1, hi);
  }

  // swap a[i] with a[i+1]  , if a[i]!=a[i+1] call swapadjacent(i)
  void swapadjacent(int i)
  {
    if (lo == hi)
      return ;
    b[i] = b[i - 1] + b[i + 1] - b[i];
    c[i] = c[i - 1] + c[i + 1] - c[i];
    if ( b[i + 1] - b[i] == b[i] - b[i - 1])
    {
      if (b[i] - b[i - 1])
        return this->l->swapadjacent(b[i]);
      else
        return this->r->swapadjacent(i - b[i]);
    }
    else
      return ;
  }

  //kth smallest element in [l, r]
  int kth(int l, int r, int k)
  {
    if (l > r) return 0;
    if (lo == hi) return lo;
    int inleft = b[r] - b[l - 1];
    int lb = b[l - 1];//amt of nos in first (l-1) nos that go in left
    int rb = b[r]; //amt of nos in first (r) nos that go in left
    if (k <= inleft) return this->l->kth(lb + 1, rb, k);
    return this->r->kth(l - lb, r - rb, k - inleft);
  }

  //count of nos in [l,r] less than or equal to k
  int LTE(int l, int r, int k)
  {
    if (l > r or k < lo) return 0;
    if (hi <= k) return r - l + 1;
    int lb = b[l - 1];
    int rb = b[r];
    return this->l->LTE(lb + 1, rb, k) + this->r->LTE(l - lb, r - rb, k);
  }

  // count of nos in [l,r] equal to k
  int count(int l, int r, int k)
  {
    if (l > r or k < lo or k > hi) return 0;
    if (lo == hi) return r - l + 1;
    int lb = b[l - 1];
    int rb = b[r];
    int mid = (lo + hi) / 2;
    if (k <= mid) return this->l->count(lb + 1, rb, k);
    return this->r->count(l - lb, r - rb, k);
  }

  // sum of nos in [l,r] less than or eqaul to k
  int sumk(int l, int r, int k)
  {
    if (l > r or k < lo) return 0;
    if (hi <= k) return c[r] - c[l - 1];
    int lb = b[l - 1];
    int rb = b[r];
    return this->l->sumk(lb + 1, rb, k) + this->r->sumk(l - lb, r - rb, k);
  }

  ~wavelet_tree() {
    delete l;
    delete r;
  }
};


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
  for (int i = 1; i <= n; i++) cin >> a[i];

  wavelet_tree T(a + 1, a + n + 1, 1, M);
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    int l, r, k;
    cin >> l >> r >> k;
    if (x == 0) { // kth smallest
      cout << "Kth smallest: ";
      cout << T.kth(l, r, k) << endl;
    }
    else if (x == 1) { // lss than or equal to k
      cout << "LTE: ";
      cout << T.LTE(l, r, k) << endl;
    }
    else if (x == 2) { // count occurence of K in [l, r]
      cout << "Occurence of K: ";
      cout << T.count(l, r, k) << endl;
    }
    else if (x == 3) {//sum of elements less than or equal to K in [l, r]
      cout << "Sum: ";
      cout << T.sumk(l, r, k) << endl;
    }
  }
  return 0;
}
