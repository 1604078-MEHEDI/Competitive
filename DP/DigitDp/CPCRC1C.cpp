
///https://www.spoj.com/problems/CPCRC1C/
///https://massivealgorithms.blogspot.com/2018/12/cpcrc1c-sum-of-digits.html
///http://gautamdp.blogspot.com/2016/04/cpcrc1c-sum-of-digits.html
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

ll dp[20][180][2];

void getDigits(ll x, vector<ll> &v)
{
  while (x) {
    v.push_back(x % 10);
    x /= 10;
  }
}

ll go(ll pos, ll sum, ll tight, vector<ll> &digit)
{
  if (pos == -1) return sum;

  ll &ret = dp[pos][sum][tight];
  if (ret != -1) return ret;

  ret = 0;
  ll k = (tight) ? digit[pos] : 9;

  for (ll i =  0; i <= k; i++) {

    ll newTight = (digit[pos] == i) ? tight : 0;

    ret += go(pos - 1, sum + i, newTight, digit);
  }
  // if (!tight) return ret;
  return ret;
}

ll solve(ll a, ll b)
{
  memset(dp, -1, sizeof dp);

  vector<ll> A;
  getDigits(a - 1, A);

  ll l = go((ll)A.size() - 1, 0, 1, A);

  memset(dp, -1, sizeof dp);

  vector<ll> B;
  getDigits(b, B);

  ll r  = go((ll)B.size() - 1, 0, 1, B);

  return (r - l);
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

  while (1) {
    ll a, b;
    cin >> a >> b;
    if (a == -1 && b == -1)break;
    cout << solve(a, b) << endl;
  }

}



//const int N = 1006;
// int digits[N];
// ll dp[11][100][2];




// ll go(int pos, int n, ll sm, bool flag) {

// 	if (pos > n) return sm;
// //	dbg(digits[pos]);
// 	ll &ret = dp[pos][sm][flag];
// 	if (~ret) return ret;
// 	int limit = (flag) ? digits[pos] : 9;
// 	ll res = 0;
// 	for (int i = 0; i <= limit; i++) {
// 		res += go(pos + 1, n, sm + i, flag && (i == limit));
// 	}
// 	return ret = res;
// }

// int DigitSum(string s) {
// 	int ret = 0;
// 	for (auto &ch : s)
// 		ret += (ch - '0');
// 	return ret;
// }

// int main()
// {
// 	FASTIO
// 	///*
// #ifndef ONLINE_JUDGE
// 	freopen("in.txt", "r", stdin);
// 	freopen("out.txt", "w", stdout);
// 	freopen("error.txt", "w", stderr);
// #endif
// //*/
// 	int T;
// 	T = 100000;
// 	//scanf("%d", &T);
// 	string a, b;
// 	for (int cs = 1; cs <= T; cs++) {
// 		cin >> a >> b;
// 		//dbg(a,b);
// 		if (a == "-1")break;
// 		for (int i = 0; i < (int)a.size(); i++)
// 			digits[i + 1] = a[i] - '0';
// 		// for (int i = 1; i <= (int)a.size(); i++)
// 		// 	dbg(digits[i]);
// 		memset(dp, -1, sizeof dp);
// 		ll l = go(1, a.size(), 0, 1);
// 		// dbg(l);
// 		for (int i = 0; i < (int)b.size(); i++)
// 			digits[i + 1] = b[i] - '0';


// 		// for (int i = 1; i <= (int)b.size(); i++)
// 		// 	dbg(digits[i]);


// 		memset(dp, -1, sizeof dp);
// 		ll r = go(1, b.size(), 0, 1);
// 		// dbg(r);
// 		//dbg(DigitSum(a));
// 		ll ans = r - l + DigitSum(a);
// 		cout << ans << "\n";
// 	}
// 	return 0;
// }


