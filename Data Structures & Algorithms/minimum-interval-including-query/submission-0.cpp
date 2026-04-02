class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int lenq = queries.size();
        int leni = intervals.size();
        vector<pair<int,int>>v(lenq);
        vector<int>ret(lenq);
        for(int i=0;i<lenq;i++){
            v[i]={queries[i],i};
        }
        sort(v.begin(),v.end());
        sort(intervals.begin(),intervals.end());
        int j = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<lenq;i++){
            while(j<leni && intervals[j][0]<=v[i].first){
                pq.push({intervals[j][1]-intervals[j][0]+1,intervals[j][0]});
                j++;
            }
            while(!pq.empty()){
                pair<int,int>p = pq.top();
                if(v[i].first > p.second+p.first-1){
                    pq.pop();
                }
                else{
                    ret[v[i].second] = p.first;
                    break;
                }
            }
            if(pq.empty()){
                ret[v[i].second] = -1;
            }
        }
        return ret;

    }
};
