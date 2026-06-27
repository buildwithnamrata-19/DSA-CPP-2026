class Solution {
public:

    unordered_map<int,int> mp;

    TreeNode* build(vector<int>& preorder,
                    int preStart,
                    int preEnd,
                    vector<int>& inorder,
                    int inStart,
                    int inEnd) {

        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int idx = mp[root->val];
        int leftSize = idx - inStart;

        root->left = build(preorder,
                           preStart + 1,
                           preStart + leftSize,
                           inorder,
                           inStart,
                           idx - 1);

        root->right = build(preorder,
                            preStart + leftSize + 1,
                            preEnd,
                            inorder,
                            idx + 1,
                            inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(preorder,
                     0,
                     preorder.size() - 1,
                     inorder,
                     0,
                     inorder.size() - 1);
    }
};
