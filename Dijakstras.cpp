#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int V=9 ;

bool visited[9] ;
vector<vector<pair<int,int>>> adj(V) ;
int dist[9] ;

void addEdge(int u, int v, int wt)
{
    adj[u].push_back(make_pair(v,wt)) ;
    adj[v].push_back(make_pair(u,wt)) ;
}


void shortestPath(int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ;
    
    dist[src] = 0 ;
    pq.push(make_pair(0,src)) ;
    
    while(! pq.empty())
    {
        int u = pq.top().second ;
        pq.pop() ;
        
        if(visited[u] == false)
            visited[u] = true ;
        else
            continue ;
        
        for(auto it=adj[u].begin(); it!=adj[u].end(); it++)
        {
            int v = (*it).first ;
            int wt = (*it).second ;
            
            if(visited[v] == false && dist[v] > dist[u]+wt)
            {
                dist[v] = dist[u]+wt ;
                pq.push(make_pair(dist[v],v)) ;
                //visited[v] = true ;  // caution
            }
        }
        
    }
    
    // Print shortest distances stored in dist[] 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < V; ++i) 
        printf("%d \t\t %d\n", i, dist[i]); 
    
}


int main()
{
    for(int i=0; i<V; i++)
        dist[i] = INF ;
        
    memset(visited,false,sizeof(visited)) ;
    
    addEdge(0, 1, 4); 
    addEdge(0, 7, 8); 
    addEdge(1, 2, 8); 
    addEdge(1, 7, 11); 
    addEdge(2, 3, 7); 
    addEdge(2, 8, 2); 
    addEdge(2, 5, 4); 
    addEdge(3, 4, 9); 
    addEdge(3, 5, 14); 
    addEdge(4, 5, 10); 
    addEdge(5, 6, 2); 
    addEdge(6, 7, 1); 
    addEdge(6, 8, 6); 
    addEdge(7, 8, 7); 
  
    shortestPath(0); 

}
