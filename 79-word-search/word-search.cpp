class Solution {
public:
     bool exist(vector<vector<char> >& board, string word) {
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(solve(board,i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
    }

    bool solve(vector<vector<char> >& board,int i,int j, string word,int ind){
        if(i<0 ||j<0 ||i>=board.size() ||j>=board[0].size() || board[i][j]!=word[ind]){
            return false;
        }
        if(ind==word.size()-1){
            return true;
        }

        char temp=board[i][j];
        board[i][j]='#';

        bool found = solve(board,i+1,j,word,ind+1) ||
                     solve(board,i-1,j,word,ind+1) ||
                     solve(board,i,j+1,word,ind+1) ||
                     solve(board,i,j-1,word,ind+1) ;
        
        board[i][j]=temp;
        return found;



    }
};