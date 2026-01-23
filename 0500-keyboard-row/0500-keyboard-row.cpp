class Solution {
public:
    vector<string> findWords(vector<string>& words) {
     unordered_set<char> row1 = {'q','w','e','r','t','y','u','i','o','p'};
    unordered_set<char> row2 = {'a','s','d','f','g','h','j','k','l'};
    unordered_set<char> row3 = {'z','x','c','v','b','n','m'};
    
    vector<string> result;
    
    for (string word : words) {
        string lower = word;
        transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        
        unordered_set<char>* currentRow;
        
        if (row1.count(lower[0])) currentRow = &row1;
        else if (row2.count(lower[0])) currentRow = &row2;
        else currentRow = &row3;
        
        bool valid = true;
        for (char c : lower) {
            if (!currentRow->count(c)) {
                valid = false;
                break;
            }
        }
        
        if (valid) result.push_back(word);
    }
    
    return result;   
    }
};