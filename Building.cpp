#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int par[N];
long long int group_size[N];
long long int level[N];

class Edge
{
public:
   long long int u, v, w;
    Edge(long long int u,long long int v,long long int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

void dsu_initialize(long long int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }
}
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int dsu_find(long long int node)
{
    if (par[node] == -1)
        return node;
    long long int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_union_by_level(int node1, int node2)
{
    long long int leaderA = dsu_find(node1);
    long long int leaderB = dsu_find(node2);
    if (level[leaderA] > level[leaderB])
    {
        par[leaderB] = leaderA;
    }
    else if (level[leaderB] > level[leaderA])
    {
        par[leaderA] = leaderB;
    }
    else
    {
        par[leaderA] = leaderB;
        level[leaderB]++;
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_initialize(n);
    vector<Edge> list;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        list.push_back(Edge(a, b, c));
    }
    sort(list.begin(), list.end(), cmp);
    long long int cost = 0;
    long long int comp = n;
    for (Edge ed : list)
    {
        int leaderU = dsu_find(ed.u);
        int leaderV = dsu_find(ed.v);
        if (leaderU != leaderV)
        {
            dsu_union_by_level(ed.u, ed.v);
            cost += ed.w;
            comp--;
            if (comp == 1)
            {
                break;
            }
        }
    }
    if(comp>1){
        cout<<"-1"<<endl;
    }
    else{
        cout<<cost<<endl;
    }
    return 0;
}