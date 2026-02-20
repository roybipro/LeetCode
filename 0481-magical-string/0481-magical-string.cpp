class Solution {
public:
    int magicalString(int n) {
        if (n <= 3) return 1;
        
        string s = "122";
        int count = 1;   // already one '1'
        int i = 2;       // pointer to read group size
        char next = '1'; // next number to append
        
        while (s.size() < n) {
            int times = s[i] - '0';
            
            for (int j = 0; j < times && s.size() < n; j++) {
                s += next;
                if (next == '1') count++;
            }
            
            next = (next == '1') ? '2' : '1';
            i++;
        }
        
        return count;
    }
};