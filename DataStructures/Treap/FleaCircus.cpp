#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXN (100*1024)

struct node
{
    int l, r;
    int y, v;
    int sz, cnt;
    int rev;
};

struct node treap[MAXN];
int cur;

int newNode( int v )
{
    cur++;
    treap[cur].v = v;
    treap[cur].y = (rand() * rand() + rand()) & 0x7fffffff;
    treap[cur].sz = 1;
    treap[cur].cnt = v & 1;
    treap[cur].rev = 0;
    treap[cur].l = treap[cur].r = 0;
    return cur;
}

void push( int node )
{
    int l, r;
    if ( !treap[node].rev ) return;
    if ( (l = treap[node].r) != 0 ) treap[l].rev ^= 1;
    if ( (r = treap[node].l) != 0 ) treap[r].rev ^= 1;
    treap[node].l = l, treap[node].r = r, treap[node].rev = 0;
}

void update( int node )
{
    int next;
    treap[node].sz = 1;
    treap[node].cnt = treap[node].v & 1;
    if ( (next = treap[node].l) != 0 )
    {
        treap[node].sz += treap[next].sz;
        treap[node].cnt += treap[next].cnt;
    }
    if ( (next = treap[node].r) != 0 )
    {
        treap[node].sz += treap[next].sz;
        treap[node].cnt += treap[next].cnt;
    }
}

void merge( int *proot, int l, int r)
{
    if ( l != 0 ) push( l );
    if ( r != 0 ) push( r );
    if ( l == 0 )
        *proot = r;
    else if ( r == 0 )
        *proot = l;
    else if ( treap[l].y > treap[r].y )
    {
        merge( &treap[l].r, treap[l].r, r);
        *proot = l;
    }
    else
    {
        merge( &treap[r].l, l, treap[r].l);
        *proot = r;
    }
    update( *proot );
}

void split( int root, int *pl, int *pr, int x, int add)
{
    int key, l;
    if ( root == 0 )
    {
        *pl = *pr = 0;
        return;
    }
    push( root );
    key = 1 + add;
    if ( (l = treap[root].l) != 0 ) key += treap[l].sz;
    if ( x <= key )
    {
        split( l, pl, &treap[root].l, x, add);
        *pr = root;
    }
    else
    {
        split( treap[root].r, &treap[root].r, pr, x, key);
        *pl = root;
    }
    update( root );
}

int root;

void setNode( int id, int v)
{
    int a, b;
    split( root, &root, &a, id, 0);
    split( a, &a, &b, 2, 0);
    treap[a].v = v;
    update( a );
    merge( &root, root, a);
    merge( &root, root, b);
}

int getCnt( int l, int r)
{
    int a, b, cnt;
    split( root, &root, &a, l, 0);
    split( a, &a, &b, r - l + 2, 0);
    cnt = (a == 0) ? 0 : treap[a].cnt;
    merge( &root, root, a);
    merge( &root, root, b);
    return cnt;
}

void revNode( int l, int r)
{
    int a, b;
    split( root, &root, &a, l, 0);
    split( a, &a, &b, r - l + 2, 0);
    treap[a].rev ^= 1;
    merge( &root, root, a);
    merge( &root, root, b);
}


// https: //www.urionlinejudge.com.br/judge/en/problems/view/2529

int main( void )
{
    int n, q;
    srand( time( NULL ) );
    while ( scanf( "%d %d", &n, &q) == 2 )
    {
        int i;
        root = cur = 0;
        for ( i = 0; i < n; ++i)
        {
            int v;
            scanf( "%d", &v);
            merge( &root, root, newNode( v ));
        }
        for ( i = 0; i < q; ++i)
        {
            char code[16];
            int a, b;
            scanf( "%s %d %d", code, &a, &b);
            switch ( code[0] )
            {
            case 'S':
                setNode( a, b);
                break;
            case 'E':
                printf( "%d\n", b - a + 1 - getCnt( a, b));
                break;
            case 'O':
                printf( "%d\n", getCnt( a, b));
                break;
            case 'I':
                revNode( a, b);
                break;
            }
        }
    }
    return 0;
}
