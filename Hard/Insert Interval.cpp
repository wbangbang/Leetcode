/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        //intervals can be empty!
        //if(intervals.empty()) return res;
        bool isInsert = false;
        for(int i = 0; i < intervals.size(); i++) {
            //newInterval has been inserted
            if(isInsert) {
                res.push_back(intervals[i]);
                continue;
            }
            //newInterval does not overlap with the current interval and is sooner than the current one
            if(newInterval.end < intervals[i].start) {
                res.push_back(newInterval);
                isInsert = true;
            }
            //newInterval overlaps with the current one
            if(intervals[i].start <= newInterval.end && intervals[i].end >= newInterval.start) {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
                continue;
            }
            //except the conditions above, just push the current interval into res
            res.push_back(intervals[i]);
        }
        if(!isInsert) res.push_back(newInterval);
        return res;
    }
};