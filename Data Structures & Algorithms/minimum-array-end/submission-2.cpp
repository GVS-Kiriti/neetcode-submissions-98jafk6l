class Solution {
public:
    long long minEnd(int n, int x) {
        long long ret = x;
        long long num = 1;
        int p = 0;
        long long k = n-1;
        while(k!=0){
            while((ret&(num<<p))!=0){
                p++;
            }
            ret|=((k&1)<<p);
            k>>=1;
            p++;
        }
        return ret;
    }
};