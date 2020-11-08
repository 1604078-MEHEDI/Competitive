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


// template < typename F, typename S >ostream& operator << ( ostream& os, const pair< F, S > & p ) {return os << "(" << p.first << ", " << p.second << ")";}
// template < typename T >ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{"; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", "; os << *it;} return os << "}";}
// template < typename T >ostream &operator << ( ostream & os, const set< T > &v ) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin()) os << ", "; os << *it;} return os << "]";}
// template < typename F, typename S >ostream &operator << ( ostream & os, const map< F, S > &v ) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", "; os << it -> first << " = " << it -> second ;} return os << "]";}
// #define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
// clock_t tStart = clock();
// #define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
// void faltu () { cerr << endl; }
// template <typename T>void faltu( T a[], int n ) {for (int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl;}
// template <typename T, typename ... hello>
// void faltu( T arg, const hello &... rest) { cerr << arg << ' '; faltu(rest...); }

const int N = 36;
vector<ll> digits;
ll n, m, nx, cs, Round;
ll dp[N][2][2][N];
int vis[N][2][2][N];

ll go(int pos, bool flag, bool Start, int sm) {
    if (pos == nx)return sm;
    ll &ret = dp[pos][flag][Start][sm];
    int &v = vis[pos][flag][Start][sm];
    if (v == Round) return ret;
    v = Round;
    ll tot = 0;
    ll limit = (flag) ? digits[pos] : 9;
    if (Start) {// number agei start korechi
        for (int i = 0; i <= limit; i++) {
            tot += go(pos + 1, flag && (i == limit), 1, sm + (i == 0));
        }
    }
    else {
        for (int i = 1; i <= limit; i++) {
            tot += go(pos + 1, flag && (i == limit), 1, sm);
        }
        tot += go(pos + 1, 0, 0, 0);
    }

    return ret = tot ;
}

ll misir(ll x) {
    if (x < 0)return 0;
    if (x <= 9) return 1;
    digits.clear();
    while (x) {
        digits.push_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
    // dbg(digits);
    nx = digits.size();
    ++Round;
    return go(0, 1, 0, 0) + 1;
}


void solve() {
    //dbg(cs);
    sll(m, n);
    // dbg(m, n);
    ll l = misir(m - 1);
    ll r = misir(n);
    // return r - l;
    ll ans = r - l;
    printf("Case %lld: %lld\n", cs, ans);
}

/// LOJ_1140_How_Many_Zeroes.cpp 
///http://lightoj.com/volume_showproblem.php?problem=1140

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
    int t;
    si(t);
    while (t--) {
        cs++;
        solve();
    }
    return 0;
}

