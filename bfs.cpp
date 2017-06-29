#include <stdio.h>
#include <queue>
#include <vector>

#include "err_malloc.h"
#include "fatal.h"

#define INF -1

using std::vector;
using std::queue;

enum ERROR
{
    OK,
    BADARG,
    INVALIDARG
};

int bfs(vector< vector<int> > &g, vector<int> &dist, vector<int> &path, int v, int n)
{
   
    if ((path.size() != n) || (dist.size() != n))
        return BADARG;
    
    if ((n < 0) || (v > n) || (v < 0))
        return BADARG;

    queue<int> q;
    vector<bool> used(n, false);
 
    for (int i = 0; i < n; i++)
    {
        path[i] = INF;
        dist[i] = INF;
    }

    used[v] = true;
    dist[v] = 0;
    q.push(v);
    while (!q.empty())
    {
        int from = q.front();
        q.pop();
        for (size_t i = 0; i < g[v].size(); i++)
        {
            int to = g[from][i];
            if (!used[to])
            {
                used[to] = true;
                q.push(to);
                dist[to] = dist[from] + 1;
                path[to] = from;
            }
        }
    }

    return OK;
}

int main()
{
    int i, j;
    int n, m, start;

    // n - graph dim
    scanf("%d%d", &n, &start);
    start--;

    vector< vector<int> > graph(n);
    vector<int> path(n), dist(n);

    if (n < 0)
        fatal("Error: n must be positive");
    if (start < 0 || start > n)
        fatal("Error: 1<=start<=n");

    /* Graph Example 
         n = 6
       --------------
          3  3 4 6
          4  5 6
       --------------
                      */  

    for (i = 0; i < n; i++)
    {
        scanf("%d", &m);
        int tmp;
        for (j = 0; j < m; j++)
        {
            scanf("%d", &tmp);
            graph[i].push_back(tmp - 1);
        }
    }
    
    bfs(graph, dist, path, start, n);

    printf("dist:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);

    return 0;
}
