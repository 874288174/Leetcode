class Solution {
public:
    bool detectCapitalUse(string a) {
        for(int i = 1; i < a.size(); i++) {
            if (isupper(a[1]) != isupper(a[i]) || islower(a[0]) && isupper(a[i])) 
                return false;
        }        
        return true;
    }
};