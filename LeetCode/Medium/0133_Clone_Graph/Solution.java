import java.util.*;

// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}

// 2021-10-13
class Solution {
    private static Map<Integer, Node> seen;
    
    public Node cloneGraph(Node node) {
        seen = new HashMap<Integer, Node>();
        return cloneNode(node, seen);
    }
    
    public Node cloneNode(Node node, Map<Integer, Node> seen) {

        if (node == null) return node;
        if (seen.containsKey(node.val)) {
            return seen.get(node.val);
        }
        
        Node clone = new Node(node.val);
        seen.put(node.val, clone);
        for (Node neighbor : node.neighbors) {
            Node x = cloneNode(neighbor, seen);
            clone.neighbors.add(x);
        }
        
        return clone;
    }
}