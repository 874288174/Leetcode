/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    string serialize(Node* root) {
        if (!root) return "";
        string cur = to_string(root->val) + "[";
        for (auto &child : root->children){
            cur += serialize(child);
        }
        cur += "]";
        return cur;
    }
	
    Node* dfs(stringstream &ss) {
        int cur = 0;
        char c;
        while (ss >> c && c != '[') {
            cur = cur * 10 + (c - '0');
        }
        Node *node = new Node(cur);
        while (ss.peek() != ']') {
            node->children.push_back(dfs(ss));
        }
        ss >> c;
        return node;
    }

    
    Node* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream ss(data);
        return dfs(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));