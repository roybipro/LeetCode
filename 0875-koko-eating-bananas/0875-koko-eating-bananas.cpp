class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long hours = 0;

            for (int bananas : piles) {
                // ceil(bananas / mid)
                hours += (bananas + mid - 1) / mid;
            }

            if (hours <= h) {
                ans = mid;          // valid speed
                right = mid - 1;    // try slower
            } else {
                left = mid + 1;     // need faster
            }
        }
        return ans;
    }
};