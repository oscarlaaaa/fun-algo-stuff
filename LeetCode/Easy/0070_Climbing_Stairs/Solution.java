import java.util.Map;
import java.util.HashMap;

//2021-07-14
class Solution {
    private Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    
    public int climbStairs(int n) {
        if (n <= 1) return 1;
        if (map.containsKey(n)) return map.get(n);
        
        map.put(n, (climbStairs(n-1) + climbStairs(n-2)));
        
        return map.get(n);
    }
}
