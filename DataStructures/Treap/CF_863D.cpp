#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 200005
#define tc printf("Case %d: ", cs)
#define tcn printf("Case %d:\n", cs);
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define dbg4(w,x, y, z) cerr << #w << " = " << w << ", " <<#x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

#define gn(t, d) node[node[t].c[d]]

struct Treap
{
    int v, s, r, f;
    int c[2];
};

Treap node[maxn];
int sz;

void makeTree(int t)
{
    node[t].s = gn(t, 0).s + gn(t, 1).s + 1;
}

void Rotate(int &t, int d)
{
    int k = node[t].c[d ^ 1];
    node[t].c[d ^ 1] = node[k].c[d];
    node[k].c[d] = t;
    makeTree(t);
    makeTree(k);
    t = k;
}

void Init(int t, int v)
{
    Treap &n = node[t];
    n.v = v;
    n.r = rand();
    n.s = 1;
    n.c[0] = n.c[1] = 0;
    n.f = 0;
}

void PushDown(int t)
{
    if (node[t].f) {
        swap(node[t].c[0], node[t].c[1]);
        gn(t, 0).f ^= 1;
        gn(t, 1).f ^= 1;
        node[t].f = 0;
    }
}

void Insert(int &t, int p, int x)
{
    if (t == 0) {
        t = sz++;
        Init(t, x);
    }
    else {
        int m = gn(t, 0).s + 1;
        int d = 0;
        if (p > m) {
            p -= m;
            d = 1;
        }
        Insert(node[t].c[d], p, x);
        if (gn(t, d).r > node[t].r) Rotate(t, d ^ 1);
    }
    makeTree(t);
}

void Split(int t, int &l, int &r, int k)
{
    if (k == 0) {
        l = 0; r = t; return;
    }
    if (k == node[t].s) {
        l = t; r = 0; return;
    }
    PushDown(t);

    if (k <= gn(t, 0).s) {
        PushDown(node[t].c[0]);
        r = t;
        Split(node[r].c[0], l, node[r].c[0], k);
        makeTree(r);
    }
    else {
        PushDown(node[t].c[1]);
        l = t;
        Split(node[l].c[1], node[l].c[1], r, k - gn(t, 0).s - 1);
        makeTree(l);
    }
}

void Merge(int &t, int l, int r)
{
    if (!l) t = r;
    else if (!r) t = l;
    else if (node[l].r > node[r].r) {
        t = l;
        PushDown(t);
        Merge(node[t].c[1], node[t].c[1], r);
        makeTree(t);
    }
    else {
        t = r;
        PushDown(t);
        Merge(node[t].c[0], l, node[t].c[0]);
        makeTree(t);
    }
}

int a[maxn];

int Size = 0;

void Print(int t)
{
    if (t) {
        PushDown(t);
        Print(node[t].c[0]);
        a[++Size] = node[t].v;
        Print(node[t].c[1]);
    }
}

/// Circular right shift.
void CRshift(int &t, int l, int r)
{
// dbg3(t,l,r);
    int lp, rp, mid, MID;
    Split(t, lp, rp, l - 1);
    Split(rp, mid, rp, r - l + 1);
    Split(mid, MID, mid, r - l);

    Merge(mid, mid, MID);
    Merge(t, lp, mid);
    Merge(t, t, rp);
}

void Reverse(int &t, int l, int r)
{
    //dbg3(t, l, r);
    int lp, rp, mid;

    Split(t, lp, rp, l - 1);
    Split(rp, mid, rp, r - l + 1);
    node[mid].f ^= 1;
    Merge(t, lp, mid);
    Merge(t, t, rp);
}

///https://codeforces.com/contest/863/problem/D

int main()
{
    //FASTIO
    ///*
    //double start_time = clock();
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
//*/

    node[0].s = 0;
    sz = 1;
    int root = 0;

    int n, q, m, p;
    scanf("%d %d %d", &n, &q, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p);
        Insert(root, i, p);
        //dbg(p);
    }

    //dbg(q);
    for (int i = 1; i <= q; i++) {
        int cmd, l, r;
        scanf("%d %d %d", &cmd, &l, &r);
        //dbg3(i, l, r);
        if (cmd == 1) CRshift(root, l, r);
        else Reverse(root, l, r);
    }

    Print(root);

    for (int i = 1; i <= m; i++) {
        scanf("%d", &p);
        //dbg(p);
        printf("%d ", a[p]);
    }


    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
    return 0;
}
