#include<iostream>
using namespace std;

#define V 4  // number of vertices

// function to check if color is safe for vertex v
bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    // check all vertices
    for(int i=0; i<V; i++)
    {
        // agar adjacent hai aur same color hai to false return karo
        if(graph[v][i] && color[i]==c)
            return false;
    }
    return true;  // safe hai to true
}

// main function for graph coloring using backtracking
bool graphColoring(bool graph[V][V], int m, int color[], int v)
{
    // base case: agar sabhi vertices assign ho gaye
    if(v == V)
        return true;
    
    // try karenge har color ko vertex v ke liye
    for(int c=1; c<=m; c++)
    {
        // agar ye color safe hai
        if(isSafe(v, graph, color, c))
        {
            // assign karo color
            color[v] = c;
            
            // next vertex ke liye recursion call karo
            if(graphColoring(graph, m, color, v+1))
                return true;
            
            // backtrack karo agar solution nahi mila
            color[v] = 0;
        }
    }
    
    return false;  // solution nahi mila
}

int main()
{
    // adjacency matrix banate hain
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    
    int m = 3;  // 3 colors available hain
    int color[V] = {0};  // initially sab 0 hain
    
    // solve karo graph coloring problem
    if(graphColoring(graph, m, color, 0))
    {
        cout << "Solution Exists\n";
        cout << "\nColoring Assignment:\n";
        
        // print karo solution
        for(int i=0; i<V; i++)
        {
            cout << "Vertex " << i << " -> Color " << color[i] << endl;
        }
    }
    else
    {
        cout << "No Solution Found!\n";
    }
    
    return 0;
}