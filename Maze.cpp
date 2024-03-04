#include <bits/stdc++.h>
using namespace std;

const int N =1e3+4;

char mat[N][N];

vector<vector<pair<int, int>>> parent;
bool vis[N][N];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, m;


bool valid(int ci,int cj){
    return (ci >= 0 && ci < n && cj >= 0 && cj < m);
}

void bfs(int si,int sj)
{
    queue<pair<int, int>> q;

    q.push({si,sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        auto par = q.front();
        q.pop();
        int x = par.first;
        int y = par.second;

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (valid(new_x, new_y) && !vis[new_x][new_y] && mat[new_x][new_y] != '#')
            {
                vis[new_x][new_y] = true;
                q.push({new_x, new_y});
                parent[new_x][new_y] = {x, y};
                
            }
        }
    }
}

int main()
{

    pair<int, int> src, des;
    cin >> n >> m;
    parent.resize(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];

            if (mat[i][j] == 'R')
                src = {i, j};
            if (mat[i][j] == 'D')
                des = {i, j};
        }
    }
    memset(vis, false, sizeof(vis));
    
    bfs(src.first,src.second);
    
    if (vis[des.first][des.second])
    {
        vector < pair < int, int >> ans;
        des = parent[des.first][des.second];
        while (des.first != src.first || des.second != src.second)
        {
            ans.push_back(des);
            des = parent[des.first][des.second];
        }
        for (pair<int, int> child : ans)
        {
            int a = child.first;
            int b = child.second;
            mat[a][b] = 'X';
        }
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {

                cout << mat[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {

                cout << mat[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}