/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<int>s;
        while(p){
            s.insert(p->val);
            p=p->parent;
        }
        while(q){
            if(s.count(q->val)!=0)return q;
            q=q->parent;
        }
        return NULL;
    }
};