/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/
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


const int N = 10015;
int prime[N];
int Pf[N];
int mp[N];
vector<int> primes;

// void seive()
// {
//     //memset(prime, 0, sizeof(prime));
//     prime[0] = prime[1] = 1;
//     //for (int i = 4; i < N; i += 2) prime[i] = 1;

//     // Pf[2] = 2;
//     for (int i = 2; i * i < N; i++) {
//         if (prime[i] == 0) {
//             Pf[i] = i;
//             for (int j = 2 * i; j < N; j += i) {
//                 Pf[j] = i;
//                 prime[j] = 1;
//                 //dbg(j, i);
//             }
//         }
//     }
// }

void linear_sieve()
{
    for (int i = 2; i < N; i++) {
        if (Pf[i] == 0) {
            Pf[i] = i;
            primes.push_back(i);
        }
        int sz = primes.size();
        for (int j = 0; j < sz && i * primes[j] < N && primes[j] <= Pf[i]; j++)
            Pf[i * primes[j]] = primes[j];
    }
}

void primeFactorization(int x)
{
    while (x > 1) {
        //dbg(x);
        int p = Pf[x];
        //dbg(x, p);
        int cnt = 0;
        while (x % p == 0) {
            cnt++;
            x /= p;
        }
        mp[p] =  max(mp[p], cnt);
    }
}


int go(int x)
{
    int ret = 1;
    while (x > 1) {
        //dbg(x);
        int p = Pf[x];
        //dbg(p);
        int cnt = 0;
        while (x % p == 0) {
            x /= p;
            cnt++;
        }
        while (cnt > mp[p]) {
            cnt--;
            ret *= p;
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
    linear_sieve();
    // dbg(pr);
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        int n, m;
        cin >> n >> m;
        memset(mp, 0, sizeof mp);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            primeFactorization(x);
        }
        int ans = 1;
        int mx = -1;
        for (int i = m; i >= 1; i--) {
            int tm = go(i);
            if (tm >= mx) {
                ans = i;
                mx = tm;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
