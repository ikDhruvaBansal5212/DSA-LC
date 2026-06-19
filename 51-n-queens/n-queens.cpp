class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> res;

       combinations(board,0,0,n,res);
       return res;

    }

    void combinations(vector<vector<char>> &board,int row,int p , int n , vector<vector<string>> &res){
        if(p==n){
            vector<string> temp;
            for (int i = 0; i < n; i++) {
                temp.push_back(string(board[i].begin(), board[i].end()));
            }
            res.push_back(temp);
            return;
        }
       
        for(int j=0;j<n;j++){
            if(board[row][j]=='.' && isvalid(row,j,n,board)){
                    board[row][j]='Q';
                    combinations(board,row+1,p+1,n,res);
                    board[row][j]='.';
                }
            }
    
    }

     bool isvalid(int i, int j, int n, vector<vector<char>> &board) {
        // Check column
        for (int k = 0; k < i; k++) {
            if (board[k][j] == 'Q') return false;
        }

        // Diagonal (top-left)
        for (int r = i - 1, c = j - 1; r >= 0 && c >= 0; r--, c--) {
            if (board[r][c] == 'Q') return false;
        }

        // Diagonal (top-right)
        for (int r = i - 1, c = j + 1; r >= 0 && c < n; r--, c++) {
            if (board[r][c] == 'Q') return false;
        }

        return true;
    }
};