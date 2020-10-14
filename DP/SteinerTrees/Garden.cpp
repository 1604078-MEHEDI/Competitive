/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

//https://codeforces.com/contest/152/problem/E
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


/* for Random Number generate
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
*/
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
const int N = 222;
const int M = 8;
int terminal[M][2];
int a[N][N], dp[N][1 << M], n, m;
pair<int, int> par[N][1 << M];
char ans[N][N];

// tracking the steiner tree
void go(int i, int mask)
{
    if (i < 0 || mask < 0) return;
    ans[i / m][i % m] = 'X';
    go(par[i][mask].first, par[i][mask].second);
    if (i == par[i][mask].first)go(i, mask ^ par[i][mask].second);
}

ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};

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
    int k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        terminal[i][0] = x - 1;
        terminal[i][1] = y - 1;
    }

    for (int i = 0; i < n * m; i++)
        for (int j = 0; j < (1 << k); j++) {
            dp[i][j] = mod;
            par[i][j] = make_pair(-1, -1);
        }

    //base case
    for (int i = 0; i < k; i++) {
        int x = terminal[i][0];
        int y = terminal[i][1];
        dp[x * m + y][1 << i] = a[x][y];
    }

    for (int mask = 1; mask < (1 << k); mask++) {
        for (int i = 0; i < (n * m); i++) {
            for (int sub = ((mask - 1)&mask); sub > 0; sub = (sub - 1)&mask) {
                int p = dp[i][sub]; // cost of having nodes of sub
                int q = dp[i][sub ^ mask]; // cost for tree without sub nodes
                int r = a[i / m][i % m]; // remove cost for common node i
                if (p + q - r < dp[i][mask]) {
                    dp[i][mask] = p + q - r;
                    par[i][mask] = make_pair(i, sub);
                }
            }
        }

        // SPFA
        queue<int> Q;
        vector < bool> vis(N * N, 0);
        for (int i = 0; i < (n * m); i++) {
            vis[i] = true;
            Q.push(i);
        }

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            vis[u] = false;
            for (int i = 0; i < 4; i++) {
                int x = u / m;
                int y = u % m;
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int v = dp[x * m + y][mask] + a[nx][ny];
                    if (v < dp[nx * m + ny][mask]) {
                        dp[nx * m + ny][mask] = v;
                        par[nx * m + ny][mask] = make_pair(u, mask);
                        if (!vis[nx * m + ny]) {
                            vis[nx * m + ny] = true;
                            Q.push(nx * m + ny);
                        }
                    }
                }
            }
        }
    }

    int ret = mod;
    int last = 0;
    for (int i = 0; i < (n * m); i++) {
        if (dp[i][(1 << k) - 1] < ret) {
            ret = dp[i][(1 << k) - 1];
            last = i;
        }
    }

    cout << ret << endl;
    go(last, (1 << k) - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] != 'X') ans[i][j] = '.';
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}

