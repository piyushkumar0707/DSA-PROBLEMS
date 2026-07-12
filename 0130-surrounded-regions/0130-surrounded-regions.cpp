class Solution {
public:

    void dfs(vector<vector<char>>& board, int r, int c){
        int m=board.size();
        int n=board[0].size();
        if(r<0 || r>=m || c<0 || c>=n)return;
        if(board[r][c]!='O')return; //agar 0 nhi to dfs nhi chalega
        board[r][c]='S'; //safe mark

        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
        dfs(board, r, c-1);

    }



    void solve(vector<vector<char>>& board) {
        int m= board.size();
        int n=board[0].size();
        for(int i=0; i<m; i++){
            if(board[i][0]=='O')dfs(board, i,0);
            if(board[i][n-1]=='O') dfs(board, i, n-1);
        }
        for(int j=0; j<n; j++){
            if(board[0][j]=='O') dfs(board,0,j);
            if(board[m-1][j]=='O')dfs(board, m-1,j);
        }


        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O')board[i][j]='X'; //flip 
                else if(board[i][j]=='S')board[i][j]='O'; //safe restore
            }
        }
        
    }
};