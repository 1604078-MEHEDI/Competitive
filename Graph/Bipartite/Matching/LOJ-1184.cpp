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
const int N = 66;


struct misir
{
	int age, height, divorce;
};
misir men[N], women[N];
int vis[N], dp[N];
int n,m;


int ok(int i, int j) {
	if ((men[i].divorce == women[j].divorce) and (abs(men[i].height - women[j].height) <= 12) and (abs(men[i].age - women[j].age) <= 5)) {
		return true;
	}

	return false;
}

int BPM(int manID) {
	for (int i = 0; i < m; i++) {
		if (ok(manID, i)) {
			if (vis[i])continue;
			vis[i] = 1;
			if (dp[i] < 0 || BPM(dp[i])) {
				dp[i] = manID;
				return 1;
			}
		}
	}
	return 0;
}

///1184 - Marriage Media 

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
	for (int cs = 1; cs <= T; cs++) {
		sii(n, m);
		for (int i = 0; i < n; i++) {
			si(men[i].height);
			si(men[i].age);
			si(men[i].divorce);
		}
		for (int i = 0; i < m; i++) {
			si(women[i].height);
			si(women[i].age);
			si(women[i].divorce);
		}

		memset(dp, -1, sizeof dp);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			memset(vis, 0, sizeof vis);
			if (BPM(i))ans++;
		}
		printf("Case %d: %d\n", cs, ans);
	}
	return 0;
}
