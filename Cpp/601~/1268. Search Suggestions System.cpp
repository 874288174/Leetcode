class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        int n = searchWord.size();
        multiset<string> Myset(products.begin(), products.end());
        for (int i = 0; i < n; ++i) {
            char c = searchWord[i];
            vector<string> tmp;
            auto it = Myset.begin();
            while (it != Myset.end()) {
                if (it->size() < i || (*it)[i] != c) it = Myset.erase(it);
                else if(tmp.size() < 3) tmp.push_back(*it++);
                else it++;
            }
            res.push_back(tmp);
        }
        return res;
    }
};