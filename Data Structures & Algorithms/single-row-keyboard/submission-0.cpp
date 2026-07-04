class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char,int>umap;
        for(int i=0;i<26;i++){
            umap[keyboard[i]]=i;
        }
        int len = word.size();
        int curr = 0;
        int ret = 0;
        for(int i=0;i<len;i++){
            ret+=abs(curr-umap[word[i]]);
            curr = umap[word[i]];
        }
        return ret;
    }
};
