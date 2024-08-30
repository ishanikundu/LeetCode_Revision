Approach 1:
Brute Force : Make the zero to -1


void setZeroes(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == 0){
                    markRow(i,c,matrix);
                    markColoumn(j,r,matrix);
                }
            }
        }
        for(int i = 0; i < r; i ++){
            for(int j = 0; j < c; j++){
                 if(matrix[i][j] == -1){
                    matrix[i][j] = 0;
                 }
            }
        }
    }
    void markRow(int r, int c, vector<vector<int>>& matrix){
        for(int i = 0; i < c; i++){
            if(matrix[r][i] != 0){
                matrix[r][i] = -1;
            }
        }
    }
    void markColoumn(int col, int r,vector<vector<int>>& matrix){
        for(int i = 0; i < r; i++){
            if(matrix[i][col] != 0){
                matrix[i][col] = -1;
            }
        }
    }

    but it will  fail for test case : 
                     Input: [[-1],[2],[3]]
                     OutPut: [[0],[-2],[3]]
                     expected: [[-1],[-2],[3]]

-----------------------------------------------------------------------------------------------------------------

Approach 2: Using extra space 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col = matrix[0].size();
        int row = matrix.size();
        vector<int>r(row,0);
        vector<int>c(col,0);
        for(int i = 0; i < row; i++){
            for(int j = 0; j  < col; j++){
                if(matrix[i][j] == 0){
                    r[i] = 1;
                    c[j] = 1;
                }
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if((r[i]==1 )|| (c[j] == 1)){
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};

