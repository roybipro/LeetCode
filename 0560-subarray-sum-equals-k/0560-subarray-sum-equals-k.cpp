class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;  // prefix sum zero occurs once before starting

        int prefix = 0;
        int count = 0;

        for (int x : nums) {
            prefix += x;

            // check if there's a previous prefix that makes a subarray sum to k
            if (freq.find(prefix - k) != freq.end()) {
                count += freq[prefix - k];
            }

            freq[prefix]++;
        }

        return count;
    }
};