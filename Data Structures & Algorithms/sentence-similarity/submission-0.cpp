class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int len1 = sentence1.size();
        int len2 = sentence2.size();
        if(len1!=len2)return false;
        unordered_map<string,unordered_set<string>>umap;
        int len3 = similarPairs.size();
        for(int i=0;i<len3;i++){
            umap[similarPairs[i][0]].insert(similarPairs[i][1]);
            umap[similarPairs[i][1]].insert(similarPairs[i][0]);
        }
        for(int i=0;i<len1;i++){
            if(sentence1[i]==sentence2[i])continue;
            if(umap[sentence1[i]].count(sentence2[i])==0)return false;
        }
        return true;
    }
};
