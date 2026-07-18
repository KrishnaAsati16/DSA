#include <iostream>
#include <climits>
using namespace std;

#define N 4

int cost[N][N] = {
    {0,10,15,20},
    {10,0,35,25},
    {15,35,0,30},
    {20,25,30,0}
};

bool visited[N];
int ans = INT_MAX;

void tsp(int city, int count, int currCost)
{
    if(count == N)
    {
        ans = min(ans, currCost + cost[city][0]);
        return;
    }

    for(int i=0;i<N;i++)
    {
        if(!visited[i])
        {
            // Branch
            visited[i] = true;

            // Bound (simple pruning)
            if(currCost + cost[city][i] < ans)
            {
                tsp(i, count+1,
                    currCost + cost[city][i]);
            }

            // Backtrack
            visited[i] = false;
        }
    }
}

int main()
{
    visited[0] = true;

    tsp(0,1,0);

    cout<<"Minimum Cost = "<<ans;

    return 0;
}