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
const int N = 200006;
const int M = 2e2 + 2;


struct data {
	int l, r, idx;

	data () {};
	data (int l, int r, int idx) : l (l), r (r), idx (idx) {}

	bool operator < (const data &rhs) const {
		if (l == rhs.l) return r > rhs.r;
		return l > rhs.l;
	}
};

int n, m, q, a[N];
pii edge[N];
data Q[N];


// DSU
int P[M][N];
inline int Find (int idx, int u) {
	if (P[idx][u] == u) return u;
	return P[idx][u] = Find (idx, P[idx][u]);
}

void Union (int idx, int u, int v) {
	int till = idx / 1000;
	for (int i = 0; i <= till; ++i) {
		int _u = Find (i, u);
		int _v = Find (i, v);
		if (_u == _v) continue;
		if (rand () & 1)
			swap (_u, _v);
		P[i][_v] = _u;
	}
}



vector<pii> con;
int _Find(int idx, int u) {
	con.push_back(make_pair(u, P[idx][u]));
	if (P[idx][u] == u)return u;
	return P[idx][u] = _Find(idx, P[idx][u]);
}



// bit
int bit [N];
void Add (int idx) { for (++idx; idx <= m; idx += idx & -idx) bit [idx] += 1; }
void Del (int idx) { for (++idx; idx <= m; idx += idx & -idx) bit [idx] -= 1; }
int get (int idx) {
	int sum = 0;
	for (++idx; idx; idx -= idx & -idx)
		sum += bit [idx];
	return sum;
}

void  merge(int idx, int u, int v) {
	u = _Find(idx, u);
	v = _Find(idx, v);
	if (u == v)return;
	con.push_back(make_pair(u, v));
	P[idx][v] = u;
}

int get(int idx, int u, int v) {
	if (u == v)return idx;
	con.clear();
	int ret = -1;
	int till = (idx - 1) / 1000;
	for (int i = till; ~i; --i) {
		if (Find(i, u) == Find(i, v)) {
			int from = min(idx, (i + 1) * 1000) - 1;
			int to = i * 1000;

			for (int j = from; j >= to; --j) {
				Find(i + 1, edge[j].first);
				Find(i + 1, edge[j].second);
			}

			for (int j = from; j >= to; --j) {
				int _u = edge[j].first;
				int _v = edge[j].second;
				if (_u == _v)continue;

				merge(i + 1, _u, _v);

				if (_Find (i + 1, u) == _Find (i + 1, v)) {
					ret = j;
					if (!con.empty ()) {
						int k = con.size () - 1;
						for (; ~k; --k)
							P [i + 1][con [k].first] = con [k].second;
					}
					break;
				}
			}
			break;
		}
	}
	return ret;
}


int ans[N];
set<pii> st;

void misir() {
	sort(Q, Q + q);
	int tot = 0;
	for (int i = m - 1; ~i; --i) {
		Add(i);
		st.insert(make_pair(a[i], i));

		while (!st.empty()) {
			auto it = st.end();
			--it;
			if (i == it->first) {
				Del(it->second);
				st.erase(it);
			}
			else break;
		}
		while (tot < q && Q[tot].l == i) {
			ans[Q[tot].idx] = n - get(Q[tot].r);
			++tot;
		}
	}
}


void init() {
	st.clear();
	memset(bit, 0, sizeof bit);
	for (int i = 0; i < M; i++)
		for (int j = 0; j < n; j++)
			P[i][j] = j;
}
//Number_of_Connected_Components_on_Segments.cpp
///https://www.codechef.com/problems/GERALD07
//https://discuss.codechef.com/t/gerald07-editorial/4849
///https://codeforces.com/edu/course/2/lesson/7/3/practice/contest/289392/problem/B
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
	int T;
	T = 1;
	//scanf("%d", &T);
	//cin >> T;
	for (int cs = 1; cs <= T; cs++) {
		cin >> n >> m;
		init();

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			edge[i] = make_pair(--u, --v);
			a[i] = get(i, u, v);
			Union(i, u, v);
		}

		cin >> q;

		for (int i = 0; i < q; i++) {
			int l, r;
			cin >> l >> r;
			Q[i] = data(l - 1, r - 1, i);
		}
		misir();
		for (int i = 0; i < q; i++)
			cout << ans[i] << "\n";
	}
	return 0;
}
