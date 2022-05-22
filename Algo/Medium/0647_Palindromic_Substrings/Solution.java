
// 2021-07-14 (brute force w/ global variable)
class Solution {
    public int output;
    
    private void palindromeCheck(String s, int i, int x) {
        Character check = s.charAt(i);
        if (check.compareTo(s.charAt(x)) == 0) {
            if (i == x || x - i == 1) {
                ++output;
            } else {
                palindromeCheck(s, i + 1, x - 1);
            }
        }
    }
    
    public int countSubstrings(String s) {
        output = s.length();
        for (int i = 0; i < s.length(); i++) {
            for (int x = s.length() - 1; x > i; x--) {
                palindromeCheck(s, i, x);
            }
        }
        return output;
    }
}

// 2021-07-14 (heh i learned queues around this time B))
class Solution2 {
    public int countSubstrings(String s) {
        // initialize output and queue
        int output = 0;
        Deque<int[]> queue = new ArrayDeque<int[]>();
        
        // increment output; add the positions around every letter to the queue
        for (int i = 0; i < s.length(); i++) {
            ++output;
            int[] x = new int[]{i-1, i+1};
            queue.add(x);
            
            // increment output for matches; add positions around every matched pair to the queue
            if (i+1 < s.length() && s.charAt(i) == s.charAt(i+1)) {
                ++output;
                x = new int[]{i-1, i+2};
                queue.add(x);
            }
        }
        
        // cycle while the queue still has positions to check
        while (!queue.isEmpty()) {
            int[] check = queue.getFirst();
            queue.removeFirst();
            
            // make sure that the bounds for the positions are within the string
            if (!(check[0] < 0 || check[1] >= s.length())) {
                
                // if they match, increment output and queue the positions around the matched pair
                if (s.charAt(check[0]) == s.charAt(check[1])) {
                    ++output;
                    int[] x = new int[]{--check[0], ++check[1]};
                    queue.add(x);
                }
            }
        }
        return output;
    }
}