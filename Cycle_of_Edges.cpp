#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int par[N];

int group_size[N];
int level[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }
}
int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union_by_level(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
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
    int count = 0;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        int leader1 = dsu_find(a);
        int leader2 = dsu_find(b);
        if (leader1 == leader2)
        {
            count++;
        }
        else
        {
            // dsu_union_by_size(a, b);
            dsu_union_by_level(a, b);
        }
    }
    cout << count << endl;
    return 0;
}