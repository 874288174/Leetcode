/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/ 
int cnt = 0;
class Solution {
public:
    Node* intersect(Node* T1, Node* T2) {
        Node *T = new Node(false, false, nullptr, nullptr, nullptr, nullptr);
        if (T1->isLeaf && T2->isLeaf) {
            T->isLeaf = true;
            T->val = (T1->val || T2->val);
        } 
        else if (T1->isLeaf || T2->isLeaf) {
            if (!T1->isLeaf) swap(T1, T2);
            if (T1->val)  T->isLeaf = T->val = true;
            else T = T2;
        } 
        else {
            T->topLeft = intersect(T1->topLeft, T2->topLeft);
            T->topRight = intersect(T1->topRight, T2->topRight);
            T->bottomLeft = intersect(T1->bottomLeft, T2->bottomLeft);
            T->bottomRight = intersect(T1->bottomRight, T2->bottomRight);
        }
        if (!T->isLeaf && T->topLeft->val && T->topRight->val 
            && T->bottomLeft->val && T->bottomRight->val) {
            T->isLeaf = T->val = true;
        }
        return T;
    }
};