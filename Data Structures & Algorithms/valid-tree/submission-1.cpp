class Solution {
public:
    bool cycle = false;
    void dfs(vector<vector<int>>&neigh,unordered_set<int>&check,int i, int p){
        if(cycle)return;
        if(check.find(i)!=check.end()){
            cout<<i<<endl;
            cycle =true;
            return;
        }
        check.insert(i);
        int len = neigh[i].size();
        for(int k=0;k<len;k++){
            if(neigh[i][k]==p)continue;
            dfs(neigh,check,neigh[i][k],i);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>neigh(n);
        int len = edges.size();
        for(auto k: edges){
            neigh[k[0]].push_back(k[1]);
            neigh[k[1]].push_back(k[0]);
        }
        unordered_set<int> check;
        dfs(neigh,check,0,-1);
        if(cycle)return false;
        return check.size()==n;
    }
};
