class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int curr = 0;
        int len = shift.size();
        for(int i=0;i<len;i++){
            if(shift[i][0]==0)curr-=shift[i][1];
            else curr+=shift[i][1];
        }   
        string ret = s;
        int siz = s.size();
        if(curr<0){
            int a = (-1*curr)/siz;
            a++;
            curr+=a*siz;
        }
        else{
            curr%=siz;
        }
        for(int i=0;i<siz;i++){
            ret[(i+curr)%siz] = s[i];
        }
        return ret;
    }
};
