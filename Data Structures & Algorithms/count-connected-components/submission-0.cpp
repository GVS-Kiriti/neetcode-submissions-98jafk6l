class Solution {
public:
    void dfs(vector<vector<int>>& neigh,vector<bool>& check, int i){
        if(check[i])return;
        check[i]=true;
        int len = neigh[i].size();
        for(int k=0;k<len;k++){
            dfs(neigh,check,neigh[i][k]);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int ret = 0;
        vector<bool>check(n,false);
        int len = edges.size();
        vector<vector<int>>neigh(n);
        for(auto x:edges){
            neigh[x[0]].push_back(x[1]);
            neigh[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++){
            if(!check[i]){
                dfs(neigh,check,i);
                ret++;
            }
        }
        return ret;
    }
};
