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
const int N = 406;
bool vis[N];
vector<int> g[N];
char G[25][25];
int dp[N], Gold[25][25];
int h, w, n;


int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void init() {
	for (int i = 0; i < n; i++)g[i].clear();
}
bool valid(int x, int y) {
	return (x >= 0 && y >= 0 && x < h && y < w);
}

bool bpm(int u) {
	for (int v : g[u]) {
		if (vis[v])continue;
		vis[v] = 1;
		if (dp[v] == -1 || bpm(dp[v])) {
			dp[v] = u;
			return 1;
		}
	}
	return 0;
}

int solve() {
	int ans = 0;
	memset(dp, -1, sizeof dp);
	for (int i = 1; i < n; i++) {
		memset(vis,  0, sizeof vis);
		if (bpm(i))ans++;
	}
	return ans / 2;
}
///1152 - Hiding Gold 
///Credit: Shakil Ahmed


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
		sii(h, w);
		for (int i = 0; i < h; i++)ss(G[i]);
		n = 1;
		memset(Gold, 0, sizeof Gold);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (G[i][j] == '*')
					Gold[i][j] = n++;
			}
		}

		init();

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (Gold[i][j]) {
					int x = i;
					int y = j;
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (valid(nx, ny) && Gold[nx][ny]) {
							g[Gold[x][y]].push_back(Gold[nx][ny]);
						}
					}
				}
			}
		}
		printf("Case %d: %d\n", cs, n - solve() - 1);
	}
	return 0;
}
