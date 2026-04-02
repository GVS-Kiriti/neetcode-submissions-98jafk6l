class node{
public:
    vector<node*>v;
    bool end;
    node(){
        v = vector<node*>(26);
        end = false;
    }
};
class Solution {
public:
    vector<string>ret;
    void dfs(vector<vector<char>>& board,node* curr,int& rem,string& name,int r, int c){
        int m = board.size();
        int n = board[0].size();
        if(!curr)return;
        if(curr->end){
            ret.push_back(name);
            rem--;
            curr->end = false;
        }
        if(r<0 || r>=m || c<0 || c>=n)return;
        if(rem==0)return;
        if(board[r][c]=='1')return;
        char now = board[r][c];
        board[r][c]='1';
        name+=now;
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(int y=0;y<4;y++){
            int row = r+dir[y][0];
            int col = c+dir[y][1];
            dfs(board,curr->v[now-'a'],rem,name,row,col);
            if(rem==0)return;
        }
        board[r][c]=now;
        name.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        int len = words.size();
        node* root = new node();
        for(string x: words){
            node* temp = root;
            for(char c: x){
                if(!temp->v[c-'a']){
                    temp->v[c-'a']=new node();
                }
                temp = temp->v[c-'a'];
            }
            temp->end = true;
        }
        string name = "";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(board,root,len,name,i,j);
                if(len==0)return ret;
            }
        }
        return ret;
    }
};