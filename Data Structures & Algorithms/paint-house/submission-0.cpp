class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int len = costs.size();
        for(int i=1;i<len;i++){
            costs[i][0]+=min(costs[i-1][1],costs[i-1][2]);
            costs[i][1]+=min(costs[i-1][2],costs[i-1][0]);
            costs[i][2]+=min(costs[i-1][0],costs[i-1][1]);
        }
        return min({costs[len-1][0],costs[len-1][1],costs[len-1][2]});
    }
};