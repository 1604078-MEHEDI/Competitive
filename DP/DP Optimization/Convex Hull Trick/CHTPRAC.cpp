/*Ø¨Ù�Ø³Ù�Ù�Ù� Ø§Ù�Ù�Ù�Ù�Ù�Ù� Ø§Ù�Ø±Ù�Ù�Ø­Ù�Ù�Ù�Ù�Ù� Ø§Ù�Ø±Ù�Ù�Ø­Ù�Ù�Ù�*/

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
// find_by_order(k) â�� à¦«à¦¾à¦�à¦¶à¦¨à¦�à¦¿ kth ordered element à¦�à¦° à¦�à¦�à¦�à¦¾ à¦ªà§�à§�à¦¨à§�à¦�à¦¾à¦° à¦°à¦¿à¦�à¦¾à¦°à§�à¦¨ à¦�à¦°à§�à¥¤ à¦�à¦°à§�à¦¥à¦¾à§� à¦¤à§�à¦®à¦¿ à¦�à¦¾à¦�à¦²à§�à¦� kth à¦�à¦¨à§�à¦¡à§�à¦�à§�à¦¸à§� à¦�à¦¿ à¦�à¦�à§�, à¦¸à§�à¦�à¦¾ à¦�à§�à¦¨à§� à¦«à§�à¦²à¦¤à§� à¦ªà¦¾à¦°à¦�à§�!
// order_of_key(x) â�� à¦«à¦¾à¦�à¦¶à¦¨à¦�à¦¿ x à¦�à¦²à¦¿à¦®à§�à¦¨à§�à¦�à¦�à¦¾ à¦�à§�à¦¨ à¦ªà¦�à¦¿à¦¶à¦¨à§� à¦�à¦�à§� à¦¸à§�à¦�à¦¾ à¦¬à¦²à§� à¦¦à§�à§�à¥¤
//*//**___________________________________________________**/
const int N = 1000006;

struct ConvexHullTricks
{
	vector<ll> m, c;
	bool decSlope, askMin;

	ConvexHullTricks(bool slopeType, bool QueryType) {
		decSlope = slopeType;
		askMin = QueryType;
	}

	bool throwline(ll l1, ll l2, ll l3) {
		if (decSlope) {
			if (askMin)
				return (c[l2] - c[l1]) * (m[l1] - m[l3]) >= (c[l3] - c[l1]) * (m[l1] - m[l2]);
			else
				return (c[l2] - c[l1]) * (m[l1] - m[l3]) <= (c[l3] - c[l1]) * (m[l1] - m[l2]);
		}
		else {
			if (!askMin)
				return (c[l2] - c[l1]) * (m[l1] - m[l3]) >= (c[l3] - c[l1]) * (m[l1] - m[l2]);
			else
				return (c[l2] - c[l1]) * (m[l1] - m[l3]) <= (c[l3] - c[l1]) * (m[l1] - m[l2]);
		}
		//return 0;
	}

	void add(ll M, ll C) {
		//dbg(M,C);
		m.push_back(M);
		c.push_back(C);
		ll sz = m.size();
		while (sz >= 3 && throwline(sz - 3, sz - 2, sz - 1)) {
			//dbg(sz);
			m.erase(m.end() - 2);
			c.erase(c.end() - 2);
			sz--;
		}
	}

	ll f(ll i, ll x) {
		return m[i] * x + c[i];
	}

	ll Query(ll x) {
		ll l = 0, r = m.size() - 1, ret;
		if (askMin)ret = 1e18;
		else ret = -1e18;

		while (l <= r) {
			//dbg(l,r);
			ll m1 = l + (r - l) / 3;
			ll m2 = r - (r - l) / 3;
			if (f(m1, x) == f(m2, x)) {
				ret = f(m1, x);
				r = m2 - 1;
				l = m1 + 1;
			}
			else if (f(m1, x) < f(m2, x)) {
				if (askMin) {
					ret = f(m1, x);
					r = m2 - 1;
				}
				else {
					ret = f(m2, x);
					l = m1 + 1;
				}
			}
			else {
				if (askMin) {
					ret = f(m2, x);
					l = m1 + 1;
				}
				else {
					ret = f(m1, x);
					r = m2 - 1;
				}
			}
		}
		return ret;
	}
};


///https://www.spoj.com/problems/CHTPRAC/

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
	ll Q, type;
	cin >> Q >> type;
	ll s, q;
	if (type <= 2) s = 1;//dec slope
	else s = 0;
	if (type % 2)q = 1;///mini
	else q = 0;
	ConvexHullTricks CHT(s, q);
	while (Q--) {
		ll t;
		cin >> t;
		//dbg(t);
		if (t == 1) {
			ll M, C;
			cin >> M >> C;
			//dbg(m,c);
			CHT.add(M, C);
			//dbg(m,c);
		}
		else {
			ll x;
			cin >> x;
			//dbg(x);
			cout << CHT.Query(x) << "\n";
		}
	}
	return 0;
}
