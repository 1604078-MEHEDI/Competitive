
//https://open.kattis.com/problems/elementarymath
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
const int N = 2555;

bool match(ll cur, vector<vector<ll>> &graph, vector<ll>& l, vector<ll>& r, vector<ll>& vis)
{
  if (vis[cur]) return false;
  vis[cur] = true;
  for (auto next : graph[cur]) {
    if (r[next] == -1 || match(r[next], graph, l, r, vis)) {
      l[cur] = next;
      r[next] = cur;
      return true;
    }
  }
  return false;
}



vector<ll> bipertite(vector<vector<ll>> &graph, ll n, ll m)
{
  vector<ll> l, r, vis;
  l.resize(n, -1);
  r.resize(m, -1);
  vis.resize(n);

  bool works = true;
  while (works) {
    works = false;
    fill(vis.begin(), vis.end(), 0);
    for (int i = 0; i < n; i++) {
      if (l[i] == -1) {
        works |= match(i, graph, l, r, vis);
      }
    }
  }
  return l;
}

void go(ll l, ll r, ll F)
{
  cout << l << " ";
  if (l + r == F) {
    cout << "+";
  }
  else if (l - r == F) {
    cout << "-";
  }
  else cout << "*";
  cout << " " << r << " = " << F << endl;
}

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
  ll n;
  cin >> n;
  vector<pair<ll, ll>> input;
  vector <vector<ll> > graph(n);
  map<ll, ll> NumToNode;
  vector<ll> NodeToNum;
  ll cnt = 0;

  for (int i = 0; i < n; i++) {
    pair<ll, ll> p;
    cin >> p.first >> p.second;
    input.push_back(p);

    ll Add = p.first + p.second;
    if (NumToNode.count(Add) == 0) {
      NumToNode[Add] = cnt;
      NodeToNum.push_back(Add);
      cnt++;
    }

    ll Sub = p.first - p.second;
    if (NumToNode.count(Sub) == 0) {
      NumToNode[Sub] = cnt;
      NodeToNum.push_back(Sub);
      cnt++;
    }
    ll Mul = p.first * p.second;
    if (NumToNode.count(Mul) == 0) {
      NumToNode[Mul] = cnt;
      NodeToNum.push_back(Mul);
      cnt++;
    }
    graph[i].push_back(NumToNode[Add]);
    graph[i].push_back(NumToNode[Sub]);
    graph[i].push_back(NumToNode[Mul]);
  }
  //dbg(cnt);
  vector<ll> matching = bipertite(graph, n, cnt);
  //dbg(matching);
  ll total = 0;
  for (int i = 0; i < n; i++) {
    total += (matching[i] != -1);
  }
  //dbg(total);
  if (total == n) {
    for (int i = 0; i < n; i++) {
      go(input[i].first, input[i].second, NodeToNum[matching[i]]);
    }
  }
  else cout << "impossible\n";
}
