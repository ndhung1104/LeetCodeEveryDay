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

class Solution {
public:
    void LRN(Node* pRoot, vector<int> &a)
    {
        if (pRoot)
        {
            for (int i = 0; i < pRoot->children.size(); i++)
                if (pRoot->children[i])
                    LRN(pRoot->children[i], a);
            a.push_back(pRoot->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int> a;
        LRN(root, a);
        return a;
    }
};