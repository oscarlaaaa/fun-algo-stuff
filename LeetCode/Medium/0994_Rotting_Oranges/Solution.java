// 2021-10-29
class Solution {
    public int orangesRotting(int[][] grid) {
        Deque<int[]> sick = new ArrayDeque<int[]>();
        Set<Pair<Integer, Integer>> healthy = new HashSet<Pair<Integer, Integer>>();
        
        findOranges(sick, healthy, grid);

        if (sick.size() == 0) return healthy.size() == 0 ? 0 : -1;
        
        
        int time = 0;
        while (!sick.isEmpty()) {
            int[] rotten = sick.getFirst();
            sick.removeFirst();
            
            int i = rotten[0];
            int j = rotten[1];
            
            int count = rotten[2];
            if (count > time) time = count;
            
            spreadRot(i, j, count, grid, sick, healthy);
        }
        return healthy.size() == 0 ? time : -1;
    }
    
    private static void findOranges(Deque<int[]> sick, Set<Pair<Integer, Integer>> healthy, int[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 2) {
                    sick.addLast(new int[]{i, j, 0});
                }
                if (grid[i][j] == 1) {
                    healthy.add(new Pair<Integer, Integer>(i, j));
                }
            }
        }
    }
    
    private static void spreadRot(int i, int j, int count, int[][] grid, Deque<int[]> sick, Set<Pair<Integer, Integer>> healthy) {
        if (i - 1 >= 0 && grid[i-1][j] == 1) {
            grid[i-1][j] = 2;
            sick.addLast(new int[]{i-1, j, count + 1});
        }

        if (j - 1 >= 0 && grid[i][j-1] == 1) {
            grid[i][j-1] = 2;
            sick.addLast(new int[]{i, j-1, count + 1});
        }

        if (i + 1 < grid.length && grid[i+1][j] == 1) {
            grid[i+1][j] = 2;
            sick.addLast(new int[]{i+1, j, count + 1});
        }

        if (j + 1 < grid[i].length && grid[i][j+1] == 1) {
            grid[i][j+1] = 2;
            sick.addLast(new int[]{i, j+1, count + 1});
        }
        
        Pair<Integer, Integer> position = new Pair<Integer, Integer>(i, j);
        if (healthy.contains(position)) healthy.remove(position);
    }