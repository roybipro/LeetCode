class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int prev = 0;

    for (int x : arr) {
        int missing = x - prev - 1;
        if (k <= missing) {
            return prev + k;
        }
        k -= missing;
        prev = x;
    }

    return prev + k;
    }
};