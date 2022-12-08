struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-12-06 (recursive approach; slow due to repeated string creation)
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        /*
            input: a DFS on the root of the binary tree
            output: return the reconstructed tree root

            notes:
            - dashes before a number = depth of the node
            - could do recursively, as root of the node always has no dash behind it

            approach:
            - take the first value of the string as the root node
            - find first occurrence of '-' as the left traversal string, and second as right
            - delete single occurrences of '-' from the strings
            - create node, and point left/right to recursive results
            - return root
        */
        if (traversal == "") 
            return nullptr;

        int n = traversal.size();
        int start = traversal.find("-");  // find end of first number
        if (start == -1) 
            return new TreeNode(stoi(traversal));

        TreeNode* node = new TreeNode(stoi(traversal.substr(0, start)));
        string l = traversal.substr(start+1), r = "";
        for (int i=start+1; i<n-1 && r == ""; i++) {
            if (isSingleDash(traversal, i) && r == "") {
                l = traversal.substr(start+1, i-(start+1));
                r = traversal.substr(i+1);
            }
        }
        
        node->left = recoverFromPreorder(removeSingleDashes(l));
        node->right = recoverFromPreorder(removeSingleDashes(r));
        return node;
    }

    bool isSingleDash(string& s, int i) {
        return s[i-1] != '-' && s[i] == '-' && s[i+1] != '-';
    }

    string removeSingleDashes(string& s) {
        string output = "";
        for (int i=0; i<s.length(); i++) {
            if (i > 0 && s[i-1] != '-' && s[i] == '-') 
                continue;
            output += s[i];
        }
        return output;
    }
};

// 2022-12-06 (stack-approach)
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        /*
            input: a DFS on the root of the binary tree
            output: return the reconstructed tree root

            approach:
            - utilize a stack to hold the current root to leaf path we're on
            - iterate through the string
            - use dashes to count the depth, and convert non-dashes into a value
            - pop nodes until our path's depth is less than what our current node is
            - add our current node to the end's left if empty, else right
            - add current node to the stack
            - return the top value of the stack (note: although we pop it off, the nodes maintain
              the variable assignments, we just don't hold all of them within our stack)
        */
        int n = traversal.size();
        vector<TreeNode*> stack;
        
        int i = 0;
        while (i<n) {
            int depth = 0, val = 0;
            while (i<n && traversal[i] == '-') {
                depth++;
                i++;
            }
            while (i<n && traversal[i] != '-') {
                val = val*10 + traversal[i] - '0';
                i++;
            }
            while (stack.size() > depth) 
                stack.pop_back();
            
            TreeNode* node = new TreeNode(val);
            if (!stack.empty()) {
                if (!stack.back()->left) {
                    stack.back()->left = node;
                } else {
                    stack.back()->right = node;
                }
            }
            stack.push_back(node);
        }
        
        return stack[0];
    }
};