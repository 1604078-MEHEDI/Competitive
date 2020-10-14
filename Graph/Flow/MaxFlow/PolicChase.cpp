/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/


//https://cses.fi/problemset/task/1694/


//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

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

int dx[]  = {0, 0, 1, -1};
int dy[]  = {1, -1, 0, 0};
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

struct FlowEdge
{
  int v, u;
  ll cap, flow = 0;
  FlowEdge(int v, int u, ll cap): v(v), u(u), cap(cap) {}
};

struct Dinic
{
  const ll inf = 1e18;
  int n, m = 0, s, t;
  vector<FlowEdge> edges;
  vector<vector<int>> g;
  vector<int> level, ptr;
  queue<int> Q;

  Dinic(int n, int s, int t): n(n), s(s), t(t) {
    g.resize(n);
    level.resize(n);
    ptr.resize(n);
  }

  void addEdge(int u, int v, ll cap)
  {
    edges.emplace_back(u, v, cap);
    edges.emplace_back(v, u, 0);
    g[u].push_back(m);
    g[v].push_back(m + 1);
    m += 2;
  }

  bool bfs()
  {
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      for (auto id : g[v]) {
        if (edges[id].cap - edges[id].flow < 1)continue;
        if (level[edges[id].u] != -1)continue;
        level[edges[id].u] = level[v] + 1;
        Q.push(edges[id].u);
      }
    }
    return level[t] != -1;
  }

  ll dfs(int v, ll pushed)
  {
    if (pushed == 0)return 0;
    if (v == t)return pushed;
    for (int &cid = ptr[v]; cid < (int)g[v].size(); cid++) {
      int id = g[v][cid];
      int u = edges[id].u;
      if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)continue;
      ll ret =  dfs(u, min(pushed, edges[id].cap - edges[id].flow));
      if (ret == 0)continue;
      edges[id].flow += ret;
      edges[id ^ 1].flow -= ret;
      return ret;
    }
    return 0;
  }

  ll maxFlow()
  {
    ll ans = 0;
    while (true) {
      fill(level.begin(), level.end(), -1);
      level[s] = 0;
      Q.push(s);
      if (!bfs())break;
      fill(ptr.begin(), ptr.end(), 0);
      while (ll pushed = dfs(s, inf))ans += pushed;
    }
    return ans;
  }
};
// O(N^2*E);


bool hasEdge[505][505];
vector<int> positive, negative;



int main()
{

  //https://cses.fi/problemset/task/1695/
  FASTIO
  /*
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
  #endif
  //*/
  int n, m;
  cin >> n >> m;
  Dinic dinic(n + 1, 1, n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    dinic.addEdge(a, b, 1);
    dinic.addEdge(b, a, 1);
    hasEdge[a][b] = true;
    hasEdge[b][a] = true;
  }
  cout << dinic.maxFlow() << "\n";
  for (int i = 1; i <= n; i++) {
    if (dinic.level[i] >= 0)positive.push_back(i);
    else negative.push_back(i);
  }
  for (auto a : positive) {
    for (auto b : negative) {
      if (hasEdge[a][b])
        cout << a << " " << b << "\n";
    }
  }
}
