class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int len = word.size();
        string temp = "";
        for(char c: abbr){
            if(c>='a' && c<='z'){
                if(temp!=""){
                    i+=stoi(temp);
                    temp="";
                }
                if(i>=len)return false;
                if(c!=word[i])return false;
                i++;
            }
            else{
                if(temp=="" && c=='0')return false;
                temp+=c;
            }
        }
        if(temp!=""){
            i+=stoi(temp);
            temp="";
            if(i!=len)return false;
        }
        return true;

    }
};