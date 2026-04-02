class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        vector<pair<int,int>>t;
        unordered_map<string,vector<string>>users;
        int len = username.size();
        for(int i=0;i<len;i++){
            t.push_back({timestamp[i],i});
        }
        sort(t.begin(),t.end());
        for(int i=0;i<len;i++){
            int idx = t[i].second;
            users[username[idx]].push_back(website[idx]);
        }
        unordered_map<string,int>umap;
        for(auto it:users){
            int siz = it.second.size();
            for(int k=0;k<siz-2;k++){
                string s="";
                for(int p=k;p<=k+2;p++){
                    s+=it.second[p];
                    s+='A';
                }
                // cout<<s<<endl;
                if(umap.find(s)==umap.end())umap[s]=1;
                else umap[s]++;
            }
        }
        int maxi = 0;
        string curr = "";
        for(auto it:umap){
            if(maxi<it.second){
                maxi=it.second;
                curr=it.first;
            }
            else if(maxi==it.second){
                curr=min(curr,it.first);
            }
        }
        vector<string>ret(3);
        int poi=0;
        for(int i=0;i<3;i++){
            int temp = poi;
            while(curr[temp]!='A'){
                temp++;
            }
            ret[i]=curr.substr(poi,temp-poi);
            poi=temp+1;
        }
        return ret;
    }
};