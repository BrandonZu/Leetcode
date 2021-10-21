//
// Created by BrandonZu on 10/20/21.
//

#include "common.h"

// Runtime 7ms(>83%) | Memory Usage 10MB(>40%)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, INT_MAX));
        // Init
        for(int i = 0; i < 3; i++) dp[0][i] = 0;
        for(int i = 1; i <= n; i++) {
            // Red
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
            // Green
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
            // Blue
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i - 1][2];
        }
        return min(min(dp[n][0], dp[n][1]), dp[n][2]);
    }
};
