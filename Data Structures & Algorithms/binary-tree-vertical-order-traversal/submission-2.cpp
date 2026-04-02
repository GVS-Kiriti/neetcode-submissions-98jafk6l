/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxi;
    int mini;
    void traverse(TreeNode* root,unordered_map<int,vector<int>>&umap,int num){
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        TreeNode* temp;
        int pos;
        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                temp = q.front().first;
                pos = q.front().second;
                umap[pos].push_back(temp->val);
                maxi=max(maxi,pos);
                mini=min(mini,pos);
                q.pop();
                if(temp->left)q.push({temp->left,pos-1});
                if(temp->right)q.push({temp->right,pos+1});
            }
        }
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root)return {};
        unordered_map<int,vector<int>>umap;
        maxi=INT_MIN;
        mini = INT_MAX;
        traverse(root,umap,0);
        vector<vector<int>>ret(maxi-mini+1);
        for(int i=mini;i<=maxi;i++){
            ret[i-mini]=umap[i];
        }
        return ret;
    }
};