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

/*

                   Range Updates and Sums:
                   -----------------------


https://cses.fi/problemset/task/1735/
Your task is to maintain an array of n values and efficiently process the following types of queries:
1. Increase each value in range [a,b] by x.
2. Set each value in range [a,b] to x.
3. Calculate the sum of values in range [a,b].

6 5
2 3 1 1 5 3
3 3 5
1 2 4 2
3 3 5
2 2 4 5
3 3 5

7
11
15
*/

const int N = 200006;

ll sg[4 * N];
ll Add[4 * N], Set[4 * N];
ll a[N];
int n, q;
void build(int v, int l, int r) {
	if (l == r) {
		sg[v] = a[l];
		return;
	}
	int m = l + (r - l) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m + 1, r);
	sg[v] = sg[v * 2 + 1] + sg[v * 2 + 2];
}

void Push(int v, int l, int r) {
	if (Set[v] != 0) {
		sg[v] = Set[v] * (r - l + 1);
		if (l != r) {
			Set[2 * v + 1] = Set[2 * v + 2] = Set[v];
			Add[2 * v + 1] = Add[2 * v + 2] = 0;
		}
		Set[v] = 0;
	}
	if (Add[v] != 0) {
		sg[v] += Add[v] * (r - l + 1);
		if (l != r) {
			Add[2 * v + 1] += Add[v];
			Add[2 * v + 2] += Add[v];
		}
		Add[v] = 0;
	}
}

ll Query(int v, int l, int r, int i, int j) {
	Push(v, l, r);
	if (j < l || r < i)return 0;
	if (i <= l && r <= j) return sg[v];
	int m = l + (r - l) / 2;
	ll Ql = Query(2 * v + 1, l, m, i, j);
	ll Qr = Query(2 * v + 2, m + 1, r, i, j);
	return Ql + Qr;
}

void modify(int v, int l, int r, int i, int j, int SET, int ADD) {
	Push(v, l, r);
	if (j < l || r < i)return;
	if (i <= l && r <= j) {
		if (SET != 0)Set[v] = SET;
		if (ADD != 0)Add[v] = ADD;
		Push(v, l, r);
		return;
	}

	int m = l + (r - l) / 2;
	modify(v * 2 + 1, l, m, i, j, SET, ADD);
	modify(v * 2 + 2, m + 1, r, i, j, SET, ADD);
	sg[v] = sg[v * 2 + 1] + sg[v * 2 + 2];
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
	cin >> n >> q;
	for (int i = 0; i < n; i++)cin >> a[i];

	build(0, 0, n - 1);

	while (q--) {
		int c, a, b, x;
		cin >> c >> a >> b;
		if (c == 1) {
			cin >> x;
			modify(0, 0, n - 1, a - 1, b - 1, 0, x);
		}
		else if (c == 2) {
			cin >> x;
			modify(0, 0, n - 1, a - 1, b - 1, x, 0);
		}
		else
			cout << Query(0, 0, n - 1, a - 1, b - 1) << "\n";
	}
	return 0;
}
