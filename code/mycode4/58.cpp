

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#define  N 1000004
#define  INF 1000000000
using namespace std ;

struct node
{
    int to ;
    int val ;
    int next ;
}p[N] ;
int head[N] , h[N] , d[N] ;
bool vist[N] ;
int dis[N] , n , m , pre[N] ;
queue<int>q ;

void init()
{
    memset( head , -1 , sizeof ( head )) ;
    memset( h , -1 , sizeof ( h )) ;
    memset( vist , false , sizeof ( vist )) ;
    for ( int i = 0 ; i <= n ; i++ )
    {
        pre[i] = -1 ;
        dis[i] = INF ;
    }
    while( !q.empty()) q.pop();
    m = 0 ;
}

void add( int x , int y , int z )
{
    p[m].to = y ;
    p[m].val = z ;
    p[m].next = head[x] ;
    head[x] = m++ ;
}

void Spfa( int s )
{
    dis[s] = 0 ;
    vist[s] = true ;
    q.push( s ) ;
    int u , v , i ;

    while ( !q.empty())
    {
        u = q.front() ;
        q.pop();
        vist[u] = false ;

        for ( i = head[u] ; i != -1 ; i = p[i].next )
        {
            v = p[i].to ;
            if ( dis[v] > dis[u] + p[i].val )
            {
                dis[v] = dis[u] + p[i].val ;
                pre[v] = u ;
                if( !vist[v] )
                {
                    vist[v] = true ;
                    q.push( v ) ;
                }
            }
        }
    }
}

void output( int x )
{
    if ( x == -1 )
    return ;
    output( pre[x] ) ;
    if ( d[pre[x]] == d[x] )
    return ;
    if( pre[x] == -1 )
    printf ( "%d" , d[x] ) ;
    else
    printf ( " %d" , d[x] ) ;
}

int main()
{
    int i , k ;

    while ( scanf ( "%d" , &n ) != EOF )
    {
        init() ;
        for ( i = 0 ; i < n - 1 ; i++ )
        add( i , i + 1 , 1 ) ;

        for ( i = 0 ; i < n ; i++ )
        {
            scanf ( "%d" , &d[i] ) ;
            k = d[i] ;
            if ( h[k] != -1 )
            {
                add( h[k] , i , 0 );
            }
            h[k] = i ;
        }
        for(int i = 0; i < n - 1; i++){
            cout <<"s = " << i << "--->";
            for(int j = head[i]; j != -1; j = p[j].next){
                cout <<"t  " << p[j].to << " w " << p[j].val << " --- >" ;
            }
            cout << endl;
        }

        Spfa( 0 ) ;
        output( n - 1 ) ;
        printf( "\n" ) ;
    }
    return 0 ;
}