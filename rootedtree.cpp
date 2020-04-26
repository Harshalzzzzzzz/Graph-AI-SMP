#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int rooted(int s,vector<int> v[],bool vis[],int weight[])
{
    vis[s]=true;
    int n=v[s].size();
    for(int i=0;i<n;i++)
    {
        int b=v[s][i];
        if(!vis[b])
        {
            vis[b]=true;
            weight[s]+=rooted(b,v,vis,weight);
        }
    }
    return weight[s];
}
int main()
{
    int n;
    cout<<"Enter the no of vertex of rooted tree";
    cin>>n;
    int weight[n+1],s[n+1];
    for(int i=1;i<=n;i++)
    {
      cin>>weight[i];
      s[i]=weight[i];
    }
    vector<int> v[n+1];
    bool vis[n+1]={false};
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    int d=rooted(1,v,vis,weight);
    for(int i=1;i<=n;i++)
    {
        cout<<weight[i]-s[i]<<" ";
    }

return 0;
}
