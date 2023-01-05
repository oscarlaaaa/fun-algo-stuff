// 2022-09-17 (stack)
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer, Integer> nextLargest = new HashMap<>();
        Deque<Integer> stack = new ArrayDeque<Integer>(); // only holds values from high to low (at top)
        
        for (int num : nums2) {
            // while the current value is greater than the top of our stack, record down as next largest and pop
            while (stack.size() > 0 && stack.peek() < num) {
                nextLargest.put(stack.peek(), num);
                stack.pop();
            }
            stack.push(num);
        }
        
        int[] nextGreaters = new int[nums1.length];
        Arrays.fill(nextGreaters, -1);
        for (int i=0; i<nums1.length; i++) {
            if (nextLargest.containsKey(nums1[i])) {
                nextGreaters[i] = nextLargest.get(nums1[i]);
            }
        }
        return nextGreaters;
    }
}