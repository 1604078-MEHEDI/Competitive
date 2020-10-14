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

/*
Compute the biggest power of 2 that is a divisor of x. Example: f(12) = 4
1 << __builtin_ctz(x)


Compute the smallest power of 2 that is not smaller than x. Example: f(12) = 16

1 << (32 - __builtin_clz (x - 1))

but this is UB (undefined behavior) for x≤1
so you'll often need an if for x==1.





--Find two workers that are best for the job — maximize the number of days when both these workers are available.
const int K = MAX_D / 64 + 1;
unsigned long long x[MAX_N][K];
int intersection(int i, int j) {
    int total = 0;
    for(int z = 0; z < K; z++) {
        total += __builtin_popcountll(x[i][z] & x[j][z]);
    }
    return total;


    same code using bitset:
    bitset<365> is a binary number with 365 bits available, and it supports most of binary operations. The code above changes into simple:

    bitset<MAX_D> x[MAX_N];
    int intersection(int i, int j) {
    return (x[i] & x[j]).count();}}


(***).
Note that the size of the bitset must be a constant number. You can't read n and then declare bitset<n> john;.
If n is up to 100, just create bitset<100>.



P1. Different numbers — You are given a sequence of N≤107 numbers, each from interval [0,109]. How many different values appear in the sequence? Don't use set or unordered_set because they quite slow.

Create bitset<1000000001> visited, mark every given number visited[x] = 1, and print visited.count(). The time complexity is O(N+MAX_X32), space is O(MAX_X32)

. This will use 128 MB memory (one billion bits).

Creating a boolean array instead would take 1GB because one element of this array takes the whole byte. Remember that bitset is more memory-optimized than a boolean array!

An alternative solution is to use vector<bool> b(1000000001) because it's memory-optimized too, so takes 128 MB. It doesn't have a count() method but it isn't necessary if you do if(!b[x]) { count++; b[x] = 1; }.



P2. Knapsack — You are given N≤1000 items, each with some weight wi. Is there a subset of items with total weight exactly W≤106?

**Instead of using a boolean array, let's use bitsets and binary shifting to get O(N⋅W32). You don't need to know bitsets to see how this would work for W≤32

and a bitmask unsigned long long can;, and here we just do it for a longer bitmask.

bitset<MAX_W> can;
int main() {
    int n, W;
    cin >> n >> W;
    can[0] = true;
    for(int id = 0; id < n; id++) {
        int x;
        cin >> x;
        can = can | (can << x); // or just: can |= (can << x);
    }
    puts(can[W] ? "YES" : "NO");




P3. Triangles in a graph — Given a graph with n≤2000 vertices and m≤n⋅(n−1)/2 edges, count triples of vertices a,b,c such that there are edges a−b, a−c and b−c.

** Hint: Represent adjacency of a vertex in bitmask.
*/
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
}
