class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() != '0') return false;
        vector<int> zero;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') 
                zero.push_back(i);
        }
        vector<bool> can(zero.size(), false);
        can[0] = true;
        
        for (int i = 0, j = 0; i < zero.size(); ++i) if (can[i]) {
            while (j < zero.size() && zero[j] - zero[i] < minJump) ++j;
            while (j < zero.size() && zero[j] - zero[i] <= maxJump) can[j++] = true;
        }
        return can.back();
    }
};
