
//https://www.spoj.com/problems/CNTPRIME/
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

const int N = 1e6 + 6;
int a[N];
int Tree[4 * N];
int lazy[4 * N];
int vis[N];

void SV()
{
	vis[0] = vis[1] = 1;
	int lmt = sqrt(N * 1.0) + 2;

	for (int i = 4; i < N; i += 2)vis[i] = 1;

	for (int i = 3; i < N; i += 2) {
		if (!vis[i]) {
			if (i <= lmt) {
				for (int j = i * i; j < N; j += i) {
					vis[j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) vis[i] = (1 - vis[i]);
}

void build(int node, int l, int r)
{
	if (l == r) {
		Tree[node] = vis[a[l]];
		return;
	}
	int m = (l + r) >> 1;

	int lft = node << 1;
	int rgt = lft + 1;
	build(lft, l, m);
	build(rgt, m + 1, r);
	Tree[node] = Tree[lft] + Tree[rgt];
}

void update(int node, int l, int r, int x, int y, int v)
{
	int m = (l + r) >> 1;

	int lft = node << 1;
	int rgt = lft + 1;

	if (lazy[node] > 1) {
		lazy[lft] = lazy[rgt] = lazy[node];
		Tree[node] = (r - l + 1) * vis[lazy[node]];
		lazy[node] = 0;
	}

	if (y < l || r < x) return;
	if (x <= l && r <= y) {
		Tree[node] = (r - l + 1) * vis[v];
		lazy[lft] = lazy[rgt] = v;
		return;
	}

	update(lft, l, m, x, y, v);
	update(rgt, m + 1, r, x, y, v);
	Tree[node] = Tree[lft] + Tree[rgt];
}

int query(int node, int l, int r, int x, int y)
{
	int m = (l + r) >> 1;

	int lft = node << 1;
	int rgt = lft + 1;

	if (lazy[node] > 1) {
		lazy[lft] = lazy[rgt] = lazy[node];
		Tree[node] = (r - l + 1) * vis[lazy[node]];
		lazy[node] = 0;
	}

	if (y < l || r < x) return 0;
	if (x <= l && r <= y) {
		return Tree[node];
	}

	int P = query(lft, l, m, x, y);
	int Q = query(rgt, m + 1, r, x, y);
	return P + Q;
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
	SV();
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		memset(lazy, 0, sizeof lazy);

		int n, q;
		scanf("%d %d", &n, &q);
		for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
		build(1, 1, n);
		printf("Case %d:\n", cs);

		while (q--) {
			int t;
			scanf("%d", &t);
			if (t == 1) {
				int x, y;
				scanf("%d %d", &x, &y);
				printf("%d\n", query(1, 1, n, x, y));
			}
			else {
				int x, y, v;
				scanf("%d%d%d", &x, &y, &v);
				update(1, 1, n, x, y, v);
			}
		}
	}
	return 0;
}
