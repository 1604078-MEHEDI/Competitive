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
const int N = 1000006;

struct node
{
	ll a, b, sm;
};

vector<node> sg;
ll k = 1;

void Push(ll x, ll y, ll k) {
	ll d = (x + y) / 2;
	sg[2 * k].b +=  sg[k].b;
	sg[2 * k].a += sg[k].a;
	sg[2 * k].sm += sg[k].b * (d - x) * (d - x + 1) / 2 + sg[k].a * (d - x + 1);
	sg[2 * k + 1].b += sg[k].b;
	ll A = sg[k].a + (d - x + 1) * sg[k].b;
	sg[2 * k + 1].a += A;
	sg[2 * k + 1].sm += sg[k].b * (y - d - 1) * (y - d) / 2 + A * (y - d);
	sg[k].a  = sg[k].b = 0;
}

void Add(ll l, ll r, ll k, ll x, ll y) {
	if (r < x || y < l)return;
	if (l <= x && y <= r) {
		ll A = x - l + 1;
		sg[k].b++;
		sg[k].a += A;
		sg[k].sm += (y - x) * (y - x + 1) / 2 + A * (y - x + 1);
		return;
	}
	Push(x, y, k);
	ll d = (x + y) / 2;
	Add(l, r, k * 2, x, d);
	Add(l, r, k * 2 + 1, d + 1, y);
	sg[k].sm = sg[2 * k].sm + sg[2 * k + 1].sm;
}

void Add(ll l, ll r) {
	Add(l, r, 1, 0, k - 1);
}

ll Sum(ll l, ll r, ll k, ll x , ll y) {
	if (r < x || y < l)return 0;
	if (l <= x && y <= r)return sg[k].sm;
	Push(x, y, k);
	ll d = (x + y) / 2;
	return Sum(l, r, 2 * k, x, d) + Sum(l, r, 2 * k + 1, d + 1, y);
}
ll Sum(ll l, ll r) {
	return Sum(l, r, 1, 0, k - 1);
}

int main()
{
	FASTIO
	/*
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
//*/
	ll n, q;
	cin >> n >> q;
	while (k < n)k *= 2;
	sg = vector<node>(2 * k);
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		sg[k + i].sm = x;
	}
	for (int i = k - 1; i > 0; i--)
		sg[i].sm = sg[2 * i].sm + sg[2 * i + 1].sm;
	while (q--) {
		ll typ;
		ll l, r;
		cin >> typ >> l >> r;
		--l;
		--r;
		if (typ == 1)Add(l, r);
		else cout << Sum(l, r) << "\n";
	}
	return 0;
}

/*
https://cses.fi/problemset/task/1736/

Polynomial Queries
Memory limit: 512 MB 
Your task is to maintain an array of n values and efficiently process the following types of queries:

1. Increase the first value in range [a,b]
   by 1, the second value by 2, the third value by 3, and so on.
2. Calculate the sum of values in range [a,b]
.
5 3
4 2 3 1 7
2 1 5
1 1 5
2 1 5

output: 
17
32

*/
