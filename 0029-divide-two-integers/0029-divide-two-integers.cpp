class Solution {
public:
    int divide(int dividend, int divisor) {
        const int INT_MAX_VAL = INT_MAX;
        const int INT_MIN_VAL = INT_MIN;

        // Handle overflow
        if (dividend == INT_MIN_VAL && divisor == -1) {
            return INT_MAX_VAL;
        }

        // Determine sign
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long and take absolute values
        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long quotient = 0;

        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1;

            // Shift until it exceeds
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            quotient += multiple;
        }

        // Apply sign
        if (negative) quotient = -quotient;

        return (int)quotient;
    }
};