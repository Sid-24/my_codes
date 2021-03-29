#include <bits/stdc++.h>

using namespace std;


int min(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}

int minRangeQuery(int segment[],int qlow,int qhigh,int low,int high,int pos)
{
    if(qlow <= low && qhigh >= high )  // Total overlap
    {
        return segment[pos] ;
    }
    
    if(qhigh < low || qlow > high)  // No overlap
    {
        return 1e9+10 ;
    }
    
    int mid = (low+high)/2 ;
    
    return min(minRangeQuery(segment,qlow,qhigh,low,mid,2*pos+1),minRangeQuery(segment,qlow,qhigh,mid+1,high,2*pos+2)) ;
    
}

void constructSegment(int arr[],int low,int high,int segment[],int pos)
{
    if(low == high)
    {
        segment[pos] = arr[low] ;
        return ;
    }
    
    int mid = (low+high)/2 ;
    
    constructSegment(arr,low,mid,segment,2*pos+1) ;
    constructSegment(arr,mid+1,high,segment,2*pos+2) ;
    
    segment[pos] = min(segment[2*pos+1],segment[2*pos+2]) ;
    
}

int main()
{
    int arr[] = {1, 3, 2, 7, 9, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int y = ceil(log2(n)) ;
    int x = 2*((int)(0.5+pow(2,y)))-1 ;
    
    int segment[x] ;
    
    memset(segment,1e9+10,sizeof(segment)) ;
    
    constructSegment(arr,0,n-1,segment,0) ;
    
    int ans = minRangeQuery(segment,0,1,0,n-1,0) ;
    
    cout << ans << "\n" ;
    
}