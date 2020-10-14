/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/
///https://codeforces.com/gym/101908/problem/J
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
// GNU link : https://g...content-available-to-author-only...o.gl/WVDL6g
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

// find_by_order(k) – ফাংশনটি kth ordered element এর একটা পয়েন্টার রিটার্ন করে। অর্থাৎ তুমি চাইলেই kth ইন্ডেক্সে কি আছে, সেটা জেনে ফেলতে পারছো!
// order_of_key(x) – ফাংশনটি x এলিমেন্টটা কোন পজিশনে আছে সেটা বলে দেয়।

//*//**___________________________________________________**/

int id_cnt = 0;
map<pair<int, int> , int> mp;
map<pair<int, int> , bool> vis;

int getID(int x, int y)
{
  if (vis[ {x, y}])return mp[ {x, y}];
  mp[ {x, y}] = id_cnt++;
  vis[ {x, y}] = true;
  return mp[ {x, y}];
}

int n, k;
double inf = 1234578.0;
double cost[105][105];
vector<pair<int, int>> point;

void init (int n)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cost[i][j] = inf;

  for (int i = 0; i < n; i++) {
    cost[i][i] = 0;
  }
}

double dist(int a, int b, int c, int d)
{
  return ((double)sqrt((a - c) * (a - c) + (b - d) * (b - d)));
}

void floyed_warshall()
{
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
}

int main()
{
  //FASTIO
  //s/*
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
  #endif
  //*/
  cin >> n >> k;
  init(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    getID(x, y);
    point.push_back({x, y});
  }
  for (int i = 0; i < n; i++) {
    int u = getID(point[i].first, point[i].second);
    for (int j = i; j < n; j++) {
      int v = getID(point[j].first, point[j].second);
      double w = dist(point[i].first, point[i].second, point[j].first, point[j].second);
      cost[u][v] = cost[v][u] = min(cost[u][v], w);
      // dbg(u, v, cost[u][v]);
    }
  }

  floyed_warshall();

  vector<int> group(k);
  int cnt = 0;
  for (int i = 0; i < k; i++) {
    int u = getID(point[i].first, point[i].second);
    group[cnt++] = u;
  }

  int roads[k][k][2];
  for (int i = 0; i < k; i++) {
    int x = getID(point[i].first, point[i].second);
    for (int j = i; j < k; j++) {
      roads[i][j][0] = x;
      roads[i][j][1] = getID(point[j].first, point[j].second);
    }
  }
  //Compute steiner trees
  double minCost[n][1 << k];

  // memset(minCost, 64, sizeof minCost);
  for (int i = 0; i < n; i++) {
    for (int it = 0; it < (1 << k); it++)
      minCost[i][it] = inf;
  }

  for (int i = 0; i < k; i++)
    minCost[group[i]][(1 << i)] = 0;

  for (int mask = 0; mask < (1 << k); mask++) {
    for (int i = 0; i < n; i++) {
      for (int ss = mask; ss > 0; ss = (ss - 1)&mask)
        minCost[i][mask] = min(minCost[i][mask],
                               minCost[i][ss] + minCost[i][mask - ss]);
      if (inf - minCost[i][mask] > 1) {
        for (int j = k; j < n; j++)
          minCost[j][mask] = min(minCost[j][mask],
                                 minCost[i][mask] + cost[i][j]);
      }
      //faltu(i, mask, minCost[i][mask]);
    }
  }

  vector<double> minTotal(1 << k, inf);
  //dbg(minTotal);
  for (int mask = 0; mask < (1 << k); mask++)
    for (int i = 0; i < n; i++)
      minTotal[mask] = min(minTotal[mask], minCost[i][mask]);
  // dbg(minTotal);
  vector<double> dp(1 << k, inf);
  dp[0] = 0.0;
  for (int mask = 0; mask < (1 << k); mask++) {
    if (abs(dp[mask] - inf) < 1) continue;
    //dbg(dp[mask]);
    for (int smask = 0; smask < (1 << k); smask++) {
      // dbg(mask & smask);
      if ((mask & smask) > 0)continue;
      int joinmask = 0;
      for (int i = 0; i < k; i++) {
        if (((1 << i)&smask) > 0) {
          for (int j = i; j < k; j++) {
            int x = lower_bound(group.begin(), group.end(), roads[i][j][0]) - group.begin();
            int y = lower_bound(group.begin(), group.end(), roads[i][j][1]) - group.begin();
            joinmask |= (1 << x) | (1 << y);
          }
        }
      }
      //dbg(mask | smask, joinmask);

      dp[mask | smask] = min(dp[mask | smask], dp[mask] + minTotal[joinmask]);
      //faltu(dp[mask | smask], joinmask);
    }
  }
  //dbg(dp);
  cout << fixed << setprecision(5) << dp[(1 << k) - 1] << endl;
  return 0;
}
