// 2021-02-18
class Solution {
    public String restoreString(String s, int[] indices) {
        String[] hold = new String[indices.length];
        for (int i=0; i<indices.length; i++) {
            hold[indices[i]] = s.substring(i, i+1);
        }
        String answer = String.join("", hold);
        return answer;
    }
}