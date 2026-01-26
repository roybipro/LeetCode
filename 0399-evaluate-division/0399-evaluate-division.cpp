class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    bool dfs(const string& src, const string& dst,
             unordered_set<string>& visited, double& result) {
        if (src == dst) return true;

        visited.insert(src);

        for (auto& [next, weight] : graph[src]) {
            if (visited.count(next)) continue;
            double prev = result;
            result *= weight;
            if (dfs(next, dst, visited, result)) return true;
            result = prev; // backtrack
        }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        vector<double> answers;

        for (auto& q : queries) {
            string src = q[0];
            string dst = q[1];

            if (!graph.count(src) || !graph.count(dst)) {
                answers.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;
            double result = 1.0;

            if (dfs(src, dst, visited, result))
                answers.push_back(result);
            else
                answers.push_back(-1.0);
        }

        return answers;
    }
};