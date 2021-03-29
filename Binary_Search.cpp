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

ll binarysearch(ll a[], ll target, ll n)
{
    ll L = 0 ;
    ll R = n-1 ;

    while(L <= R)
    {
        ll mid = L + (R-L)/2 ;

        if(a[mid]*a[mid] == target)
        {
            return a[mid] ;
        }
        else if(a[mid]*a[mid] < target)
        {
            L = mid+1 ;
        }
        else
        {
            R = mid-1 ;
        }

    }

    return -1 ;
}



ll rotated_smallest(ll a[], ll n)
{
    ll L=0 ;
    ll R=n-1 ;
    ll last = a[n-1] ;
    ll ans ;

    while(L <= R)
    {
        ll mid = L + (R-L)/2 ;

        if(a[mid] > last)
        {
            L = mid+1 ;
        }
        else
        {
            ans = mid ;
            R = mid-1 ;
        }

    }

    return a[ans] ;

}


ll find_peak(ll a[], ll n)
{
    ll L=0 ;
    ll R=n-1 ;
    ll ans ;

    while(L <= R)
    {
        ll mid = L + (R-L)/2 ;

        if(mid==0 || a[mid] > a[mid-1])
        {
            ans = mid ;
            L = mid+1 ;
        }
        else
        {
            R = mid-1 ;
        }

    }

    return a[ans] ;

}


lld square_root(ll x)
{
    lld L=0 ;
    lld R=x ;
    lld epis = 0.000000001 ;

    while(R-L >= epis)
    {
        lld mid = L + (R-L)/2.0 ;

        if(mid*mid < x)
        {
            L = mid ;
        }
        else
        {
            R = mid ;
        }

    }

    return L + (R-L)/2.0 ;
}



int main()
{
 /*   ll n ;
    cin >> n ;

    ll a[n] ;

    for(ll i=0; i<n; i++)
    {
        cin >> a[i] ;
    }

    ll target ;
    cin >> target ;

    ll ans = binarysearch(a,target,n) ;

    if(ans == -1)
        cout << "NO" << '\n' ;
    else
        cout << "YES" << '\n' ; */

/*    ll arr[6] = {3,10,19,-1,1,2} ;
    ll x = rotated_smallest(arr,6) ;
    cout << x << '\n' ;             */

/*    ll arr[8] = {3,10,200,21,9,7,6,5} ;
    ll x = find_peak(arr,8) ;
    cout << x << '\n' ;  */


    lld ans = square_root(6) ;

    cout << ans << '\n' ;

}





/*
ll lowerbound()
{
    ll L=0 ;
    ll R=n-1 ;
    ll ans=-1 ;
    while(L <= R)
    {
        ll mid = L + (R-L)/2 ;

        if(a[mid] >= target)
        {
            ans = mid ;
            R = mid-1 ;
        }
        else
        {
            L = mid+1 ;
        }

    }

    return ans ;

}
*/














