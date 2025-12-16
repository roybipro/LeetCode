class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cand1 = 0, cand2 = 1; // different initial values
        int cnt1 = 0, cnt2 = 0;

        // First pass: find potential candidates
        for (int x : nums) {
            if (x == cand1) {
                cnt1++;
            } else if (x == cand2) {
                cnt2++;
            } else if (cnt1 == 0) {
                cand1 = x;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                cand2 = x;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        // Second pass: verify counts
        cnt1 = cnt2 = 0;
        for (int x : nums) {
            if (x == cand1) cnt1++;
            else if (x == cand2) cnt2++;
        }

        vector<int> result;
        if (cnt1 > n / 3) result.push_back(cand1);
        if (cnt2 > n / 3) result.push_back(cand2);

        return result;
    }
};