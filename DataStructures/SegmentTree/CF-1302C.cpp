///https://codeforces.com/contest/1302/problem/C
#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;

#define MAX 1000005

long long a[MAX];

ll st[4 * MAX];

ll query(ll node, ll l, ll r, ll ql, ll qr) {
  if (l >= ql && r <= qr) return st[node];
  else if (r < ql || l > qr) return 0;
  ll left = query(2 * node + 1, l, (l + r) / 2, ql, qr);
  ll right = query(2 * node + 2, (l + r) / 2 + 1, r, ql, qr);
  return left + right;
}

ll update(ll node, ll l, ll r, ll q, ll val) {
  if (r < q || l > q) return st[node];
  if (q == l && q == r) st[node] = val;
  else {
    ll left = update(2 * node + 1, l, (l + r) / 2, q, val);
    ll right = update(2 * node + 2, (l + r) / 2 + 1, r, q, val);
    st[node] = left + right;
  }
  return st[node];
}


int  main()
{
  ll tc;
  scanf("%lld", &tc);
  memset(a, 0, sizeof(a));
  memset(st, 0, sizeof(st));
  for (ll t = 1; t <= tc; t++ ) {
    //printf("Case %lld:\n", t);
    ll n, q;
    scanf("%lld%lld", &n, &q);
    //scanf("%lld", &a[i]);
    while (q--) {
      ll tp;
      scanf("%lld", &tp);
      ll x, y;
      scanf("%lld%lld", &x, &y);
      //x--, y--;
      if (tp == 1) update(1, 1, MAX, x, y);
      else printf("%lld\n", query(1, 1, MAX, x, y));
    }
  }
}
