class Solution {
public:
    int scoreOfString(string s) {
        int len = s.size();
        int ret = 0;
        for(int i=0;i<len-1;i++){
            int a = s[i];
            int b = s[i+1];
            ret+=abs(a-b);
        }
        return ret;
    }
};