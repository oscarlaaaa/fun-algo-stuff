// 2021-03-18
class Solution {
    public int singleNumber(int[] nums) {
        List<Integer> list = new ArrayList<Integer>();
        for (int i = 0; i<nums.length; i++) {
            Integer x = nums[i];
            if (list.contains(x)) {
                list.remove(x);
            } else {
                list.add(x);
            }
        }    
        return (int)list.get(0);
    }
}