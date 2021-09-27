#include <bits/stdc++.h>
using namespace std;


void dfs(vector<int> adj[],vector<bool> &vis,int node) {
    vis[node]=true;
    cout<<node<<" ";
    for(auto it :adj[node])
    {
        if(!vis[it])
        {
            dfs(adj,vis,it);
        }
    }
}


int main()
{
    int n,e;
    cout<<"Enter the number of nodes and edges :";
    cin>>n>>e;
    vector<int> adj[n];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n,false);
    dfs(adj,vis,0);
    return 0;
}