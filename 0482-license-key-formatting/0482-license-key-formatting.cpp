class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string clean = "";
        
        // Remove dashes and convert to uppercase
        for(char c : s) {
            if(c != '-') {
                clean += toupper(c);
            }
        }

        string result = "";
        int count = 0;

        // Build from the end
        for(int i = clean.size() - 1; i >= 0; i--) {
            if(count == k) {
                result += '-';
                count = 0;
            }
            result += clean[i];
            count++;
        }

        // Reverse to correct order
        reverse(result.begin(), result.end());
        return result;
    }
};