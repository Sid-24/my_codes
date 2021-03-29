#include <bits/stdc++.h>

using namespace std;


int min(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}

void updateSegmentTree(int segment[],int lazy[],int start,int end,int delta,int low,int high,int pos)
{
    if(low > high)
        return ;

    if(lazy[pos] != 0)
    {
        segment[pos] = segment[pos]+lazy[pos] ;

        if(low != high) // it's not a leaf node
        {
            lazy[2*pos+1] += lazy[pos] ;
            lazy[2*pos+2] += lazy[pos] ;
        }

        lazy[pos] = 0 ;
    }

    // Now do current update

    // total overlap
    if( start <= low  && end >= high)
    {
        segment[pos] += delta ;

        if(low != high)
        {
            lazy[2*pos+1] += delta ;
            lazy[2*pos+2] += delta ;
        }

        return ;
    }

    //no overlap
    if(start > high || end < low )
    {
        return ;
    }

    //partial overlap

    int mid = (low+high)/2 ;

    updateSegmentTree(segment,lazy,start,end,delta,low,mid,2*pos+1) ;
    updateSegmentTree(segment,lazy,start,end,delta,mid+1,high,2*pos+2) ;

    segment[pos] = min(segment[2*pos+1],segment[2*pos+2]) ;



}


int minRangeQuery(int segment[],int lazy[],int qlow,int qhigh,int low,int high,int pos)
{
    if(low > high)
        return 1e9+10 ;

    if(lazy[pos] != 0)
    {
        segment[pos] += lazy[pos] ;

        if(low != high)
        {
            lazy[2*pos+1] += lazy[pos] ;
            lazy[2*pos+2] += lazy[pos] ;
        }

        lazy[pos] = 0 ;
    }


    // no overlap
    if(qlow > high || qhigh < low)
        return 1e9+10 ;

    //total overlap
    if(qlow <= low && qhigh >= high)
    {
        return segment[pos] ;
    }

    // partial overlap

    int mid = (low+high)/2 ;




    return min(minRangeQuery(segment,lazy,qlow,qhigh,low,mid,2*pos+1), minRangeQuery(segment,lazy,qlow,qhigh,mid+1,high,2*pos+2)) ;


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
    int lazy[x] ;

    memset(segment,1e9+10,sizeof(segment)) ;
    memset(lazy,0,sizeof(lazy)) ;

    constructSegment(arr,0,n-1,segment,0) ;

    updateSegmentTree(segment,lazy,2,2,-10,0,n-1,0) ;
    //updateSegmentTree(segment,lazy,0,2,11,0,n-1,0) ;

    int ans = minRangeQuery(segment,lazy,1,4,0,n-1,0) ;

    cout << ans << "\n" ;

}
