#include <iostream>
#include <climits>
using namespace std;

int n = 4;

int cost[4][4] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

bool visited[4];
int ans = INT_MAX;

void tsp(int city, int count, int currCost)
{
    if(count == n)
    {
        ans = min(ans, currCost + cost[city][0]);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            tsp(i, count + 1, currCost + cost[city][i]);
            visited[i] = false;
        }
    }
}

int main()
{
    visited[0] = true;
    tsp(0, 1, 0);

    cout << "Minimum Cost = " << ans;

    return 0;
}