class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int ret = nums[len-1];
        int count = 1;
        for(int i=len-2;i>=0;i--){
            if(nums[i]==ret){
                count++;
            }
            else{
                if(count==1)return ret;
                count = 1;
                ret = nums[i];
            }
        }
        if(count==1)return ret;
        return -1;
    }
};
