/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/
///https://cp-algorithms.com/game_theory/games_on_graphs.html#toc-tgt-1
#include <bits/stdc++.h>
using namespace std;
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




/*
Here is the implementation of such a DFS.
We assume that the variable adj_rev stores the adjacency list
for the graph in reversed form,
 i.e. instead of storing the edge (i,j) of the graph,
we store (j,i). Also for each vertex we assume that the outgoing degree is already computed
*/
// vector<vector<int>> adj_rev;

// vector<bool> wining;
// vector<bool> losing;
// vector<bool> visited;
// vector<int> degree;

// void dfs(int u)
// {
//   visited[u] = true;
//   for (auto v : adj_rev[v]) {
//     if (visited[v])continue;
//     if (losing[u]) wining[v] = true;
//     else if (--degree[v] == 0) losing[u] = true;
//     else continue;
//     dfs(v);
//   }
// }



/*
There is m×n board. Some of the cells cannot be entered.
The initial coordinates of the police officer and of the thief are known.
One of the cells is the exit. If the policeman and the thief are located at
the same cell at any moment, the policeman wins. If the thief is at the exit
cell (without the policeman also being on the cell), then the thief wins.
The policeman can walk in all 8 directions, the thief only in 4 (along the coordinate axis).
Both the policeman and the thief will take turns moving. However they also can skip a turn if they want to.
The first move is made by the policeman
*/
///Policeman and thief.
struct State
{
  int P, T;
  bool Pstep;
};

vector<State> r_g[100][100][2]; // [P][T][Pstep]
bool wining[100][100][2];
bool losing[100][100][2];
bool visited[100][100][2];
int degree[100][100][2];

void dfs(State v)
{
  visited[v.P][v.T][v.Pstep] = true;
  for (auto u : r_g[v.P][v.T][v.Pstep]) {
    if (visited[u.P][u.T][u.Pstep])continue;
    if (losing[v.P][v.T][v.Pstep])
      wining[u.P][u.T][u.Pstep] = true;
    else if (--degree[u.P][u.T][u.Pstep] == 0)
      losing[u.P][u.T][u.Pstep] = true;
    else continue;
    dfs(u);
  }
}



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

  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int P = 0; P < n * m; P++) {
    for (int T = 0; T < n * m; T++) {
      for (int Pstep = 0; Pstep < 2; Pstep++) {
        int Px = P / m;
        int Py = P % m;
        int Tx = T / m;
        int Ty = T % m;

        if (a[Px][Py] == '*' || a[Tx][Ty] == '*')
          continue;

        bool& win = wining[P][T][Pstep];
        bool& lose = losing[P][T][Pstep];

        if (Pstep) {
          win = (Px == Tx && Py == Ty);
          lose = !win && a[Tx][Ty] == 'E';
        }
        else {
          lose = (Px == Tx && Py == Ty);
          win = !lose && a[Tx][Ty] == 'E';
        }

        if (win || lose)continue;

        State st = {P, T, !Pstep};
        r_g[P][T][Pstep].push_back(st);
        st.Pstep = Pstep;
        degree[P][T][Pstep]++;


        const int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1};
        const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};

        for (int d = 0; d < (Pstep ? 8 : 4); d++) {
          int PPx = Px;
          int PPy = Py;
          int TTx = Tx;
          int TTy = Ty;

          if (Pstep) {
            PPx += dx[d];
            PPy += dy[d];
          }
          else {
            TTx += dx[d];
            TTy += dy[d];
          }

          if (PPx >= 0 && PPx < n && PPy >= 0 && PPy < m && a[PPx][PPy] != '*' &&
              TTx >= 0 && TTx < n && TTy >= 0 && TTy < m && a[TTx][TTy] != '*')
          {
            r_g[PPx * m + PPy][TTx * m + TTy][!Pstep].push_back(st);
            ++degree[P][T][Pstep];
          }
        }
      }
    }
  }


  for (int P = 0; P < n * m; P++) {
    for (int T = 0; T < n * m; T++) {
      for (int Pstep = 0; Pstep < 2; Pstep++) {
        if ((wining[P][T][Pstep] || losing[P][T][Pstep]) && !visited[P][T][Pstep])
          dfs({P, T, (bool)Pstep});
      }
    }
  }

  int P_st, T_st;

  for (int i = 0; i < n; i++) {
    for (int j = 0;  j < m; j++) {
      if (a[i][j] == 'P') P_st = i * m + j;
      else if (a[i][j] == 'T') T_st = i * m + j;
    }
  }

  if (wining[P_st][T_st][true])
    cout << "Police cathes the thief\n";
  else if (losing[P_st][T_st][true])
    cout << "The thief escapes\n";
  else cout << "Draw\n";
  return 0;
}
