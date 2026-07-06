class Solution {
public:
    int countElements(vector<int>& arr) {
        int len = arr.size();
        unordered_set<int>s;
        int ret = 0;
        for(int i=0;i<len;i++){
            s.insert(arr[i]);
        }
        for(int i=0;i<len;i++){
            if(s.count(arr[i]+1)!=0){
                ret++;
            }
        }
        return ret;
    }
};
