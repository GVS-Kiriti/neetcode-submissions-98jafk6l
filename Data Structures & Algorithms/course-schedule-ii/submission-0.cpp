class Solution {
public:
bool cycle = false;
    void dfs(vector<vector<int>>&neigh,vector<bool>&visited, int i, vector<int>&ret,unordered_set<int>&s){
        if(cycle)return;
        if(s.find(i)!=s.end()){
            cycle = true;
            return;
        }
        if(visited[i])return;
        visited[i]=true;
        s.insert(i);
        int len = neigh[i].size();
        for(int k=0;k<len;k++){
            dfs(neigh,visited,neigh[i][k],ret,s);
        }
        s.erase(i);
        ret.push_back(i);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>neigh(numCourses);
        for(auto x: prerequisites){
            neigh[x[0]].push_back(x[1]);
        }
        vector<int>ret;
        vector<bool>visited(numCourses);
        unordered_set<int>s;
        for(int i=0;i<numCourses;i++){
            cycle = false;
            dfs(neigh,visited,i,ret,s);
            if(cycle)return {};
        }
        return ret;
    }
};