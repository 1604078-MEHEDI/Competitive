
///https://www.spoj.com/problems/QTREE5/
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
const int N = 1e5 + 5;
const int inf = 1e9 + 7;
struct CentroidDecomposition
{
	vector<int> g[N];
	int subsize[N], par[N];

	void dfs(int cur, int p)
	{
		subsize[cur] = 1;
		for (auto v : g[cur]) {
			if (v != p && par[v] == -1) {
				dfs(v, cur);
				subsize[cur] += subsize[v];
			}
		}
	}

	void Centroid_decomposition(int cur, int p, int n, int prev)
	{
		for (auto v : g[cur]) {
			if (v != p && par[v] == -1 && 2 * subsize[v] > n) {
				Centroid_decomposition(v, cur, n, prev);
				return;
			}
		}

		par[cur] = prev;

		for (auto v : g[cur]) {
			if (par[v] == -1) {
				dfs(v, -1);
				Centroid_decomposition(v, cur, subsize[v], cur);
			}
		}
	}

	void init(int v) {
		memset(par, -1, sizeof par);
		dfs(v, -1);
		Centroid_decomposition(v, -1, subsize[v], -2);
	}
} CD;

struct node
{
	int pos, dist;
	node(int _pos, int _dist):
		pos(_pos), dist(_dist) {}

	bool operator < (node X)const {
		return dist > X.dist;
	}
};

int dp[17][N], l[N], r[N], h[N], cnt;

void dfs(int cur, int par, int curh)
{
	dp[0][cur] = par;
	h[cur] = curh;
	l[cur] = cnt++;

	for (int i = 1; i < 17; i++)
		dp[i][cur] = dp[i - 1][dp[i - 1][cur]];

	for (auto v : CD.g[cur]) {
		if (v != par) dfs(v, cur, curh + 1);
	}
	r[cur] = cnt++;
}

inline bool is_ancestor(int u, int v)
{
	return l[u] <= l[v] && r[u] >= r[v];
}

int lca(int u, int v)
{
	if (is_ancestor(u, v)) return u;
	if (is_ancestor(v, u)) return v;

	for (int i = 16; i >= 0; i--)
		if (!is_ancestor(dp[i][u], v))
			u = dp[i][u];
	return dp[0][u];
}

int dist(int u, int v)
{
	return h[u] + h[v] - 2 * h[lca(u, v)];
}

priority_queue<node> Q[N];
bool white[N];

int distW(int x)
{
	priority_queue<node> &PQ = Q[x];

	while (!PQ.empty()) {
		node cur = PQ.top();
		if (!white[cur.pos]) PQ.pop();
		else return cur.dist;
	}
	return inf;
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
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		CD.g[u].push_back(v);
		CD.g[v].push_back(u);
	}

	CD.init(1);
	dfs(1, 1, 0);

	int q;
	scanf("%d", &q);
	//dbg(q);
	while (q--) {
		int t, x;
		scanf("%d %d", &t, &x);
		//dbg(t, x);
		if (t == 0) {
			white[x] = !white[x];
			if (white[x]) {
				int cur = x;
				while (cur != -2) {
					Q[cur].push(node(x, dist(x, cur)));
					cur = CD.par[cur];
				}
			}
		}
		else {
			int ans = inf;
			int cur = x;
			while (cur != -2) {
				ans = min(ans, dist(x, cur) + distW(cur));
				cur = CD.par[cur];
			}
			if (ans == inf) ans = -1;
			printf("%d\n", ans);
		}
	}
}
