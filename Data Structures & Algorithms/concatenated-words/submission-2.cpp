class node{
public:
    vector<node*>v;
    bool check;
    node(){
        v=vector<node*>(26);
        check=false;
    }
};
class Solution {
public:
    // bool isPoss2(node* n, string s,int idx){
    //     int len = s.size();
    //     if(idx==len)return true;
    //     node* temp=n;
    //     for(int i=idx;i<len;i++){
    //         char c = s[i];
    //         if(!temp->v[c-'a'])return false;
    //         temp=temp->v[c-'a'];
    //         if(temp->check && i!=len-1){
    //             if(isPoss(n,s,i+1))return true;
    //         }
    //     }
    //     if(!temp->check)return false;
    //     else{
    //         if(idx==0)return false;
    //         else return true;
    //     }
    // }
    bool isPoss(node* n, string s){
        node* temp = n;
        int len=s.size();
        vector<bool>dp(len+1,false);
        dp[len]=true;
        for(int i=len-1;i>=0;i--){
            temp=n;
            for(int j=i;j<len;j++){
                int c = s[j]-'a';
                if(!temp->v[c]){
                    dp[i]=false;
                    break;
                }
                temp=temp->v[c];
                if(temp->check && dp[j+1]){
                    if(i==0 && j==len-1)return false;
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        node* head=new node();
        node* temp=head;
        for(string s:words){
            temp=head;
            for(char c:s){
                if(!temp->v[c-'a'])temp->v[c-'a']=new node();
                temp=temp->v[c-'a'];
            }
            temp->check=true;
        }
        vector<string>ret;
        for(string s:words){
            if(isPoss(head,s))ret.push_back(s);
        }
        return ret;
    }
};