class Solution {
public:
   string minWindow(string s, string t) {
      string res;
      vector<int> tab(256, 0), window(256,0);
      for(char &c: t) ++tab[c];

      int st = 0, cur = 0; 
      int minlen = INT_MAX, nums = 0;
    
      while (1) {
         while (cur < s.length() && nums < t.length()){
            int idx = s[cur++];
            if (tab[idx] > 0 && window[idx]++ < tab[idx])  ++nums;  
         }
         if (nums < t.length()) break;
         if (minlen > cur - st) {
             res = s.substr(st, cur-st);
             minlen = res.length();
         }
         int idx = s[st++];
         if (tab[idx] > 0 && --window[idx] < tab[idx]) --nums;  
      } 
      return res;  
   }
};