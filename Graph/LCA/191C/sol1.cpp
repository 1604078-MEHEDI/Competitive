/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

//https://codeforces.com/contest/191/problem/C
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
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
const int N = 100006;
const int lg = 25;
int dp[N][30];
int ans[N];
map<pair<int, int>, int> road;
vector<int>g[N];

int n, k;

struct city
{
    int vis = 0;
    int parent = -1;
    int level = 0;
    int cnt = 0;
} city[N];


// find the parent and level of each node for calculation lca
void dfs(int node, int par, int lvl)
{
    city[node].vis = 1;
    city[node].parent = par;
    city[node].level = lvl;
    for (auto v : g[node]) {
        if (!city[v].vis) {
            dfs(v, node, lvl + 1);
        }
    }
}

// dp approach to find lca between two nodes by setting (2^i)th ancestor of each node
void process()
{
    dfs(1, 1, 0);
    for (int i = 0; i <= n + 2; i++)
        for (int j = 0; j <= lg; j++) dp[i][j] = 1;

    for (int i = 1; i <= n; i++)
        dp[i][0] = city[i].parent;
    for (int j = 1; j < lg; j++)
        for (int i = 1; i <= n; i++)
            dp[i][j] = dp[max(0, dp[i][j - 1])][j - 1];
}

int lca(int a, int b)
{
    if (city[a].level > city[b].level)swap(a, b);

    for (int j = lg; j >= 0; j--) {
        if (city[b].level - (1 << j) >= city[a].level)
            b = dp[b][j];
    }
    if (a == b) return a;

    for (int i = lg; i >= 0; i--) {
        if (dp[a][i] != -1 && dp[a][i] != dp[b][i]) {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return city[a].parent;
}

// 2nd dfs to count the number of times we travel each road
void DFS(int node)
{
    city[node].vis = 0;
    for (auto v : g[node]) {
        if (city[v].vis) {
            DFS(v);
            city[node].cnt += city[v].cnt;
        }
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
    si(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        sii(x, y);
        g[x].push_back(y);
        g[y].push_back(x);
        road[ {x, y}] = road[ {y, x}] = i; // road ID
    }
    process();
    si(k);
    while (k--) {
        int x, y;
        sii(x, y);
        city[x].cnt++;
        city[y].cnt++;
        city[lca(x, y)].cnt -= 2;
    }
    DFS(1);
    for (int i = 2; i <= n; i++) {
        ans[road[ {i, city[i].parent}]] = city[i].cnt;
    }
    for (int i = 1; i < n; i++) {
        pi(ans[i]);
        printf(" ");
    }
    printf("\n");
    return 0;
}
