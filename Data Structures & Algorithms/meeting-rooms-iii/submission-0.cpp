class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int len = meetings.size();
        priority_queue<int,vector<int>,greater<int>>rooms;
        for(int i=0;i<n;i++){
            rooms.push(i);
        }
        vector<int>ret(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>last;
        sort(meetings.begin(),meetings.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[0]==b[0])return a[1]<b[1];
            return a[0]<b[0];
        });
        for(int i=0;i<len;i++){
            int st = meetings[i][0];
            int en = meetings[i][1];
            //update the rooms
            while(!last.empty() && (last.top().first<=st)){
                rooms.push(last.top().second);
                last.pop();
            }
            if(!rooms.empty()){
                ret[rooms.top()]++;
                last.push({en,rooms.top()});
                // cout<<en<<","<<rooms.top()<<endl;
                rooms.pop();
            }
            else{
                pair<int,int>a = last.top();
                ret[a.second]++;
                last.pop();
                last.push({en+a.first-st,a.second});
                // cout<<en+a.first-st<<","<<a.second<<endl;
            }
        }
        int maxi = 0;
        for(int i=0;i<n;i++){
            // cout<<ret[i]<<endl;
            if(ret[i]>ret[maxi])maxi=i;
        }
        return maxi;
    }
};