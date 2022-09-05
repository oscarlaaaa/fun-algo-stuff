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

// 2022-09-05 (DFS)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> levelOrder;
        generateLevelOrder(root, 0, levelOrder);
        return levelOrder;
    }
    
    void generateLevelOrder(Node* root, int level, vector<vector<int>>& order) {
        if (!root) return;
        
        if (level >= order.size())
            order.push_back(vector<int>());
        
        order[level].push_back(root->val);

        for (Node* child : root->children) {
            generateLevelOrder(child, level+1, order);
        }
    }
};