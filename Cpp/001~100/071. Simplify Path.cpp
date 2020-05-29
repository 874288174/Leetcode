class Solution {
public:
    string simplifyPath(string path) {
        deque<string> My_deque;  
        if(path.back() != '/') path += '/';
        while (path != "/") {
            auto p = path.find('/'), q = path.find('/', p+1);
            string s = path.substr(p+1,q-p-1);
            if(s == ".." ) {
                if(!My_deque.empty()) 
                    My_deque.pop_back();
            }
            else if(s != "." && s != "") My_deque.push_back(s);
            path.erase(p, q-p);
        }
        if(My_deque.empty()) return "/";
        string res;
        while (!My_deque.empty()) {
           res += '/'+My_deque.front();
           My_deque.pop_front();
        }
        return res;
    }
};