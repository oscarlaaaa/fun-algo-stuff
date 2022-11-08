import java.util.*;

// 2021-06-02
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        if (prerequisites.length == 0) return true;
        
        HashSet seen = new HashSet();
        for (int i = 0; i < numCourses; i++) {
            seen.add(i);
        }
        // remove courses that require prereqs
        for (int i = 0; i < prerequisites.length; i++) {
            seen.remove(prerequisites[i][0]);
        }
        
        boolean answer = true;
        for (int i = 0; i < numCourses; i++) {
            if (!seen.contains(i)) {
                HashSet<Integer> currentPath = new HashSet<Integer>();
                answer = answer && terminate(prerequisites, i, seen, currentPath);
            }
        }
        return answer;
    }
    
    private boolean terminate(int[][] relationships, int val, HashSet seen, HashSet<Integer> currentPath) {
        if (currentPath.contains(val)) return false;
        if (seen.contains(val)) return true;
        
        currentPath.add(val);
        
        for (int i = 0; i < relationships.length; i++) {
            if (relationships[i][1] == val && !seen.contains(relationships[i][0])) {
                val = relationships[i][0];
                return true && terminate(relationships, val, seen, currentPath);
            }
        }
        
        seen.add(val);
        return true;
    }
}