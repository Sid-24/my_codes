#include <bits/stdc++.h>
using namespace std;

typedef long long ll ;
typedef long double lld ;

const ll mod = 998244353 ;
const ll inf = 1e17 ;

ll power(ll a, ll b)
{
    if(b==0)
        return 1 ;

    if(a==1)
        return 1 ;

    ll x = power(a,b/2) ;

    if(b%2 == 0)
        return (x*x)%mod ;
    else
        return (a*((x*x)%mod))%mod ;
}

ll parent[6] ;
ll sz[6] ;

ll find(ll x)
{
    // with path compression
    return parent[x] = parent[x]==x ? x : find(parent[x]) ;
}

void Union(ll a, ll b)
{
    a = find(a) ;
    b = find(b) ;

    if(a==b)
        return ;

    if(sz[a] > sz[b])
    {
        parent[b] = a ;
        sz[a] += sz[b] ;
    }
    else
    {
        parent[a] = b ;
        sz[b] += sz[a] ;
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL) ;

    cout << setprecision(10) << fixed ;

    ll arr[5] = {1,2,3,4,5} ;

    // Make set for each element



    for(ll i=0; i<5; i++)
    {
        parent[arr[i]] = arr[i] ;
        sz[arr[i]] = 1 ;
    }

    Union(2,1) ;
    Union(2,3) ;
    Union(4,5) ;

    cout << find(2) << endl ;

    //Union(2,5) ;

    for(ll i=1; i<=5; i++)
        cout << find(i) << endl ;

}
