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

struct data
{
	int z, o, zo, oz;
};
data tr[4 * N];
bool lz[4 * N];
string s;

data Zero = {0, 0, 0, 0};

///1. Merge left and right
data Combine(const data &left, const data& right) {
	data ans;
	ans.o = left.o + right.o;
	ans.z = left.z + right.z;
	ans.zo = max(left.zo + right.o, left.z + right.zo);
	ans.oz = max(left.oz + right.z, left.o + right.oz);
	return ans;
}

///2.Push lazy down and merge lazy
void propagte(int u, int st, int en) {
	if (!lz[u])return;
	swap(tr[u].o, tr[u].z);
	swap(tr[u].oz, tr[u].zo);
	if (st != en) {
		lz[2 * u] ^= 1;
		lz[2 * u + 1] ^= 1;
	}
	lz[u] = 0;
}

void build(int u, int st, int en) {
	if (st == en) {
		if (s[st] == '0')tr[u] = {1, 0, 1, 1};
		else tr[u] = {0, 1, 1, 1};
		lz[u] = 0;
	}
	else {
		int mid = (st + en) / 2;
		build(2 * u, st, mid);
		build(2 * u + 1, mid + 1, en);
		tr[u] = Combine(tr[2 * u], tr[2 * u + 1]);
		lz[u] = 0; // 3. initialize
	}
}

void update(int u, int st, int en, int l, int r) {
	propagte(u, st, en);
	if (r < st || en < l)return;
	else if (l <= st && en <= r) {
		lz[u] ^= 1; /// 4. Merge lazy
		propagte(u, st, en);
	}
	else {
		int mid = (st + en) / 2;
		update(2 * u, st, mid, l, r);
		update(2 * u + 1, mid + 1, en, l, r);
		tr[u] = Combine(tr[2 * u], tr[2 * u + 1]);
	}
}

data query(int u, int st, int en, int l, int r) {
	propagte(u, st, en);
	if (r < st || en < l)return Zero;
	else if (l <= st && en <= r)return tr[u];
	else {
		int mid = (st + en) / 2;
		return Combine(query(2 * u, st, mid, l, r),
		               query(2 * u + 1, mid + 1, en, l, r));
	}
}

// void debug(int u, int st, int en) {
// //    cout<<"--->"<<u<<" "<<st<<" "<<en<<" "<<tr[u].<<" "<<lz[u]<<endl;
//     if (st==en) return;
//     int mid = (st+en)/2;
//     debug(2*u, st, mid);
//     debug(2*u+1, mid+1, en);
// }


///https://toph.co/p/easy-queries
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
	int n, q;
	cin >> n >> q;
	cin >> s;
	build(1, 0, n - 1);
	while (q--) {
		string s;
		cin >> s;
		if (s == "print")
			cout << query(1, 0, n - 1, 0, n - 1).zo << "\n";
		else {
			int l, r;
			cin >> l >> r;
			update(1, 0, n - 1, l - 1, r - 1);
		}
	}
	return 0;
}
