#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const ll mod = 1e9 + 7;

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



const int N = 33;
vector<int> digits;
int n;
ll dp[N][N][N][2][2];

ll go(int pos, int zero, int one, bool isStart, bool isValid) {
  if (pos == -1) {
    return zero >= one;
  }

  ll &ret = dp[pos][zero][one][isStart][isValid];
  if (~ret) return ret;
  int limit = isValid ? 1 : digits[pos];

  ll tot = 0;
  for (int i = 0; i <= limit; i++) {
    if (isStart && !i)
      tot += go(pos - 1, 0, 0, true, true);
    else
      tot += go(pos - 1, i == 0 ? zero + 1 : zero, i == 1 ? one + 1 : one, false, isValid || i < digits[pos]);
  }
  return ret = tot;
}

ll solve(ll x) {
  digits.clear();
  while (x) {
    digits.push_back(x % 2);
    x /= 2;
  }
  n = digits.size();
  memset(dp, -1, sizeof dp);
  return go(n - 1, 0, 0, true, false);
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

  ll a, b;
  cin >> a >> b;
  ll ans = solve(b) - solve(a - 1);
  cout << ans << "\n";
  return 0;
}
