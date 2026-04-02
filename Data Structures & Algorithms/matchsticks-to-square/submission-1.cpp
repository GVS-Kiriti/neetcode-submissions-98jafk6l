class Solution {
public:
    bool traverse(vector<int>& matchsticks,int idx,int sum,int w){
        int len = matchsticks.size();
        // cout<<idx<<sum<<endl;
        if(sum<0)return false;
        if(sum==0){
            if(idx==len)return true;
            sum = w;
        }
        bool ret = false;
        for(int i=idx;i<len;i++){
            if(i!=idx && matchsticks[i]==matchsticks[idx])continue;
            swap(matchsticks[i],matchsticks[idx]);
            ret = ret || traverse(matchsticks,idx+1,sum-matchsticks[idx],w);
            if(ret)return true;
        }
        for(int i=len-1;i>idx;i--){
            swap(matchsticks[idx],matchsticks[i]);
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int tot = 0;
        for(int x:matchsticks){
            tot+=x;
        }
        if(tot%4!=0)return false;
        sort(matchsticks.begin(),matchsticks.end());
        return traverse(matchsticks,0,tot/4,tot/4);
    }
};