/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
using pii = pair<ll, ll>;
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

int n;
vector<pii> candies;
vector<ll> wagons;
vector < pair<pii, int>> ans;

///https://cses.fi/107/result/B/1146710/

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
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll p, t;
    cin >> p >> t;
    candies.emplace_back(p + t, t - p);
  }
  sort(candies.begin(), candies.end());
  for (int i = 0; i < n; i++) {
    ll a = candies[i].first, b = - candies[i].second;
    int pos = lower_bound(wagons.begin(), wagons.end(), b) - wagons.begin();
    if (pos == (int)wagons.size())wagons.emplace_back(b);
    else wagons[pos] = b;
    ans.push_back(make_pair(make_pair((a + b) / 2, (a - b) / 2), pos + 1));
  }
  cout << wagons.size() << "\n";
  for (auto &x : ans)
    cout << x.first.first << " " << x.first.second << " " << x.second << "\n";
}

/*
// Credit: official editorial

A first, simple approach is to use dynamic programming over the wagon positions. This would lead
to a run time of O(n w ); 20% of the score should be awarded to such a solution.
When looking for a better solution, we observe that the paths of two wagons never need to cross.
Two crossing paths can be replaced by two paths with the parts after the crossing exchanged. Then,
we have a “smallest” wagon, i.e. a wagon such that there is no candy with a smaller position than
any of the candies caught by that wagon. Now assume we can compute an optimal smallest wagon
path (OSWP) such that this wagon catches as many candies at possible. Afterwards, we disregard all
candies caught by the smallest wagon, compute the OSWP for the remaining candies, and so on. If
the computation of the OSWP can be done in O(n), the whole algorithm runs in O(n 2 ).
Indeed, it is possible to compute an OSWP in O(n). We pass through all candies by increasing output
time and maintain a stack of candies; candies on the stack are caught by the wagon. The first candy
is pushed on top of the stack. Furtheron, we consider the current candy c and the candy on top of the
stack (the last candy to be caught by the wagon) c s . If the wagon can run from the position of c s to the
position of c such that it catches c on time, then c is put on top of the stack. Else, and if the position
of c is smaller than that of c s , the stack is popped until c is reachable from c s again. Afterwards, c is
put on the stack. 60% of the score should be awarded to a correct O(n 2 ) algorithm.
A more efficient algorithm builds upon the idea non-crossing paths, too, but passes candies by posi-
tion. Each candy is to be assigned to the leftmost possible wagon. If binary search is used to determine
the wagon and a balanced tree is used to store each wagon’s candies, a run time of O(n log 2 n) is pos-
sible. Full score should be awarded to a correct algorithm with such runtime.
Further improvements may even yield a runtime of O(n log n):
*/
