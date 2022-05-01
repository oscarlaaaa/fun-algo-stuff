// 2021-03-17
import java.util.*;

class Solution {
    private int findSection(String s) {
        int longest = 0;
        for (int i=0; i<=longest; i++) {
            Character x = s.charAt(i);
            if (s.lastIndexOf(x) > longest) {
                longest = s.lastIndexOf(x);
            }
        }
        return longest + 1;
    }
    
    public List<Integer> partitionLabels(String S) {
        int point = 0;
        List<Integer> answer = new ArrayList<Integer>();
        while (point < S.length()) {
            int section = findSection(S.substring(point));
            point += section;
            answer.add((Integer)section);
        } 
        return answer;
    }
}