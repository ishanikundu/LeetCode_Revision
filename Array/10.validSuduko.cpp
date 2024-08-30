Approach 1: Brute Force
step1: check for row 9x9
step 2: check for coloumn 9x9
step 3. check for 3x3 matrix 

bool isValidSudoku(vector<vector<char>> &board)
{
    // part 1: Each Row must contain the digits 1-9 without repeatation

    for (int row = 0; row < 9; row++)
    {
        set<char> st_row;
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == '.')
                continue;
            if (st_row.find(board[row][col]) != st_row.end())
            {
                return false;
            }
            st_row.insert(board[row][col]);
        }
    }

    //    part 2: Each Coloumn must contain the digits 1-9 without repeation
    for (int col = 0; col < 9; col++)
    {
        set<char> st_col;
        for (int row = 0; row < 9; row++)
        {
            if (board[row][col] == '.')
                continue;
            if (st_col.find(board[row][col]) != st_col.end())
            {
                return false;
            }
            st_col.insert(board[row][col]);
        }
    }
    // 3x3 box
    for (int row = 0; row < 9; row += 3)
    {
        for (int col = 0; col < 9; col += 3)
        {
            // use function to check
            if (!validBox(board, row, col))
            {
                return false;
            }
        }
    }
    return true;
}
bool validBox(vector<vector<char>> &board, int row, int col)
{
    set<char> st;
    for (int i = row; i < row + 3; i++)
    {
        for (int j = col; j < col + 3; j++)
        {
            if (board[i][j] == '.')
                continue;
            if (st.find(board[i][j]) != st.end())
            {
                return false;
            }
            st.insert(board[i][j]);
        }
    }
    return true;
}