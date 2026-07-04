class Solution {
public:
    bool canPermutePalindrome(string s) {
        int len = s.size();
        vector<int>v(26,0);
        for(char c:s){
            v[c-'a']++;
        }
        bool odd = false;
        for(int i=0;i<26;i++){
            if(v[i]%2==0)continue;
            if(odd==true)return false;
            odd = true;
        }
        return true;

    }
};
