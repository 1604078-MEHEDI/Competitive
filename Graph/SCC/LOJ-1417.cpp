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
const int N = 50005;
int n, dfsnum, dis[N];
vector<int>g[N], rg[N];
int vis[N];

void init() {
	for (int i = 0; i <= n; i++) {
		g[i].clear();
		rg[i].clear();
		dis[i] = 0;
		vis[i] = 0;
	}
}

void dfs1(int u) {
	vis[u] = 1;
	dfsnum++;
	for (auto &v : g[u]) {
		if (vis[v])continue;
		dfs1(v);
	}
	dis[u] = ++dfsnum;
}

void dfs2(int u) {
	vis[u] = 2;
	for (auto &v : rg[u]) {
		if (vis[v] == 2)continue;
		dfs2(v);
	}
}


void dfs3(int u) {
	vis[u] = 3;
	dfsnum++;
	for (auto &v : g[u]) {
		if (vis[v] == 3)continue;
		dfs3(v);
	}
}

void dfs4(int u) {
	vis[u] = 4;
	for (auto &v : g[u]) {
		if (vis[v] == 3)
			dfs4(v);
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
		si(n);
		init();
		int a, b;
		for (int i = 1; i <= n; i++) {
			sii(a, b);
			g[a].push_back(b);
			rg[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i])dfs1(i);
		}

		vector<pair<int, int>>top_sort;
		for (int i = 1; i <= n; i++) {
			top_sort.push_back({dis[i], i});
		}

		sort(top_sort.rbegin(), top_sort.rend());

		vector<int> scc;
		for (auto it : top_sort) {
			int v = it.second;
			if (vis[v] != 2) {
				scc.push_back(v);
				dfs2(v);
			}
		}

		top_sort.clear();
		for (auto v : scc) {
			if (vis[v] != 3) {
				dfsnum = 0;
				dfs3(v);
				top_sort.push_back({dfsnum, v});
				dfs4(v);// this DFS is clearing
			}
		}

		sort(top_sort.rbegin(), top_sort.rend());

		printf("Case %d: ", cs);
		if ((int)top_sort.size() == 1)
			printf("%d\n", top_sort[0].second);
		else {
			auto x = top_sort[0];
			for (auto &y : top_sort) {
				if (x.first != y.first) {
					printf("%d\n", x.second);
					break;
				}
				x = y;
			}
		}
	}
	return 0;
}
