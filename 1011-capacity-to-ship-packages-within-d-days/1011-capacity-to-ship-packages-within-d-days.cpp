class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int usedDays = 1, load = 0;

        for (int w : weights) {
            if (load + w > capacity) {
                usedDays++;
                load = 0;
            }
            load += w;
        }
        return usedDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, days, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};