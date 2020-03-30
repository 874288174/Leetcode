/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        return f(head).first;
    }
private:
    pair<Node*, Node*> f(Node* head) {
        if (!head) return {nullptr, nullptr};
        auto p = f(head->next);
        Node *t = head;
        if (head->child) {
            auto q = f(head->child);
            head->child = nullptr;
            Union(head, q.first);
            t = q.second;
        }
        if (!p.first) return {head, t};
        Union(t, p.first);
        return {head, p.second};
    }

    void Union(Node *a, Node *b) {
        a->next = b;
        b->prev = a;
    }
};