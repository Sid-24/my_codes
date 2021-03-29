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

vector<ll> edges[200005] ;
ll visited[200005] ;
ll dist[200005] ;
ll max_ele ;

ll bfs(ll cur)
{
    
    memset(dist,0,sizeof(dist)) ;
    memset(visited,0,sizeof(visited)) ;
    max_ele = 0 ;
    ll node = 0 ;
    
    queue<ll> q ;
    q.push(cur) ;
    
    visited[cur] = 1 ;
    
    while(!q.empty())
    {
        ll x = q.front() ;
        q.pop() ;
        
        for(ll next : edges[x])
        {
            if(visited[next] == 0)
            {
                visited[next] = 1 ;
                q.push(next) ;
                dist[next] = dist[x]+1 ;
            }
            
            if(dist[next] > max_ele)
            {
                node = next ;
                max_ele = dist[next] ;
            }
            
        }
        
    }
    
    return node ;
    
}




int main()
{
    ll n ;
    cin >> n ;
    
    
    for(ll i=0; i<n-1; i++)
    {
        ll u,v ;
        cin >> u >> v ;
        u--,v-- ;
        edges[u].push_back(v) ;
        edges[v].push_back(u) ;
    }
    
    ll v = bfs(0) ;
    
    bfs(v) ;
    
    cout << max_ele << '\n' ;
}
