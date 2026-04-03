class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int a = left;
        int b = right;
        int num1 = 0;
        int num2 = 0;
        while(a!=0){
            a=a>>1;
            num1++;
        }
        while(b!=0){
            b=b>>1;
            num2++;
        }
        if(num1!=num2)return 0;
        int curr = left^right;
        int num3 = 0;
        while(curr!=0){
            curr=curr>>1;
            num3++;
        }
        int val = 1<<(num3);
        val-=1;
        val=~(val);
        return val&left;
    }
};