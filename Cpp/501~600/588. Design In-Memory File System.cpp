class FileSystem {
public:
    FileSystem() {}
    
    vector<string> ls(string path) {
        auto p = f(path);
        if (!p->content.empty()) return {path.substr(path.rfind('/')+1)};
        vector<string> res;
        for (auto &i : p->dir) res.emplace_back(i.first);
        return res; 
    }
    
    void mkdir(string path) {
        f(path);
    }
    
    void addContentToFile(string path, string content) {
        auto p = f(path);
        p->content += content;
    }
    
    string readContentFromFile(string path) {
        auto p = f(path);
        return p->content;
    }

private:
    string content;
    map<string, FileSystem*> dir;

    FileSystem *f(string path) {
        for (auto &c : path) if (c == '/') c = ' ';
        stringstream ss(path);
        auto p = this;
        while (ss >> path) {
            if (!p->dir.count(path)) {
                p->dir[path] = new FileSystem();
            }
            p = p->dir[path];
        }
        return p;
    }
};