/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool func(const pair<int,int>&a,const pair<int,int>&b){
        if(a.first==b.first)return a.second<b.second;
        return a.first<b.first;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        int len = intervals.size();
        vector<pair<int,int>>v;
        for(int i=0;i<len;i++){
            v.push_back({intervals[i].start,1});
            v.push_back({intervals[i].end,-1});
        }
        sort(v.begin(),v.end(),func);
        int curr = 0;
        int ret = 0;
        for(int i=0;i<(2*len);i++){
            curr+=v[i].second;
            if(curr>ret)ret=curr;
        }
        return ret;
    }
};
