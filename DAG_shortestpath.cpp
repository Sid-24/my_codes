#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

long int dist[100] ;
bool visited[100] ;
stack<int> mystack ;

void addEdge(vector<vector<pair<int,int>>> &adj,int u, int v,int wt)
{
    adj[u].push_back(make_pair(v,wt)) ;
    //adj[v].push_back(make_pair(u,wt)) ;
}

void topological(vector<vector<pair<int,int>>> adj,int s)
{
    if(visited[s] == false)
    {
        visited[s] = true ;
    }
    
    
    for(auto it=adj[s].begin(); it != adj[s].end(); it++)
    {
        if(visited[it->first] == false)
        {
            topological(adj,it->first) ;
        }
    }
    
    
    mystack.push(s) ;
    
}


void shortestPath(vector<vector<pair<int,int>>> adj,int src)
{
    dist[src] = 0 ;
    
    while(! mystack.empty())
    {
        int x = mystack.top() ;
        mystack.pop() ;
        
        if(dist[x] != INF)
        {
            for(auto it = adj[x].begin(); it != adj[x].end(); it++)
            {
                if(dist[it->first] > dist[x] + (it->second))
                    dist[it->first] = dist[x] + (it->second) ;
            }
        }
        
        //x = mystack.top() ;
        
    }
    
    for(int i=0; i<6; i++)
    {
        cout << dist[i] << " " ;
    }
    
    
}

int main()
{
    int V=6 ; // yeahhhhhh
    
    vector<vector<pair<int,int>>> adj(V) ;
    
    memset(visited,0,sizeof(visited)) ;
    
    for(int i=0; i<V; i++)
    {
        dist[i] = INF ;
    }
    
    
    addEdge(adj,0, 1, 5); 
    addEdge(adj,0, 2, 3); 
    addEdge(adj,1, 3, 6); 
    addEdge(adj,1, 2, 2); 
    addEdge(adj,2, 4, 4); 
    addEdge(adj,2, 5, 2); 
    addEdge(adj,2, 3, 7); 
    addEdge(adj,3, 4, -1); 
    addEdge(adj,4, 5, -2); 
    
    
    for(int i=0; i<V; i++)
    {
        if(visited[i] == false)
            topological(adj,i) ;
    }
    
    int src = 1 ;
    
    shortestPath(adj,src) ;
    

}
