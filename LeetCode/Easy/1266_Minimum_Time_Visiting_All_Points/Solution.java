// 2021-02-18
class Solution {
    private int increment(int[] start, int[] end) {
        if (Math.abs(end[0] - start[0]) >= Math.abs(end[1] - start[1])) {
            return Math.abs(end[0] - start[0]);
        } else {
            return Math.abs(end[1] - start[1]);
        }
    }
    
    public int minTimeToVisitAllPoints(int[][] points) {
        int count = 0;
        for (int i=0; i<(points.length - 1); i++) {
            count += increment(points[i], points[i+1]);
        }
        return count;
    }
}