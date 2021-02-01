class Skiplist {
private:
    struct Node {
        int val;
        Node *right, *down;
        Node(int v, Node *r, Node *d): val(v), right(r), down(d) {}
    };
    
    Node *head;
    int level = 0;
   
public:
    Skiplist() : head(new Node(-1, nullptr, nullptr)) {}
    
    bool search(int target) {
        return find(target) != nullptr; 
    }
    
    void add(int num) {
        int h = 1;
        //随机找到一高度h, 在h层以下插入num
        while (h <= level && rand() & 1) ++h;
       
        if (h == level+1) {
            ++level;
            head = new Node(-1, nullptr, head);
        }
        Node* p = head, *pre = nullptr;
        
        for (int i = level; i > 0; --i) {
            while (p->right && p->right->val < num) p = p->right;
            if (i <= h) {
                p->right = new Node(num, p->right, nullptr);
                if (pre) pre->down = p->right;
                pre = p->right;
            }
            p = p->down;   
        }
    }
    
    bool erase(int num) {
        Node* p = find(num);
        if (!p) return false;
        Node* del = p->right;
        while (del) {
            while (p->right != del) p = p->right;
            auto tmp = del;
            p->right = del->right;
            del = del->down;
            p = p->down;
            delete tmp;
        }
        return true;
    }
    
    
    Node* find(int target) {
        Node* p = head;
        while (p) {
            while (p->right && p->right->val < target) p = p->right;
            if (p->right && p->right->val == target) return p;
            p = p->down;
        }
        return nullptr;        
    }
};