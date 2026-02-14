class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        string hexChars = "0123456789abcdef";
        string result = "";
        
        unsigned int n = num;  // handles negative numbers
        
        while (n != 0) {
            result = hexChars[n & 15] + result;
            n >>= 4;
        }
        
        return result;
    }
};