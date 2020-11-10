

class Skiplist {
private:
    struct node {
        int val;
        node *right, *down;
        node(int v, node *r, node *d): val(v), right(r), down(d) {}
    };
    
    node *head;
    int level = 0;
    
    

public:
    Skiplist() : head(new node(-1, nullptr, nullptr)) {
        srand(time(NULL));    
    }
    
    bool search(int target) {
        return find(target) != nullptr; 
    }
    
    void add(int num) {
        int h = 1;
        while (h <= level && rand() & 1) ++h;
        
        if (h == level+1) {
            ++level;
            head = new node(0, nullptr, head);
        }
        node* p = head, *pre = nullptr;
        
        for (int i = level; i; --i) {
            while (p->right && p->right->val < num) p = p->right;
            if (i <= h) {
                p->right = new node(num, p->right, nullptr);
                if (pre) pre->down = p->right;
                pre = p->right;
            }
            p = p->down;   
        }
    }
    
    bool erase(int num) {
        auto p = find(num);
        if (!p) return false;
        auto del = p->right;
        while (del) {
            while (p->right != del) p = p->right;
            auto t = del;
            p->right = del->right;
            del = del->down;
            p = p->down;
            delete t;
        }
        return true;
    }
    
    
    node* find(int target) {
        auto p = head;
        while (p) {
            while (p->right && p->right->val < target) p = p->right;
            if (p->right && p->right->val == target) {
                return p;
            }
            p = p->down;
        }
        return nullptr;        
    }
};