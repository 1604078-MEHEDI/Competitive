///https://codeforces.com/contest/935/problem/E

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
const int N = 11111;
const int M = 10010;
const int inf = 1e9 + 7;
int mx[101][M];
int mn[101][M];
int match[N];
int sign[N];
string s;
int n;
vector<int> graph[M];
int node;
int val[M];
int Plus, Minus;

int create(int l, int r)
{
	if (l == r) {
		val[++node] = s[l] - '0';
		return node;
	}

	int p = create(l + 1, sign[l] - 1);
	int q = create(sign[l] + 1, r - 1);
	int t = ++node;
	graph[t].push_back(p);
	graph[t].push_back(q);
	return t;
}

void MAX(int &x, int y)
{
	if (x < y) x = y;
}

void MIN(int &x, int y)
{
	if (x > y) x = y;
}

void dfs(int x)
{
	if (graph[x].empty()) {
		mx[0][x] = val[x];
		mn[0][x] = val[x];
		for (int i = 1; i <= Plus; i++) {
			mx[i][x] = -inf;
			mn[i][x] = inf;
		}
		return;
	}
	for (auto it : graph[x]) dfs(it);

	int p = graph[x][0];
	int q = graph[x][1];

	for (int i = 0; i <= Plus; i++) {
		mx[i][x] = -inf;
		mn[i][x] = inf;

		for (int j = 0; j <= i; j++) {
			MAX(mx[i][x], mx[j][p] - mn[i - j][q]);
			MIN(mn[i][x], mn[j][p] - mx[i - j][q]);
		}
		for (int j = 0; j < i; j++) {
			MAX(mx[i][x], mx[j][p] + mx[i - j - 1][q]);
			MIN(mn[i][x], mn[j][p] + mn[i - j - 1][q]);
		}
	}
}

void rev(int x)
{
	if (graph[x].empty()) {
		mx[0][x] = val[x];
		mn[0][x] = val[x];
		for (int i = 1; i <= Minus; i++) {
			mx[i][x] = -inf;
			mn[i][x] = inf;
		}
		return;
	}
	for (auto it : graph[x]) rev(it);

	int p = graph[x][0];
	int q = graph[x][1];

	for (int i = 0; i <= Minus; i++) {
		mx[i][x] = -inf;
		mn[i][x] = inf;
		for (int j = 0; j < i; j++) {
			MAX(mx[i][x], mx[j][p] - mn[i - j - 1][q]);
			MIN(mn[i][x], mn[j][p] - mx[i - j - 1][q]);
		}
		for (int j = 0; j <= i; j++) {
			MAX(mx[i][x], mx[j][p] + mx[i - j][q]);
			MIN(mn[i][x], mn[j][p] + mn[i - j][q]);
		}

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
	cin >> s;
	cin >> Plus >> Minus;
	stack<pair<int, char>> st;
	int n = s.size();
	memset(val, -1, sizeof val);
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			st.push({i, '('});
		}
		else if (s[i] == '?') {
			st.push({i, '?'});
		}
		else if (s[i] == ')'){
			int p = st.top().first;
			st.pop();
			int q = st.top().first;
			st.pop();
			match[q] = i;
			sign[q] = p;
		}
	}

	create(0, n - 1);
	if (Plus <= Minus) {
		dfs(node);
		cout << mx[Plus][node] << "\n";
	}
	else {
		rev(node);
		cout << mx[Minus][node] << "\n";
	}
	return 0;
}
