// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>>ret;
        int len = pairs.size();
        if(len==0)return {};
        ret.push_back(pairs);
        for(int i=1;i<len;i++){
            for(int j=i;j>=1;j--){
                if(pairs[j].key<pairs[j-1].key){
                    swap(pairs[j],pairs[j-1]);
                }
                else{
                    break;
                }
            }
            ret.push_back(pairs);
        }
        return ret;
    }
};
