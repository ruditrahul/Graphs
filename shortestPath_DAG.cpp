//Program to find the shortest path

#include<bits/stdc++.h>
using namespace std;

void topo_sort(vector<int> adj[],vector<bool> &vis,stack<int> &s,int node)
{
    vis[node]=true;
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            topo_sort(adj,vis,s,it);
        }
    }
    s.push(node);
}



int main()
{
    int n,e;
    cout<<"Enter the number of nodes and vertices:";
    cin>>n>>e;

    vector<int> adj[n];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }


    vector<bool> vis(n,false);
    vector<int> topo;

    //Find the topoSort of the DAG
    stack<int> s;
    topo_sort(adj,vis,s,0);

    int start=0;
    while(!s.empty())
    {
        topo.push_back(s.top());
        s.pop();
    }

    vector<int> dis(n,INT_MAX);
    dis[start]=0;

    for(int i=0;i<topo.size();i++)
    {
        int node=topo[i];
        for(auto it:adj[node])
        {
            int cost=dis[node]+1;
            if(cost<dis[it])
            {
                dis[it]=cost;
            }
        }
    }

    cout<<"The shortest distances are :"<<endl;
    for(int i=0;i<dis.size();i++)
    {
        cout<<i<<" "<<dis[i];
    }
    return 0;
}