class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for_each (nums.begin(), nums.end(), [&](const int &i){
            v.push_back(to_string(i));
        });
        sort (v.begin(), v.end(), [](const string &a, const string &b){
            return a+b > b+a;
        });
        string res;
        for(auto &s : v) res += s;
        while (res.size() > 1 && res[0] == '0') res.erase(res.begin()); 
        return res;
    }
};