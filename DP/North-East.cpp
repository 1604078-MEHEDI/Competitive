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
int n;

struct SegTree
{
#define root 1, n+10, 1
#define lr rt << 1
#define rr rt<< 1|1
#define lson l,mid,lr
#define rson mid+1, r, rr

	int mx[N << 2];

	void Up(int rt) {
		mx[rt] = max(mx[lr], mx[rr]);
	}

	void Build(int l, int r, int rt) {
		mx[rt] = 0;
		if (l == r) return;
		int mid = (l + r) >> 1;
		Build(lson);
		Build(rson);
	}

	void Update(int l, int r, int rt, int x, int v) {
		if (l == r) {
			mx[rt] = v;
			return;
		}
		int mid = (l + r) >> 1;
		if (x <= mid)Update(lson, x, v);
		else Update(rson, x, v);
		Up(rt);
	}

	int Query(int l, int r, int rt, int L, int R) {
		if (l == L && r == R)return mx[rt];
		int mid = (l + r) >> 1;
		if (R <= mid) return Query(lson, L, R);
		else if (L > mid)return Query(rson, L, R);
		else return max(Query(lson, L, mid), Query(rson, mid + 1, R));
	}
} misir;

struct node
{
	int x, y, id;
} E[N];

inline bool cmp1(const node &a, const node &b) {
	if (a.x != b.x)return a.x < b.x;
	else return a.y < b.y;
}

inline bool cmp2( const node &a , const node &b ) {
	if ( a.x != b.x ) return a.x > b.x ;
	else return a.y > b.y ;
}

map<int, int> Idx;
vector<int> a;
int S[N], top;

vector<int> ans1, ans2;
int cnt[N], dp[2][N];

void go(int k, int p) {
	for (int i = top - 1; i >= 0; i--) {
		int id = Idx[E[p].y];
		dp[k][E[p].id] = S[i];
		misir.Update(root, id, S[i]);
		p--;
	}
}

void solve() {
	memset( dp , 0 , sizeof dp);
	memset( cnt , 0 , sizeof cnt);

	sort( E + 1 , E + n + 1 , cmp1);
	misir.Build(root);
	top  = 0;
	for (int i = 1; i <= n; i++) {
		int id = Idx[E[i].y];
		if (i == n || E[i].x != E[i + 1].x) {
			S[top++] = misir.Query(root, 1, id - 1) + 1;
			go(0, i);
			top = 0;
		}
		else S[top++] = misir.Query(root, 1, id - 1) + 1;
	}

	sort( E + 1 , E + n + 1 , cmp2 ) ;
	misir.Build(root);
	top  = 0;

	for ( int i = 1 ; i <= n ; ++i ) {
		int id =  Idx[ E[i].y ] ;
		if ( i == n || E[i].x != E[i + 1].x ) {
			S[top++] = misir.Query( root , id + 1 , n + 10 ) + 1 ;
			go( 1 , i );
			top = 0 ;
		} else {
			S[top++] = misir.Query( root , id + 1 , n + 10 ) + 1 ;
		}
	}
	ans1.clear() , ans2.clear() ;
	int len = 0 ;
	for ( int i = 1 ; i <= n ; ++i ) len = max( len , dp[0][i] + dp[1][i] ) ;
	for ( int i = 1 ; i <= n ; ++i ) if ( dp[0][ E[i].id ] + dp[1][ E[i].id ] == len ) ans1.push_back( E[i].id ) , cnt[ dp[0][ E[i].id ] ]++ ;
	for ( int i = 1 ; i <= n ; ++i ) if ( dp[0][ E[i].id ] + dp[1][ E[i].id ] == len && cnt[ dp[0][E[i].id] ] == 1 ) ans2.push_back( E[i].id ) ;

}

void Output() {
	sort( ans1.begin() , ans1.end() ) , sort( ans2.begin() , ans2.end() ) ;
	printf("%d",(int) ans1.size()); for ( int i = 0 ; i <(int) ans1.size() ; ++i ) printf(" %d", ans1[i]); puts("");
	printf("%d",(int) ans2.size()); for ( int i = 0 ; i <(int) ans2.size() ; ++i ) printf(" %d", ans2[i]); puts("");
}


///https://codeforces.com/problemsets/acmsguru/problem/99999/521

//Credit: https://www.cnblogs.com/hlmark/p/4521496.html
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
	while ( ~scanf("%d", &n) ) {
		Idx.clear(); a.clear();
		for ( int i = 1 ; i <= n ; ++i ) {
			scanf("%d%d", &E[i].x, &E[i].y);
			E[i].id = i ;
			a.push_back( E[i].y );
		}
		sort( a.begin() , a.end() ) ;
		int tot = 2 ;
		for ( int i = 0 ; i <(int) a.size() ; ++i ) {
			if ( Idx.find( a[i] ) == Idx.end() ) {
				Idx[ a[i] ] = tot++ ;
			}
		}
		solve(); Output();
	}
	return 0;
}
