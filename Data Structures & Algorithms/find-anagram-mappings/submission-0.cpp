class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>umap;
        int len = nums1.size();
        vector<int>ret(len);
        for(int i=0;i<len;i++){
            umap[nums2[i]]=i;
        }
        for(int i=0;i<len;i++){
            ret[i] = umap[nums1[i]];
        }
        return ret;
    }
};
