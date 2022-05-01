import java.util.*;

// 2021-06-28
class Solution {
    public int trap(int[] height) {
        
        int volume = 0;
        Deque<Integer> heights = new ArrayDeque<Integer>();
        Deque<Integer> positions = new ArrayDeque<Integer>();
        
        for (int i = 0; i < height.length; i++) {
            if (heights.size() == 1 && height[i] > heights.getFirst()) {
                heights.clear();
                heights.addFirst(height[i]);
                positions.addFirst(i);
            } else if (heights.size() == 0 || heights.getFirst() > height[i]) {
                heights.addFirst(height[i]);
                positions.addFirst(i);
            } else if (heights.getFirst() == height[i]) {
                positions.removeFirst();
                positions.addFirst(i);
            } else {
                while (heights.size() > 1 && heights.getFirst() <= height[i]) {
                    int bottom = heights.getFirst();
                    heights.removeFirst();
                    positions.removeFirst();
                    volume += (i - positions.getFirst() - 1) * Math.min((heights.getFirst() - bottom), 
                                                                    (height[i] - bottom));
                }
                --i;
            }
        }
        return volume;
    }
}
