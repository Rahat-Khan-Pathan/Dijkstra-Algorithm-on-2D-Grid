// Question link - https://www.hackerrank.com/contests/xpsc-final-contest-a-batch-04/challenges/mina-and-jungle

#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define pii pair<pi,ll>
using namespace std;
const ll N = 1005;
ll a[N][N];
ll dis[N][N];
bool vis[N][N];
ll n, m;

vector<pi> d = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
bool valid(ll i, ll j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
class cmp
{
    public:
    bool operator()(pii a,pii b)
    {
        return a.second > b.second;
    }
};
void dijkstra(ll si,ll sj)
{
    priority_queue<pii,vector<pii>,cmp> pq;
    pq.push({{si,sj},0});
    dis[si][sj]=0;
    vis[si][sj]=true;
    while(!pq.empty())
    {
        pii parent = pq.top();
        pq.pop();
        pi parentNode = parent.first;
        ll parentcost = parent.second;
        vis[parentNode.first][parentNode.second]=true;
        for(pi child: d)
        {
            ll xi=parentNode.first+child.first;
            ll xj=parentNode.second+child.second;
            if(valid(xi,xj) && a[xi][xj]!=0 && !vis[xi][xj] && parentcost+a[xi][xj]<dis[xi][xj])
            {
                dis[xi][xj]=parentcost+a[xi][xj];
                pq.push({{xi,xj},dis[xi][xj]});
            }
        }
    }
}
int main()
{
    ll t;
    cin >> t;
    ll cs=1;
    while (t--)
    {
        cin >> n >> m;
        ll si, sj, di, dj;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                dis[i][j]=1e18;
                vis[i][j]=false;
                cin >> a[i][j];
                if (a[i][j] == -1)
                {
                    si = i;
                    sj = j;
                }
                if (a[i][j] == -2)
                {
                    di = i;
                    dj = j;
                }
            }
        }
        
        dijkstra(si, sj);
        if(dis[di][dj]==1e18) 
        cout<<"Case "<<cs++<<": Impossible"<<endl;
        else cout<<"Case "<<cs++<<": "<<dis[di][dj]+2<<endl;
    }
    return 0;
}