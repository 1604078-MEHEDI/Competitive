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
const int N = 200007;
const ll inf = 1e15;
ll n;
struct info
{
  ll sum, maxPrefix, maxSuffix, maxsum;
} sg[4 * N];

ll a[N];

info Combine(info &a, info &b) {
  info res;
  res.sum = a.sum + b.sum;
  res.maxPrefix = max(a.maxPrefix, a.sum + b.maxPrefix);
  res.maxSuffix = max(a.maxSuffix + b.sum, b.maxSuffix);
  res.maxsum = max(  (a.maxSuffix + b.maxPrefix), max(a.maxsum , b.maxsum));
  return res;
}

void BuildTree(int node, int l, int r) {
  if (l == r) {
    sg[node] = {a[l], a[l], a[l], a[l]};
    return;
  }

  int mid = (l + r) / 2;
  BuildTree(2 * node + 1, l, mid);
  BuildTree(2 * node + 2, mid + 1, r);
  sg[node] = Combine(sg[2 * node + 1], sg[2 * node + 2]);
}

void update(int node, int l, int r, int pos, int val) {
  if (pos < l || r < pos)return;
  if (l == r) {
    sg[node] = {val, val, val, val};
    return;
  }
  int mid = (l + r) / 2;
  update(2 * node + 1, l, mid, pos, val);
  update(2 * node + 2, mid + 1, r, pos, val);
  sg[node] = Combine(sg[2 * node + 1], sg[2 * node + 2]);
}

info Query(int node, int l, int r, int i,  int j) {
  if (j < l || r < i)return{0, -inf, -inf, -inf};
  if (i <= l && r <= j) return sg[node];

  int mid = (l + r) / 2;
  info P = Query(2 * node + 1, l, mid, i, j);
  info Q = Query(2 * node + 2, mid + 1, r, i, j);
  return Combine(P, Q);
}
///https://www.spoj.com/problems/GSS3/

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
  ll q;
  cin >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];

  BuildTree(0, 1, n);

  while (q--) {
    ll l, r;
    cin >> l >> r;
    update(0, 1, n, l, r);
    info ans = Query(0, 1, n, 1, n);
    cout << max(ans.maxsum , 0ll) << "\n";
  }
  return 0;
}
