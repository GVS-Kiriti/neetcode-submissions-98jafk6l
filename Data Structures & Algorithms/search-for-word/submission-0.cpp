class Solution {
public:
    bool traverse(vector<vector<char>>& board,string& word,int i, int r, int c){
        if(i==word.size()){
            return true;
        }
        int m = board.size();
        int n = board[0].size();
        if(r<0 || r>=m || c<0 || c>=n)return false;
        // if(visit[r][c])return false; 
        if(board[r][c]=='1')return false;
        if(word[i]!=board[r][c])return false;
        // visit[r][c]=true;
        char temp = board[r][c];
        board[r][c]='1';
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(int k=0;k<4;k++){
            int row = r+dir[k][0];
            int col = c+dir[k][1];
            if(traverse(board,word,i+1,row,col))return true;
        }
        board[r][c]=temp;
        // visit[r][c]=false;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        // vector<vector<bool>>visit(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(traverse(board,word,0,i,j))return true;
                }
            }
        }
        return false;;
    }
};