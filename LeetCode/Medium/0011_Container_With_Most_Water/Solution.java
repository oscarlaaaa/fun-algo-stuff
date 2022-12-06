
// 2021-06-20 
class Solution {
    public int maxArea(int[] height) {
        if (height.length == 2) return (height[0] < height[1] ? height[0] : height[1]);
        
        int right = height.length - 1;
        int left = 0;
        int curVol = 0;
        int maxVol = 0;
        
        
        while (left < right) {
            curVol = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
            
            if (curVol > maxVol) maxVol = curVol;
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            } 
        }
        return maxVol;
    }
}