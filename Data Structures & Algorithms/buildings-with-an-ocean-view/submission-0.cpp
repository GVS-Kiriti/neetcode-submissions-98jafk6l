class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<int>s;
        for(int i=0;i<heights.size();i++){
            while(!s.empty() && heights[s.top()]<=heights[i]){
                s.pop();
            }
            s.push(i);
        }
        int len = s.size();
        vector<int>ret(len);
        for(int i=len-1;i>=0;i--){
            ret[i]=s.top();
            s.pop();
        }
        return ret;
    }
};