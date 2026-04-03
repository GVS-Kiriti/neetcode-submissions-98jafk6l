class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN)return 0;
        int ret = 0;
        int val = INT_MAX/10;
        bool check = false;
        if(x<0){
            check = true;
            x*=-1;
        }
        while(x!=0){
            if(ret>val)return 0;
            else if(ret==val){
                if(x<=7){
                    return 10*ret+x;
                }
                else return 0;
            }
            else{
                ret*=10;
                ret+=x%10;
                x=x/10;
            }
        }
        return (check)?-1*ret:ret;
    }
};
