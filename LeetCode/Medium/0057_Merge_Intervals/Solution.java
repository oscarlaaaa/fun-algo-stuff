import java.util.*;

// 2021-09-08
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        if (intervals.length == 0) {
            int[][] output = new int[1][2];
            output[0][0] = newInterval[0];
            output[0][1] = newInterval[1];
            return output;
        }
        List<int[]> outputList = new ArrayList<int[]>();
        boolean inserted = false;
        for (int i = 0; i < intervals.length; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (!inserted) {
                if (newInterval[0] >= start && newInterval[0] <= end || newInterval[0] <= start && newInterval[1]                       >= start) {
                    start = Math.min(newInterval[0], intervals[i][0]);
                    end = Math.max(newInterval[1], intervals[i][1]);
                    while (i + 1 < intervals.length && end >= intervals[i + 1][0]) {
                        end = Math.max(end, intervals[i+1][1]);
                        i++;
                    }
                    inserted = true;
                } else if (newInterval[1] < start) {
                    outputList.add(newInterval);
                    inserted = true;
                }
            }
            outputList.add(new int[]{start, end});
        }
        if (!inserted) {
            outputList.add(newInterval);
        }
        int[][] outputArray = new int[outputList.size()][2];
        for (int i = 0; i < outputList.size(); i++) {
            outputArray[i][0] = outputList.get(i)[0];
            outputArray[i][1] = outputList.get(i)[1];
        }
        return outputArray;
    }
}