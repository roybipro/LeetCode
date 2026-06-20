class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string result = "";

    while (i >= 0 || j >= 0 || carry) {
        int total = carry;

        if (i >= 0) {
            total += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            total += b[j] - '0';
            j--;
        }

        result.push_back((total % 2) + '0');
        carry = total / 2;
    }

    reverse(result.begin(), result.end());
    return result;
    }
};