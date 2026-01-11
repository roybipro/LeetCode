class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;

        int total = 0;
        int n = timeSeries.size();

        for (int i = 0; i < n - 1; i++) {
            total += min(duration, timeSeries[i + 1] - timeSeries[i]);
        }

        // Add duration for the last attack
        total += duration;

        return total;
    }
};