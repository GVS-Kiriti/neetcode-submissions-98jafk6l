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
    Node* traverse(Node* root,Node* p, Node* q){
        if(!root)return NULL;
        if(root->val==p->val)return p;
        if(root->val==q->val)return q;
        Node* a = traverse(root->left,p,q);
        Node* b = traverse(root->right,p,q);
        if(a&&b)return root;
        if(a)return a;
        if(b)return b;
        return NULL;
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* head=p;
        while(head->parent){
            head=head->parent;
        }
        return traverse(head,p,q);
    }
};