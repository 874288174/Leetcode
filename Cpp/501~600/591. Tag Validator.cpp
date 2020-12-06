class Solution {
public:
    bool f(const string &code, int &i, string &t) {
      while (i < code.size() && code[i] != '>') {
          if (!isupper(code[i])) return false;
          t += code[i++];
        }
        if (i == code.size()  || code[i] != '>') return false;
        if (t.size() < 1 || t.size() > 9) return false;
        return true;
    }

    bool isValid(string code) {
      int n = code.size();
      stack<string> stk;
      for (int i = 0; i < n; ++i) {
        if (code[i] == '<') {
          if (code[++i] == '/') {
            string t;
            if (!f(code, ++i, t)) return false;
            if (stk.empty() || stk.top() != t) return false;
            stk.pop();
            if (stk.empty() && i != n-1) return false; 
          }
          else if (code[i] == '!') {
            if (stk.empty()) return false;
            auto p = code.find("![CDATA[" , i);
            auto q = code.find("]]>" , i);
            if (p != i || q == string::npos) return false;
            i = q+2;
          }
          else {
            string t;
            if (!f(code, i, t)) return false;
            stk.push(t);
          }
        }
        else if (stk.empty()) return false;
      }
      return stk.empty();
    }
};







class Solution {
public:
    bool isValid(string code) {
        regex cdata("<!\\[CDATA\\[.*?\\]\\]>"), tag("<([A-Z]{1,9})>[^<]*</\\1>");
        code = regex_replace(code, cdata, "c");
        string pre = code;
        while (pre != (code = regex_replace(code, tag, "t")) ) pre = code;
        return "t" == code;
    }
};