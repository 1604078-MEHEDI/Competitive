/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/
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

//*//**___________________________________________________**/
const int N = 1006;
const int nx = (1 << 10) + 1;
char s[15];
int dp[nx][N], d;
int lim;
int vis[nx][N], cs;
int go(int mask, int mod) {
	if (mask == (1 << lim) - 1) return mod == 0;

	int &ret = dp[mask][mod];
	int &v = vis[mask][mod];
	if (v == cs)return ret;
	v = cs;
	int flag[10] = {0};
	ret = 0;
	for (int i = 0; i < lim; i++) {
		int x = s[i] - '0';
		if (mask & (1 << i) || flag[x])continue;
		flag[x] = 1;
		ret += go(mask | (1 << i), ((mod * 10) + x) % d);
	}
	return ret;
}

// LOJ: 1158 - Anagram Division 
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
	int T;
	scanf("%d", &T);
	for (cs = 1; cs <= T; cs++) {
		ss(s);
		si(d);
		lim = strlen(s);
		printf("Case %d: %d\n", cs, go(0, 0));
	}
	return 0;
}
