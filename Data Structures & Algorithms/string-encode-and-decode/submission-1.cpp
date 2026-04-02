class Solution {
public:

    string encode(vector<string>& strs) {
        string ret="";
        ret+=to_string(strs.size());
        ret+=",";
        for(auto x: strs){
            ret+=to_string(x.size());
            ret+=",";
        }
        for(auto x: strs){
            ret+=x;
        }
        return ret;
    }

    vector<string> decode(string s) {
        int i=0;
        string temp="";
        while(s[i]!=','){
            temp+=s[i];
            i++;
        }
        i++;
        int len = stoi(temp);
        temp="";
        vector<string>ret(len);
        vector<int>v(len);
        for(int k=0;k<len;k++){
            while(s[i]!=','){
                temp+=s[i];
                i++;
            }
            v[k]=stoi(temp);
            temp="";
            i++;
        }
        for(int k=0;k<len;k++){
            ret[k]=s.substr(i,v[k]);
            i+=v[k];
        }
        return ret;
    }
};
