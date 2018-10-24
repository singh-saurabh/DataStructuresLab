#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cout<<"Number of nodes :"<<endl;
    cin>>n;
    vector<std::vector<int> > v(n + 1);
    ll vis[n + 1] = {0};
    ll mx = 0;
    ll mn = 0;
    std::vector<pair<int, int> > edges;
    for(ll i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        edges.push_back(make_pair(a, b));
        v[b].push_back(i);
        if(vis[a]==1 && vis[b]==1)
        {
            mx = a;
            mn = b;
        }
        vis[a] = 1;
        vis[b] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        if(v[i].size() == 2) {
            cout << edges[(max(v[i][0], v[i][1]))].first << " " << edges[(max(v[i][0], v[i][1]))].second << "\n";
            exit(0);
        }
    }
    cout<<mx<<"  "<<mn<<endl;
}
