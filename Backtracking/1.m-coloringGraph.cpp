Abdul Bari graph = https://www.youtube.com/watch?v=052VkKhIaQ4

Statement: We are given m-colors and to determine any one posibility not all 
if anyone is true it will safies


class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
        // your code here

    //   1. an undirected graph and an integer M
    //   2. The task is to determine if the graph can be colored with 
    //       at most M colors such  that no two adjacent vertices of the graph are 
    //       colored with the same color
    //     3.Here coloring of a graph means the assignment of colors to all vertices
    //     4. Print 1 if it is possible to colour vertices and 0 otherwise
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        int colorArray[101] = {0};
        return backtrack(0, graph,colorArray ,m, n);
        
    }
        
    bool backtrack(int vertex, bool graph[101][101], int colorArray[], int m, int n){
        if(vertex == n){
            return true;
        }
           
        for(int i = 1; i <= m; i++){
              
            if(safeColor(vertex, graph, colorArray, n, i)){
            //   if safecolor is found
                colorArray[vertex] = i;
            //  since color is true there by backtracking we will be called 
            //  so that next vertex to continue the coloring process 
            if(backtrack(vertex + 1, graph, colorArray, m, n)){
                return true;
            }
             // if safeColor is  not safe then 
              colorArray[vertex] = 0;
            }
          }
          return false;
        }
    bool safeColor(int vertex, bool graph[101][101], int colorArray[], int n, int color){
           for(int i = 0; i < n; i++){
               if(graph[vertex][i] && color == colorArray[i]){
                   return false;
               }
           }
           return true;
       }
};