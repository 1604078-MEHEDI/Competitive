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
const int nx = 100001;
int N;
int x[nx];
int LIS[nx];
int LDS[nx];
int lis[nx];
int lds[nx];
int Tree[4 * nx];
int best;

void init() {
	for (int i = 1; i <= N; i++) {
		LIS[i] = LDS[i] = 0;
	}
	memset(Tree, 0, sizeof Tree);
	best = 0;
}

int query(int node , int s , int e , int qs , int qe) {
	if (s > qe || e < qs)
		return 0;
	if (s >= qs && e <= qe)
		return Tree[node];
	return max(query(2 * node , s , (s + e) / 2 , qs , qe) , query(2 * node + 1 , (s + e) / 2 + 1, e , qs , qe));
}
void update(int node , int s , int e , int idx , int val) {
	if (s == e && s == idx) {
		Tree[node] = val;
		return;
	}
	if (s > idx || e < idx)
		return;
	update(2 * node , s , (s + e) / 2 , idx , val);
	update(2 * node + 1 , (s + e) / 2 + 1 , e , idx , val);
	Tree[node] = max(Tree[2 * node] , Tree[2 * node + 1]);
	return;
}

void go() {
	
	scanf("%d" , &N);
	init();
	for (int n = 1 ; n <= N ; n++)
		scanf("%d" , &x[n]);
	for (int n = 1 ; n <= N ; n++) {
		LIS[n] = 1 + query(1 , 1 , N , 1 , x[n] - 1);
		update(1 , 1 , N , x[n] , LIS[n]);
		best = max(best , LIS[n]);
	}
	memset(Tree , 0 , sizeof(Tree));
	for (int n = N ; n >= 1 ; n--) {
		LDS[n] = 1 + query(1 , 1 , N , x[n] + 1 , N);
		update(1 , 1 , N , x[n] , LDS[n]);
	}
	vector < int > res;
	for (int n = 1 ; n <= N ; n++) {
		// printf("%d %d\n" , LIS[n],LDS[n]);
		if (LIS[n] + LDS[n] - 1 == best)
			res.push_back(x[n]);
	}


	/*
	for(int n = 1 ; n <= N ; n++){
	    lis[n] = 1;
	   for(int h = 1 ; h < n ; h++)
		   if(x[n] > x[h])
			   lis[n] = max(lis[n] , lis[h] + 1);
	}
	for(int n = N ; n >= 1 ; n--){
	    lds[n] = 1;
	   for(int h = N  ; h > n ; h--)
		   if(x[n] < x[h])
		     lds[n] = max(lds[n] , lds[h] + 1);
	}
	printf("\n\n");
	for(int n =  1 ; n <= N ; n++)
	   printf("%d %d\n" , lis[n] , lds[n]);

	*/

	sort(res.begin() , res.end());
	printf("%d\n" , (int) res.size());
	for (int i = 0 ; i < (int)(res.size()) - 1 ; i++)
		printf("%d " , res[i]);
	printf("%d\n" , res.back());
}


/// Credit: https://codeforces.com/blog/entry/5031\
///https://www.spoj.com/problems/SUPPER/
// LCS+LDS

int main() {
	///*
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	//*/

	int t = 10;
	while (t--) {
		go();
	}
	return 0;
}
