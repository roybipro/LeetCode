class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);   // tracks last index of each character
    int left = 0;
    int longest = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];

        if (last[c] >= left) {
            left = last[c] + 1;
        }

        last[c] = right;
        longest = max(longest, right - left + 1);
    }

    return longest;
    }
};