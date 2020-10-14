
//https://codeforces.com/contest/1325/problem/E
//Topic: Number Theory + bfs
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
// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

// find_by_order(k) – ফাংশনটি kth ordered element এর একটা পয়েন্টার রিটার্ন করে। অর্থাৎ তুমি চাইলেই kth ইন্ডেক্সে কি আছে, সেটা জেনে ফেলতে পারছো!
// order_of_key(x) – ফাংশনটি x এলিমেন্টটা কোন পজিশনে আছে সেটা বলে দেয়।

//*//**___________________________________________________**/

const int N = 1e6 + 6;
vector<ll> primes;
bitset<N> Check;
vector<pair<ll, ll> > g[N];
ll vis[N], visEdge[N], lev[N];
ll sz, edgeno;

void sv()
{
	primes.push_back(2);
	for (ll i = 3; i < N; i += 2) {
		if (!Check[i]) {
			primes.push_back(i);
			for (ll j = i * i; j < N; j += i) {
				Check[j] = 1;
			}
		}
	}
}

bool go(ll x)
{
	ll p1 = -1, p2 = -1;
	for (ll j = 0; j < sz && primes[j]*primes[j] <= x; j++) {
		if (x % primes[j] == 0) {
			ll cnt = 0;
			while (x % primes[j] == 0) {
				x /= primes[j];
				cnt++;
			}
			if (cnt & 1) {
				if (p1 == -1) p1 = primes[j];
				else p2 = primes[j];
			}
		}
	}

	if (x > 1) {
		if (p1 == -1) p1 = x;
		else p2 = x;
	}
	if (p1 == -1)
	{
		cout << 1 << endl;
		return 0;
	} //chk = 1;
	else {
		ll u = p1, v;
		if (p2 == -1) v = 1;
		else v = p2;
		g[u].push_back({v, edgeno});
		g[v].push_back({u, edgeno});
		edgeno++;
	}
	return 1;
}

ll bfs(ll s)
{
	queue<ll> Q;
	Q.push(s);
	vis[s] = s;
	lev[s] = 0;
	ll ret = mod;
	while (!Q.empty()) {
		ll u = Q.front();
		Q.pop();
		for (auto v : g[u]) {
			if (visEdge[v.second] == s)continue;
			if (vis[v.first] == s)
				ret = min(ret, lev[u] + lev[v.first] + 1);
			else {
				lev[v.first] = lev[u] + 1;
				vis[v.first] = visEdge[v.second] = s;
				Q.push(v.first);
			}
		}
	}
	return ret;
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
	sv();
	ll n;
	edgeno = 0;
	cin >> n;
	sz = primes.size();
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		if (!go(x)) {
			return 0;
		}
	}

	ll ans = bfs(1);
	for (ll i = 0; i < sz && primes[i]*primes[i] < N; i++) {
		ll s = primes[i];
		ans = min(ans, bfs(s));
	}
	if (ans == mod) ans = -1;
	cout << ans << endl;
	return 0;
}
