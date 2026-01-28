class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record;

        for (const string& op : ops) {
            if (op == "C") {
                record.pop_back();
            } 
            else if (op == "D") {
                record.push_back(2 * record.back());
            } 
            else if (op == "+") {
                int n = record.size();
                record.push_back(record[n - 1] + record[n - 2]);
            } 
            else {
                record.push_back(stoi(op));
            }
        }

        int sum = 0;
        for (int score : record) {
            sum += score;
        }

        return sum;
    }
};