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
ll dp[N][N][2][2][2];
int vis[N][N][2][2][2];

ll go(int l, int r, int flag, int Start, int Big) {
    if (l > r) {
        if (!flag && Big) return 0;
        return 1;
    }
    ll &ret = dp[l][r][flag][Start][Big];
    int &v = vis[l][r][flag][Start][Big];
    if (v == Round) return ret;
    v = Round;
    ll tot = 0;
    ll limit = (!flag) ? digits[l] : 9;

    for (int i = 0; i <= limit; i++) {
        int nf = (flag == 0 && i == digits[l]) ? 0 : 1;
        if (!Start && i == 0)tot += go(l + 1, r, nf, 0, Big);
        else if (l == r) tot += go(l + 1, r, nf, Start | (i > 0), Big);
        else {
            if (i == digits[r])
                tot += go(l + 1, r - 1, nf, Start | (i > 0), Big);
            else
                tot += go(l + 1, r - 1, nf, Start | (i > 0), i > digits[r]);
        }
    }
    return ret = tot ;
}

ll misir(ll x) {
    if (x < 0)return 0;
    if (x <= 9) return x + 1;
    digits.clear();
    while (x) {
        digits.push_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
    // dbg(digits);
    nx = digits.size();
    ++Round;
    return go(0, nx - 1, 0, 0, 0);// + 1;
}


void solve() {
    //dbg(cs);
    sll(m, n);
    if (m > n)swap(n, m);
    // dbg(m, n);
    ll l = misir(m - 1);
    ll r = misir(n);
    // dbg(l,r);
    // return r - l;
    ll ans = r - l;
    printf("Case %lld: %lld\n", cs, ans);
}
///1205-PalindromicNumbers.cpp 
///http://lightoj.com/volume_showproblem.php?problem=1205
int main()
{
    //FAflagIO
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

