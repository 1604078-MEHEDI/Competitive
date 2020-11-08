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


const int N = 10006;
const int M = 110;
vector<int> a;
int n, m, cs;

ll dp[M][M];
int vis[M][M];
ll go(int pos, int prv) {
	if (pos == n)return 1;
	ll &ret = dp[pos][prv];
	int &v = vis[pos][prv];
	if (v == cs) return ret;
	v = cs;
	ll tot = 0;
	int limit = a.size();
	for (int i = 0; i < limit; i++) {
		if (prv == 0 || abs(prv - a[i]) <= 2)
			tot += go(pos + 1, a[i]);
	}
	return ret = tot;
}

void solve() {
	cin >> m >> n;
	a.clear();
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	//dbg(a);
	//memset(dp, -1, sizeof dp);
	ll ans = go(0, 0);
	cout << "Case " << cs << ": ";
	cout << ans << "\n";
}


///1122 - Digit Count 
//http://www.lightoj.com/volume_showproblem.php?problem=1122
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
	int t;
	cin >> t;
	cs = 0;
	while (t--) {
		++cs;
		solve();
	}
	return 0;
}

