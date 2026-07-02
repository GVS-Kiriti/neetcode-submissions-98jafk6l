class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.size();
        if(len!=t.size())return false;
        vector<int>v(129,-1);
        vector<bool>visit(129,false);
        for(int i=0;i<len;i++){
            int a = s[i];
            int b = t[i];
            if(v[a]==-1){
                if(visit[b])return false;
                v[a]=b;
                visit[b]=true;
            }
            else{
                if(v[a]!=b)return false;
            }
        }
        return true;
    }
};