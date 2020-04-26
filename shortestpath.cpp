#include<bits/stdc++.h>
#define pb push_back
using namespace std;
void bfs(int a,vector<int> v[],bool vis[],int parent[])
{
    queue<int> q;
    q.push(a);
    vis[a]=true;
    while(!q.empty())
    {
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
    int n,m,t,se;
    cout<<"Enter the no of vertices";
    cin>>n;
    cout<<"Enter the no of edges";
    cin>>m;
    cout<<"Enter the source vertex";
    cin>>se;
    cout<<"Enter the target vertex";
    cin>>t;
    cout<<"Enter the edges";
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
    bfs(se,v,vis,parent);
        stack<int> s;
        s.push(t);
        while(s.top()!=se)
        {
            int l=parent[t];
            s.push(l);
            t=l;
        }
        cout<<"Shortest path:\n";
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }

    return 0;
}
