/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
/*

Credit: tanmoy Datta
1. Make a graph from input data and Determine the SCC of the graph.
2. Make a new Graph from SCC. Consider Each SCC as a node of this graph.
3. If any Node of SCC_graph have more than 1 out degree and It is not possible to traverse all node from the SCC which contain’s the node 0 of the input graph then Print “NO”.
4. Otherwise Print “YES”;
*/

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
const int N = 1005;
using pii = pair<int, int>;
int n, m;
vector<int>g[N], rg[N], scc_g[N];
int scc;
bool ok;
int vis[N], node_no;
stack<int>st;
int scc_nm[N], node[N], scc_vis[N];


void init() {
	for (int i = 0; i < N; i++) {
		g[i].clear();
		rg[i].clear();
		vis[i]  = 0;
		scc_nm[i] = -1;
	}

	for (int i = 0; i <= scc + 1; i++) {
		scc_g[i].clear();
		scc_vis[i] = 0;
	}
	node_no = 0;
	scc = 0;
}



void dfs1(int u) {
	vis[u]++;
	for (auto &v : g[u]) {
		if (vis[v] == 1)continue;
		dfs1(v);
	}
	st.push(u);
}

void dfs2(int u) {
	vis[u]++;
	scc_nm[u] = scc;
	for (auto &v : rg[u]) {
		if (vis[v] == 2)continue;
		dfs2(v);
	}
}

void dfs3(int u) {
	scc_vis[u] = 1;
	if ((int)scc_g[u].size() > 1) {
		ok = false;
		return;
	}
	for (auto &v : scc_g[u]) {
		dfs3(v);
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
		memset(node, -1, sizeof node);
		node_no = 0;
		node[0] = node_no;

		si(n);
		init();
		for (int i = 0; i < n; i++) {
			si(m);
			while (m--) {
				int a, b;
				sii(a, b);
				if (node[a] == -1)node[a] = ++node_no;
				if (node[b] == -1)node[b] = ++node_no;
				g[node[a]].push_back(node[b]);
				rg[node[b]].push_back(node[a]);
			}
		}

		for (int i = 0; i <= node_no; i++)
			if (vis[i] == 0)dfs1(i);

		scc = 0;

		while (!st.empty()) {
			int v = st.top();
			st.pop();
			if (vis[v] != 2) {
				scc++;
				dfs2(v);
			}
		}

		for (int i = 0; i <= node_no; i++) {
			for (auto &v : g[i]) {
				if (scc_nm[i] != scc_nm[v])
					scc_g[scc_nm[i]].push_back(scc_nm[v]);
			}
		}
		ok = true;
		dfs3(scc_nm[0]);
		if (ok) {
			for (int i = 1; i <= scc; i++) {
				if (!scc_vis[i]) {
					ok = false;
					break;
				}
			}
		}
		printf("Case %d: ", cs);
		puts(ok ? "YES" : "NO");

	}
	return 0;
}
