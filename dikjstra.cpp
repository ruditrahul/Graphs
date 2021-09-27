//Finding the shortest path in a weighted undirected graph.


#include <bits/stdc++.h>
using namespace std;

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
        adj[v].push_back({u,w});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int start=0;
    vector<int> dis(n,INT_MAX);
    pq.push({0,0});
    dis[0]=0;
    while(!pq.empty())
    {
        auto temp=pq.top();
        pq.pop();
        int u=temp.first;
        int w=temp.second;
        if(w>dis[u])
        continue;
        for(auto it:adj[u])
        {
            int cost=dis[u]+it.second;
            if(cost<dis[it.first])
            {
                dis[it.first]=cost;
                pq.push({it.first,cost});
            }
        }
        
    }

    cout<<"The shortest distance is :"<<endl;
    for(int i=0;i<dis.size();i++)
    {
        cout<<i<<"->"<<dis[i]<<endl;
    }

    return 0;
    
}