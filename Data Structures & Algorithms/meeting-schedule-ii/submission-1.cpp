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
    int minMeetingRooms(vector<Interval>& intervals) {
        int len = intervals.size();
        if(len==0)return 0;
        vector<Interval>v;
        sort(intervals.begin(),intervals.end(),[](const Interval& a, const Interval& b){
            if(a.start==b.start)return a.end < b.end;
            return a.start<b.start;
        });
        Interval temp = intervals[0];
        for(int i=1;i<len;i++){
            if(temp.end<=intervals[i].start){
                temp.end= intervals[i].end;
            }
            else{
                v.push_back(temp);
                temp = intervals[i];
            }
        }
        v.push_back(temp);
        priority_queue<int,vector<int>,greater<int>>q;
        len = v.size();
        q.push(v[0].end);
        for(int i=1;i<len;i++){
            if(q.top()<=v[i].start){
                q.pop();
                q.push(v[i].end);
            }
            else{
                q.push(v[i].end);
            }
        }
        return q.size();
    }
};














