class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
    for(char m : moves) {
        if(m == 'U') y++;
        else if(m == 'D') y--;
        else if(m == 'L') x--;
        else if(m == 'R') x++;
    }
    return x == 0 && y == 0;
    }
};