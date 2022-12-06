import java.util.*;

// 2022-07-21 (a weird queue approach)
class Solution {
    private Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    
    public int coinChange(int[] coins, int amount) {
        Deque<int[]> queue = new ArrayDeque<int[]>();
        queue.add(new int[]{amount, 0});
        
        int min = -1;
        
        while (!queue.isEmpty()) {
            int[] check = queue.getFirst();
            queue.removeFirst();

            if (check[0] < 0) continue;
            
            if (map.getOrDefault(check[0], Integer.MAX_VALUE) > check[1]) {
                map.put(check[0], check[1]);
            } else {
                continue;
            }
            
            if (check[0] == 0) {
                if (min == -1) {
                    min = check[1];
                } else {
                    min = Math.min(min, check[1]);
                }
            } else if (check[0] > 0) {
                for (int coin : coins) {
                    queue.add(new int[]{check[0] - coin, check[1] + 1});
                }
            }
        }
        
        return min;
    }
}