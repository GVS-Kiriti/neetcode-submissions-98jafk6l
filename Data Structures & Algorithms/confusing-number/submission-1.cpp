class Solution {
public:
    bool confusingNumber(int n) {
        string a = to_string(n);
        int len = a.size();
        string b = "";
        b.resize(len);
        unordered_map<char,char>umap;
        umap['0']='0';
        umap['1']='1';
        umap['6']='9';
        umap['9']='6';
        umap['8']='8';
        for(int i=0;i<len;i++){
            if(umap.find(a[i])==umap.end())return false;
            b[len-1-i]=umap[a[i]];
        }
        return !(a==b);
    }
};
