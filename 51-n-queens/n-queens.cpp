class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;

        vector<int> leftrow(n,0), upperdiag(2*n-1,0), lowerdiag(2*n-1,0);

       solve(board,0,0,n,res,leftrow,upperdiag,lowerdiag);
       return res;

    }

    void solve(vector<string> &board,int row,int p , int n , vector<vector<string>> &res,vector<int>&leftrow,vector<int> &upperdiag,vector<int> &lowerdiag){
        if(p==n){
            res.push_back(board);
            return;
        }
       
        for(int j=0;j<n;j++){
            if(leftrow[j]==0 && lowerdiag[row+j]==0 && upperdiag[n-1+j-row]==0){

                board[row][j]='Q';
                leftrow[j]=1 ;
                lowerdiag[row+j]=1;
                upperdiag[n-1+j-row]=1;

                solve(board,row+1,p+1,n,res,leftrow,upperdiag,lowerdiag);

                board[row][j]='.';
                leftrow[j]=0 ;
                lowerdiag[row+j]=0;
                upperdiag[n-1+j-row]=0;

            }
        
    
    }

     /* bool isvalid(int i, int j, int n, vector<vector<char>> &board) {
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
    } */
    }
};