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
int P[N][30], parent[N], level[N], sz[N], ptr = 0, posInBase[N];
int t[N * 3], a[N], lazy[3 * N];
bool vis[3 * N];
vector<int> g[N];

void shift(int id)
{
    t[id * 2] += lazy[id];
    t[id * 2 + 1] += lazy[id];

    lazy[id * 2] += lazy[id];
    lazy[id * 2 + 1] += lazy[id];
    vis[id * 2] = vis[id * 2 + 1] = 1;
    lazy[id] = vis[id] = 0;
}

void init(int id, int b, int e)
{
    if (b == e) {
        t[id] = a[b];
        return;
    }
    int mid = (b + e) / 2;
    init(id * 2, b, mid);
    init(id * 2 + 1, mid + 1, e);
    t[id] = t[id * 2] + t[id * 2 + 1];
}

void update(int id, int b, int e, int i, int j, int val)
{
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
        t[id] += val;
        lazy[id] += val;
        vis[id] = 1;
        return;
    }
    if (vis[id])shift(id);
    int m = (b + e) >> 1;
    update(id * 2, b, m, i, j, val);
    update(id * 2 + 1, m + 1,  e, i, j, val);
    t[id] = t[id * 2] + t[id * 2 + 1];
}

int Query(int id, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= i) return t[id];
    if (vis[id])shift(id);

    int m = (b + e) >> 1;;
    int x = Query(id * 2, b, m, i, j);
    int y = Query(id * 2 + 1, m + 1, e, i, j);
    return (x + y);
}

inline void dfs_for_lca(int u, int lvl)
{
    level[u] = lvl;
    sz[u] = 1;
    for (auto v : g[u]) {
        if (v == parent[u])continue;
        parent[v] = u;
        dfs_for_lca(v, lvl + 1);
        sz[u] += sz[v];
    }
}

inline void preprocess(int n)
{
    memset(P, -1, sizeof P);
    for (int i = 1; i <= n; i++) P[i][0] = parent[i];

    for (int j = 0; (1 << j) <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
        }
    }
}

int lca(int u, int v)
{
    if (level[u] < level[v]) swap(u, v);
    int dif = level[u] - level[v];
    while (dif > 0) {
        int rise = log2(dif);
        u = P[u][rise];
        dif -= (1 << rise);
    }
    if (u == v)return u;
    for (int j = 20; j >= 0; j--) {
        if (P[u][j] != P[v][j] && P[u][j] != -1) {
            u = P[u][j];
            v = P[v][j];
        }
    }
    return parent[u];
}
int ChainNo, ChainHead[N], ChainPos[N], ChainIdx[N];
int ChainSize[N];


void HLD(int cur) {
    if (ChainHead[ChainNo] == -1)ChainHead[ChainNo] = cur;
    ChainIdx[cur] = ChainNo;

    ChainPos[cur] = ChainSize[ChainNo];
    ChainSize[ChainNo]++;
    posInBase[cur] = ptr++;

    int idx = -1, ma = -1;
    for (int i = 0; i < (int)g[cur].size(); i++) {
        int x = g[cur][i];
        if (sz[x] > ma && x != parent[cur]) {
            ma = sz[x];
            idx = i;
        }
    }

    if (idx >= 0)HLD(g[cur][idx]);
    for (int i = 0; i < (int)g[cur].size(); i++) {
        if (i != idx && g[cur][i] != parent[cur]) {
            ChainNo++;
            HLD(g[cur][i]);
        }
    }
}

int Query_Up(int u, int v)
{
    int uchain, vchain = ChainIdx[v], ans = 0;
    while (1) {
        if (u == v)break;
        uchain = ChainIdx[u];
        if (uchain == vchain) {
            int cur = Query(1, 0, ptr, posInBase[v] + 1, posInBase[u]);
            ans += cur;
            break;
        }
        int cur = Query(1, 0, ptr, posInBase[ChainHead[uchain]], posInBase[u]);
        ans += cur;
        u = ChainHead[uchain];
        u = parent[u];
    }
    return ans;
}

int qry(int u, int v)
{
    int lc = lca(u, v);
    return (Query_Up(u, lc) + Query_Up(v, lc));
}

void Query_update(int u, int v, int val)
{
    int uchain, vchain = ChainIdx[v];
    while (1) {
        uchain = ChainIdx[u];
        if (uchain == vchain) {
            if (u == v)break;
            update(1, 0, ptr, posInBase[v] + 1, posInBase[u], 1);
            break;
        }
        if (u == v)break;
        update(1, 0, ptr, posInBase[ChainHead[uchain]], posInBase[u], 1);
        u = ChainHead[uchain];
        u = parent[u];
    }
}

void Query_Up2(int u, int v, int val)
{
    int lc = lca(u, v);
    Query_update(u, lc, val);
    Query_update(v, lc, val);
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
    si(n);
    vector<pair<int, int>> Q;
    for (int i = 1; i < n; i++) {
        int a, b;
        sii(a, b);
        g[a].push_back(b);
        g[b].push_back(a);
        Q.emplace_back(a, b);
    }

    memset(ChainHead, -1, sizeof ChainHead);
    dfs_for_lca(1, 1);
    preprocess(n);
    HLD(1);

    int q;
    si(q);
    while (q--) {
        int a, b;
        sii(a, b);
        Query_Up2(a, b, 1);
    }
    for (auto E : Q) {
        pi(qry(E.first, E.second));
        printf(" ");
    }
    printf("\n");
    return 0;
}
