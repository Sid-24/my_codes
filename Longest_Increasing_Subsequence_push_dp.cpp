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


int main()
{
    ll n ;
    cin >> n ;

    ll arr[n] ;
    for(ll i=0; i<n; i++)
        cin >> arr[i] ;

   ll dp[n+1] ;

   dp[0] = 0 ;

   for(ll i=1; i<=n; i++)
   {
       dp[i] = 1 ;
   }

   for(ll i=0; i<n; i++)
   {
       for(ll j=i+1; j<n; j++)
       {
           if(arr[j] > arr[i])
           {
               dp[j+1] = max(dp[j+1],dp[i+1]+1) ;
           }
       }
   }

   ll ans=0 ;
   for(ll i=1; i<=n; i++)
   {
       ans = max(ans,dp[i]) ;
   }

   cout << ans << '\n' ;


   ll max_ele = -inf ;
   ll index ;
   vector<ll> v ;

   for(ll i=1; i<=n; i++)
   {
        if(dp[i] > max_ele)
        {
            max_ele = dp[i] ;
            index = i ;
        }
   }

   ll ele = max_ele-1 ;
   v.push_back(index-1) ;

   for(ll i=index-1; i>=1; i--)
   {
       if(dp[i] == ele)
       {
           v.push_back(i-1) ;
           ele-- ;
       }
   }

   sort(v.begin(),v.end()) ;

   for(ll i=0; i<v.size(); i++)
   {
       cout << arr[v[i]] << " " ;
   }

}
