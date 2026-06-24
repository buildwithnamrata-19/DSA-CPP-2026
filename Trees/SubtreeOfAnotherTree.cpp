class Solution {
public:

    bool same(
        TreeNode* p,
        TreeNode* q) {

        if(!p && !q)
            return true;

        if(!p || !q)
            return false;

        if(p->val != q->val)
            return false;

        return same(
                   p->left,
                   q->left
               ) &&
               same(
                   p->right,
                   q->right
               );
    }

    bool isSubtree(
        TreeNode* root,
        TreeNode* subRoot) {

        if(root == nullptr)
            return false;

        if(same(root, subRoot))
            return true;

        return isSubtree(
                   root->left,
                   subRoot
               ) ||
               isSubtree(
                   root->right,
                   subRoot
               );
    }
};
