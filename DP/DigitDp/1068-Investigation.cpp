///https://www.hackerrank.com/topics/digit-dp
///http://www.lightoj.com/volume_showproblem.php?problem=1068
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


/**
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

string toString(ll n)
{
  string s;
  while (n != 0) {
    s += (n % 10) + '0';
    n /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}

ll dp[15][2][99][99]; // dp[index][smaller][remainder]
ll k;
string s;

ll dp_solve(string &s, int idx, bool smaller, int rem, int val)
{
  if (idx == (int)s.length()) {
    if (rem == 0 && val == 0) return 1;
    return 0;
  }

  ll &ret = dp[idx][smaller][rem][val];
  if (ret != -1) return ret;
  else {
    ret = 0;
    int lmt = 9;
    if (smaller) lmt = s[idx] - '0';
    for (int i = 0; i <= lmt; i++) {
      bool flag;
      if (i < (s[idx] - '0')) flag = false;
      else flag = smaller;
      ret +=  dp_solve(s, idx + 1, flag, (rem + i) % k, (val * 10 + i) % k);
    }
    return ret;
  }
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

  int T;
  scanf("%d", &T);
  for (int cs = 1; cs <= T; cs++) {
    int a, b; //Find numbers between A and B whose sum of digits is divisible by K
    cin >> a >> b >> k;
    printf("Case %d: ", cs);

    //If A and B are ints, then the sum of the digits can't be greater than 82
    if (k > 90)
    {
      puts("0");
      continue;
    }

    string x = toString(a - 1);
    string y = toString(b);
    memset(dp, -1, sizeof dp);
    ll l = dp_solve(x, 0, 1, 0, 0); // solving for a-1

    memset(dp, -1, sizeof dp);
    ll r = dp_solve(y, 0, 1, 0, 0); // solving for a-1
    printf("%lld\n", (r - l));
    //cout << r - l << endl;
  }
  return 0;
}
