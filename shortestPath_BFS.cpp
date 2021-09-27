//Finding shortest path using unit weights 

#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],vector<int> &dis,int start)
{
    queue<int> q1;
    dis[start]=0;
    q1.push(start);
    while(q1.empty()==false)
    {
        int temp=q1.front();
        q1.pop();
        for(auto it :adj[temp])
        {
            int cost=dis[temp]+1;
            if(cost<dis[it])
            {
                dis[it]=cost;
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

    vector<int> dis(n,INT_MAX);
    bfs(adj,dis,0);
    cout<<"The shortest distance is "<<endl;
    for(int i=0;i<dis.size();i++)
    {
        cout<<i<<"->"<<dis[i]<<endl;
    }

    return 0;
}
