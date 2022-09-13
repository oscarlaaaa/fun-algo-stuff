import java.util.*;

// 2021-06-24 (monotonic stack)
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Deque<Integer> temps = new ArrayDeque<Integer>();
        int[] output = new int[temperatures.length];
        for (int i = 0; i < output.length; i++) {
            while (temps.size() != 0 && temperatures[i] > temperatures[temps.getFirst()]) {
                output[temps.getFirst()] = i - temps.getFirst();
                temps.removeFirst();
            }
            temps.addFirst(i);
        }
        return output;
    }
}

// 2021-11-12
class Solution2 {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] daysUntilHotter = new int[temperatures.length];
        
        Deque<Integer> temps = new ArrayDeque<Integer>();
        Deque<Integer> indices = new ArrayDeque<Integer>();
        
        for (int i = 0; i < temperatures.length; i++) {
            
            while (temps.size() > 0 && temps.getLast() < temperatures[i]) {
                int index = indices.getLast();
                daysUntilHotter[index] = i - index;
                
                indices.removeLast();
                temps.removeLast();
            }
            
            temps.addLast(temperatures[i]);
            indices.addLast(i);
        }
        
        return daysUntilHotter;
    }
}