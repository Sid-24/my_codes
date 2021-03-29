#include <bits/stdc++.h>
using namespace std;

typedef long long ll ;
typedef long double lld ;

const ll mod = 1e9+7 ;
const ll inf = 1e17 ;

ll power(ll a, ll b)
{
    if(b==0)
        return 1 ;

    if(a==1)
        return 1 ;

    ll x = power(a,b/2) ;

    if(b%2 == 0)
        return (x*x) ;
    else
        return a*(x*x) ;
}

vector<ll> children[200005] ;
ll parent[200005], depth[200005] ;
ll up[200005][20] ;

void binary_lifting(ll cur, ll par, ll d)
{
    depth[cur] = d ;
    
    parent[cur] = par ;
    
    up[cur][0] = par ;
    
    for(ll i=1; i<20; i++)
    {
        if(up[cur][i-1] != -1)
            up[cur][i] = up[up[cur][i-1]][i-1] ;
        else
            up[cur][i] = -1 ;
    }
    
    for(ll next : children[cur])
    {
        binary_lifting(next, cur, d+1) ;
    }
    
}


ll lift_node(ll node, ll k)
{
    if(node == -1)
        return -1 ;
        
    if(k == 0)
        return node ;
    
    for(ll i=19; i>=0; i--)
    {
        if((1<<i) <= k)
            return lift_node(up[node][i], k-(1<<i)) ;
    }
    
}


ll LCA(ll a, ll b)
{
    if(a==b)
        return a ;
        
    if(parent[a] == parent[b])
        return parent[a] ;
        
    
    for(ll i=19; i>=0; i--)
    {
        if(up[a][i] != up[b][i])
        {
            a = lift_node(a,(1<<i)) ;
            b = lift_node(b,(1<<i)) ;
            return LCA(a,b) ;
        }
    }
    
}

int main()
{
    ll n,q ;
    cin >> n >> q ;
    
    
    for(ll i=1; i<=n-1; i++)
    {
        ll x ;
        cin >> x ;
        x-- ;
        children[x].push_back(i) ;
    }
    
    binary_lifting(0, -1, 0) ;
    
    for(ll i=0; i<q; i++)
    {
        ll a,b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        
        // lift node at same level 
        
        if(depth[a] > depth[b])
            a = lift_node(a,depth[a]-depth[b]) ;
        else
            b = lift_node(b,depth[b]-depth[a]) ;
        
        //cout << a << " " <<  b << endl ;
        
        cout << LCA(a,b)+1 << '\n' ;
        
    }
   
}
