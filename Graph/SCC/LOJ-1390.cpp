/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/
#include <bits/stdc++.h>
using namespace std;
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


/* for Random Number generate
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
*/
/**
template < typename F, typename S >ostream& operator << ( ostream& os, const pair< F, S > & p ) {return os << "(" << p.first << ", " << p.second << ")";}
template < typename T >ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{";for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", ";os << *it;}return os << "}";}
template < typename T >ostream &operator << ( ostream & os, const set< T > &v ) {os << "[";for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin()) os << ", ";os << *it;}return os << "]";}
template < typename F, typename S >ostream &operator << ( ostream & os, const map< F, S > &v ) {os << "[";for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", ";os << it -> first << " = " << it -> second ;}return os << "]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
void faltu () { cerr << endl; }
template <typename T>void faltu( T a[], int n ) {for (int i = 0; i < n; ++i) cerr << a[i] << ' ';cerr << endl;}
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
const int N = 5005;
const int M = N / 32 + 4;

int isPossible[N][M];
int n, m, sz;

using pii = pair<int, int>;
vector<pii>ans;

int topSortoprder[N], idx, in[N];
vector<int> g[N];

void init() {
	for (int i = 0; i <= n; i++) {
		g[i].clear();
		in[i] = 0;
	}
	ans.clear();
}

void TopSort() {
	int h = 0, t = 0;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0)topSortoprder[t++] = i;
	}

	while (h < t) {
		int u = topSortoprder[h++];
		for (auto &v : g[u]) {
			in[v]--;
			if (in[v])continue;
			topSortoprder[t++] = v;
		}
	}
}

void go() {
	for (int i = n - 1; i >= 0; i--) {
		int u = topSortoprder[i];
		for (int j = 0; j < sz; j++)isPossible[u][j] = 0;
		for (auto &v : g[u]) {
			for (int k = 0; k < sz; k++)
				isPossible[u][k] |= isPossible[v][k];
		}
		for (auto &v : g[u]) {
			if (isPossible[u][v / 32] & (1 << (v % 32)))continue;
			isPossible[u][v / 32] |= (1 << (v % 32));
			ans.push_back({u, v});
		}
	}
	sort(ans.begin(), ans.end());
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
		sii(n, m);
		//dbg(n,m);
		sz = ((n + 32) / 32);
		//dbg(sz);
		init();
		for (int i = 0; i < m; i++) {
			int a, b;
			sii(a, b);
			g[a].push_back(b);
			in[b]++;
		}
		TopSort();
		go();
		printf("Case %d: %d\n", cs, (int)ans.size());
		for (auto &x : ans) {
			printf("%d %d\n", x.first, x.second);
		}
	}
	return 0;
}
