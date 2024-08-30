https: // haseebq.com/n-queens-visualizer/
Given : N queens and board n x n; eg 4x4 board will have 4Queen place them 

Basic schematic  block representation : 
Part I:
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    backtrack(,n);
    return ans;
}
 
 Part II:
//  queen traverse 
void backtrack(,int n){
//   base case :
   if(i == n){
    return;
   }
    for(int i = 1; i <= n; i++){
       if (isSafePosition()){
        assign currentQueen to that particular index "q";
        backtrack( ,i+1)
      }
    }
}

Part III:
// Position to be checked   from isSafeposition function 
bool isSafePsition(){
    if(anyQueen present diagonally , horizontally, vertically){
        return false;
    }
    return true;
  }
  ------------------------------------------------------------------------------------



vector<vector<string>>ans;
vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    backtrack(board,0,n);
    return ans;
}
//  queen traverse 
void backtrack(vector<string>& board, int row, int n){
//   base case : when row == number of queen
   if(row == n){
    ans.push_back(board);
    return;
   }
    for(int col = 0; col < n; col++){
       if (isSafePosition(board,col, row, n)){
           board[row][col]='Q';
           backtrack(board,row+1,n);
           board[row][col] = '.';
      }
    }
}

// Position to be checked   from isSafeposition function 
// taken "n " as a parameter because we have to check cond

bool isSafePosition(vector<string>& board,int col,int row, int n){
    // check the upper coloumn
    for(int i=0; i < row; i++){
        if(board[i][col] == 'Q') return false;
    }
    // check upper left Diagonal
    for(int i = row-1,j = col-1; i >=0 && j >=0; i--, j--){
        if(board[i][j] == 'Q') return false;
    }
    // check upper right Diagonal
    // here n is used
    for(int i= row-1,j = col+1; i>=0 && j<n; i--, j++){
        if(board[i][j] == 'Q') return false;
    }
    return true;
  }