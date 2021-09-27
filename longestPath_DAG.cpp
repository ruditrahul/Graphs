#include <bits/stdc++.h>
using namespace std;

stack<int> s;

void topoSort(vector<pair<int,int>> adj[],vector<bool> vis,int node) {
    vis[node] = true;
    for(auto it:adj[node])
    {
        if(!vis[it.first])
        {
            topoSort(adj,vis,it.first);
        }
    }
    s.push(node);

}


void dfs(vector<pair<int,int>> adj[],vector<bool> visited,int node)
{
    visited[node]=true;
    for(auto it:adj[node])
    {
        if(!visited[it.first])
        {
            it.second=-1*it.second;
            dfs(adj,visited,it.first);
         }
            
    }
}


int main()
{
    int n,e;
    cout<<"Enter the number of nodes and edges :";
    cin>>n>>e;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<bool> visited(n,false);

    dfs(adj,visited,0);
    
    vector<bool> vis(n,false);
    topoSort(adj,vis,0);
    vector<int> dis(n,INT_MAX);
    int start=0;
    dis[s.top()]=0;

    while(!s.empty())
    {
        int temp=s.top();
        s.pop();
        for(auto it:adj[temp])
        {
            int cost=-1*(dis[temp]+it.second);
            if(cost<dis[it.first])
            {
                dis[it.first]=cost;
            }
        }
    }

    cout<<"The shortest distance is "<<endl;
    for(int i=0;i<dis.size();i++)
    {
        cout<<i<<"->"<<dis[i]*-1<<endl;
    }

    return 0;
}
