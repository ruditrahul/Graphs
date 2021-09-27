

#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],vector<bool> vis,int node)
{
    queue<int> q1;
    q1.push(node);
    vis[node]=true;
    while(!q1.empty())
    {
        int temp=q1.front();
        q1.pop();
        cout<<temp<<" ";
        for(auto it:adj[temp])
        {
            if(!vis[it])
            {
                vis[it]=true;
                q1.push(it);
            }
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
    bfs(adj,vis,0);

    return 0;
}

