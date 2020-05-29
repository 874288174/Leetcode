class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char, int> m;
        for (auto &c : s)  m[c]++;
        set<pair<int, char>> st;
        for (auto &i : m)  st.insert({i.second, i.first});
        for (auto it = st.rbegin(); it != st.rend(); it++)  res += string(it->first, it->second);
        return res;
    }
};