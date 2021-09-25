//
// Created by BrandonZu on 9/24/21.
//

#include "common.h"

// Runtime 96ms(>7%) | Memory Usage 28MB(>8%)
class Solution_MinHeap {
public:
    struct cmp {
        bool operator() (int a, int b) {
            return a > b;
        }
    };

    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&] (vector<int> a, vector<int> b) { return a[0] < b[0]; });
        priority_queue<int, vector<int>, cmp> minHeap;
        int cnt = 0;
        for(auto& cur: intervals) {
            if(minHeap.empty() || minHeap.top() > cur[0]) {
                cnt++;
                minHeap.push(cur[1]);
            }
            else {
                minHeap.pop();
                minHeap.push(cur[1]);
            }
        }
        return cnt;
    }
};

// Runtime 20ms(>60%) | Memory Usage 13.4MB(>25%)
class Solution_TreeMap {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> TreeMap;
        for(auto& cur: intervals) {
            TreeMap[cur[0]]++;
            TreeMap[cur[1]]--;
        }
        int cnt = 0;
        int ans = 0;
        for(auto& cur: TreeMap) {
            cnt += cur.second;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
