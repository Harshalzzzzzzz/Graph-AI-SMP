#include<bits/stdc++.h>
#define pb push_back
using namespace std;
bool bipartite(int s,bool vis[],vector<int> v[],int color[])
{
    vis[s]=true;
    color[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=0;i<v[t].size();i++)
        {
            int b=v[t][i];
            if(!vis[b])
            {
                vis[b]=true;
                if(color[t]==1)
                    color[b]=-1;
                else
                    color[b]=1;
                q.push(b);
            }
            else{
                if(color[b]==color[t])
                    return false;
                else
                    continue;
            }
        }
    }
    return true;
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
    int color[n+1]={0};
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    bool flag=bipartite(1,vis,v,color);
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
