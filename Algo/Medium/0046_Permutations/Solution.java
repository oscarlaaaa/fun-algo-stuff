// 2022-06-22 (recursive backtracking)
class Solution {
    
    private List<List<Integer>> output;
    
    private void permDigit(List<Integer> nums, int spot, List<Integer> branch) {
        
        // base-case; if we've seen every number, then add the branch to our output.
        if (nums.size() == 0) 
            output.add(branch);
        
        // create a new branch if we're currently on the first digit place
        if (spot == 0) branch = new ArrayList<Integer>();
        
        // iterate every number that's available; send clones with the taken number into recursion 
        for (int i = 0; i < nums.size(); i++) {
                
                // cloning each element before sending down
                List<Integer> copybranch = new ArrayList<Integer>(branch);
                List<Integer> copylist = new ArrayList<Integer>(nums);
                
                // adding/removing used number to clones
                copybranch.add(nums.get(i));
                copylist.remove(nums.get(i));
                
                permDigit(copylist, spot + 1, copybranch);
        }
    }
    
    public List<List<Integer>> permute(int[] nums) {
        
        // convert nums into convertable form for arraylist
        Integer[] output1 = Arrays.stream(nums).boxed().toArray(Integer[]::new);
        
        // initialize assets
        output = new ArrayList<List<Integer>>();
        List<Integer> numlist = Arrays.asList(output1);
        
        // recursion
        permDigit(numlist, 0, null);
        
        return output;
    }
}