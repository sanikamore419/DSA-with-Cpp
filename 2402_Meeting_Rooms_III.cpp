

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        // Min-heap for available rooms
        priority_queue<int, vector<int>, greater<int>> rooms;
        for (int i = 0; i < n; i++) rooms.push(i);

        // Min-heap for ongoing meetings {endTime, roomNumber}
        priority_queue<pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>> current;

        vector<int> count(n, 0);

        for (auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;

            // Free rooms that have completed
            while (!current.empty() && current.top().first <= start) {
                rooms.push(current.top().second);
                current.pop();
            }

            if (!rooms.empty()) {
                int room = rooms.top();
                rooms.pop();
                current.push({end, room});
                count[room]++;
            } else {
                auto [finishTime, room] = current.top();
                current.pop();
                current.push({finishTime + duration, room});
                count[room]++;
            }
        }

        // Find room with maximum meetings
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[ans]) {
                ans = i;
            }
        }
        return ans;
    }
};
