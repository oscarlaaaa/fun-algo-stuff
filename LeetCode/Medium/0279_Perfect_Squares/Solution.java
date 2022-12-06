// 2022-11-22 (tabulation)
class Solution {
    public int numSquares(int n) {
        List<Integer> squares = generateSquares(n);
        int[] tab = new int[n + 1];
        Arrays.fill(tab, -1);
        tab[0] = 0;
        for (int i = 0; i < tab.length; i++) {
            if (tab[i] != -1) {
                
                for (int square : squares) {
                    if (i + square < tab.length) {
                        
                        int next = i + square;
                        if (tab[next] == -1 || tab[next] > tab[i] + 1) {
                            tab[next] = tab[i] + 1;
                        }
                        
                    }
                    
                }
                
                
            }
        }
        return tab[n];
    }
    
    private static List<Integer> generateSquares(int n) {
        List<Integer> squares = new ArrayList<Integer>();
        for (int i = 1; i*i <= n; i++) {
            int square = i*i;
            squares.add(square);
        }
        return squares;
    }
}