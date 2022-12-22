// 2022-12-22 (double DFS approach)
class Solution {
public:
    int num;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        /*
            input: n nodes in a tree and edges of a tree
            output: list of length n where list[i] = sum of distances between that node and all other nodes

            notes:
            - the fact that its a tree might be important?
              - we can also just treat it as a graph? we might have to since there is a lot of up and down
            - thinking about some sort of prefix sum except with a graph
              - i.e. storing the sum of all distances within each node while traversing
            - with trees we can guarantee there are no cycles
            - we have an O(n^2) solution by performing BFS from each node and adding the traversal depth
              to a variable that holds that node's distance sum
            - BFS from one position, record distances, and adjust as we traverse thru?
              - TLEs
            - BFS travelling upwards from leaves?
              - store the sum of each child in each node (flow sums upwards)
                - can store using maps to be able to separate children
              - pass the sum of the top down (flow parent sums downwards)

            approach:
            - treat 0 as the root node
            - create adjacency list as if everything was a graph
            - DFS downwards to find the sums of each child node and store within their current distance sum
              - remove parent node (starting from 0) from the child node's list of children
              - sums can be passed up by summing the number of children + the children's sum + 1
              - store within maps in a vector
            - DFS downwards to send the sums of the parent + other children down each branch
              - the value we need to send would be:
              (current node's distance sum - the value the child brought to the distance sum) + (total num of nodes - the num of nodes in the child branch)
                - we do current distance sum - child's sum contribution since the child calculates its own distanceSum
                - we add (n - 1 - childCount) since that's how we calculate the additional distance added to our sum going deeper
                  into each child branch
              - add parent sum into each node
        */
        vector<unordered_map<int, int>> childCounts(n);
        vector<int> distanceSums(n);
        distanceSums = vector<int>(n);
        num = n;
        
        // create adjacency list
        for (vector<int>& edge : edges) {
            childCounts[edge[0]][edge[1]] = 0;
            childCounts[edge[1]][edge[0]] = 0;
        }

        findChildSumAndCount(childCounts, distanceSums, 0);
        findParentSumAndCount(childCounts, distanceSums, 0, 0);
        return distanceSums;
    }

    int findChildSumAndCount(vector<unordered_map<int, int>>& childCounts, vector<int>& distanceSums, int currentNode) {
        // aggregate total sum from children and total children count
        int totalSum = 0, totalChildren = 0;
        for (auto [child, _] : childCounts[currentNode]) {
            // remove parent from child's list of children
            childCounts[child].erase(currentNode); 

            auto childCount = findChildSumAndCount(childCounts, distanceSums, child);
            childCounts[currentNode][child] = childCount;

            // aggregate child results
            totalSum += distanceSums[child] + childCount + 1;
            totalChildren += childCount + 1;
        }
        // add sum from children into the node's distance sum
        distanceSums[currentNode] = totalSum;
        childCounts[currentNode][currentNode] = totalChildren;
        return totalChildren;
    }

    void findParentSumAndCount(vector<unordered_map<int, int>>& childCounts, vector<int>& distanceSums, int currentNode, int parentSum) {
        // add parent sum into current node's distance sum (finalizing the distance sum)
        distanceSums[currentNode] += parentSum;
        for (auto [child, count] : childCounts[currentNode]) {
            if (child == currentNode) 
                continue;
            
            // calculate new parent sum and send it downwards leggo
            int childContribution = distanceSums[child] + count + 1;
            int additionalDistance = num - 1 - count;
            int newParentSum = distanceSums[currentNode] - childContribution + additionalDistance;
            findParentSumAndCount(childCounts, distanceSums, child, newParentSum);
        }
    }
};
