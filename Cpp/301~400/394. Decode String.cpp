class Solution {
public:
    string decodeString(string s) {
        auto in = stringstream(s);
        return myDecodeString(in);
    }
    
private:
    string myDecodeString(stringstream& in) {
        string res;
        while (in.peek() != EOF && in.peek() != ']') {
            if (!isdigit(in.peek())) {
                char c;
                in >> c;
                res += c;
            }
            else {
                int number;
                in >> number;
                in.get();    
                string t = myDecodeString(in);
                in.get();
                while (number--) res += t;
            }
        }
        return res;
    }
};