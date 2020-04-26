#include<bits/stdc++.h>
#define pb push_back
using namespace std;
void bfs(int a,vector<int> v[],bool vis[],int parent[])
{

    queue<int> q;
    q.push(a);
    vis[a]=true;
    cout<<"BFS traversal of graph is"<<"\n";
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        int t=q.front();
        q.pop();
        for(int i=0;i<v[t].size();i++)
        {
            int b=v[t][i];
            if(!vis[b])
            {
                q.push(b);
                parent[b]=t;
                vis[b]=true;
            }
        }
    }


    return;
}
int main()
{
    int n,m;
    cout<<"Enter the no of vertices";
    cin>>n;
    cout<<"Enter the no of edges";
    cin>>m;
    vector<int> v[n+1];
    bool vis[n+1]={false};
    int parent[n+1]={0};
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    bfs(1,v,vis,parent);
    cout<<"\n";
    cout<<"Routing table is"<<"\n";

    for(int i=1;i<=n;i++)
    {
        printf("%2d ",i);
    }
    cout<<"\n";
    cout<<"   ";
    for(int i=2;i<=n;i++)
    {
        printf("%2d ",parent[i]);
    }

    return 0;
}
