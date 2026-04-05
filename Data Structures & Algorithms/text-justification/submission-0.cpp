class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int len = words.size();
        vector<string>ret;
        // cout<<"ok"<<endl;
        string tot(maxWidth,' ');
        vector<int>nums;
        int count = 1;
        int last = 0;
        // int curr = words[0].size();
        ret.push_back(words[0]);
        for(int i=1;i<len;i++){
            // cout<<i<<endl;
            if(ret[last].size()+words[i].size()+1 <=maxWidth){
                ret[last]+=" ";
                ret[last]+=words[i];
                // curr+=words[i].size();
                count++;
            }
            else{
                nums.push_back(count);
                count=1;
                // curr=words[i].size();
                ret.push_back(words[i]);
                last++;
            }
        }
        nums.push_back(count);
        len = ret.size();
        int rem,a,b,siz,p;
        string fin;
        // cout<<len<<endl;
        for(int i=0;i<len-1;i++){
            fin = tot;
            rem = maxWidth - ret[i].size()+nums[i]-1;
            if(nums[i]==1){
                a=0;
                b=0;
            }
            else{
                a = rem/(nums[i]-1);
                b = rem%(nums[i]-1);
            }
            p = 0;
            siz = ret[i].size();
            for(int j=0;j<siz;j++){
                if(ret[i][j]!=' '){
                    fin[p] = ret[i][j];
                    p++;
                }
                else{
                    if(b!=0){
                        p+=a+1;
                        b--;
                    }
                    else{
                        p+=a;
                    }
                }
            }   
            ret[i]=fin;
        }
        siz = ret[len-1].size();
        fin = tot;
        for(int i=0;i<siz;i++){
            fin[i]=ret[len-1][i];
        }
        ret[len-1]=fin;
        return ret;

    }
};