#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, m;
char mat[N][N];
int vis[N][N];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool valid(int x, int y)
{
    return !vis[x][y] && mat[x][y] != -1 && x >= 0 && x < n && y >= 0 && y < m;
}

int dfs(int si, int sj)
{
    int area=0;
    vis[si][sj] = true;
    area++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + dx[i];
        int cj = sj + dy[i];
        if (valid(ci, cj) == true && mat[ci][cj] == '.' && vis[ci][cj] == false)
        {
            area+=dfs(ci, cj);
        }
    }
    return area;
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    int min_area = INT_MAX;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '.' && !vis[i][j])
            {
                
                int area=dfs(i, j);
                min_area = min(min_area, area);
            }
        }
    }

    if (min_area == INT_MAX)
    {

        cout <<"-1"<<endl;
    }
    else
    {
        cout <<min_area<<endl;
    }

    return 0;
}