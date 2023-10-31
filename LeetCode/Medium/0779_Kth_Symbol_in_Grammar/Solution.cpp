// 2023-10-24 (tree traversal)
class Solution {
public:
    int kthGrammar(int n, int k) {
        /*
        notes:
        - ew this is a damn math question or smth
        - there's probably a clera pattern based on the row/col number
        - each iteration is just the same value with the bits flipped and
          appended onto the end??? ez money
        - if that's the case, then:
            - we just need to traverse until we hit the kth bit? the row doesn't rly matter
            - traverse is slow; we can do some math
                - zero indices: 0, 3, 5, 6, 9, 10, 12, 15, 17, 18, 20, 23, 24
            - maybe treat it like a binary tree? and try to reach the kth node
                - depending on node value, and go left for same val or right for opposite
                - start at 1 position
                    - left = pos*2-1, right = pos*2
                - we can go bottom-up!
                    - left = pos/2, right = (pos+1)/2
                    - traverse until we hit 1 (0 bit) or 2 (1 bit)
                    - count # of left-traversals since our bit flips each time

               0
             0   1
          0 1     1 0
        0 1 1 0 1 0 0 1
        0110100110010110
        01101001100101101001011001101001

        analysis:
        - time = O(k)
        - space = O(1)
        */
        int pos = k;
        int lefts = 0;
        while (pos > 2) {
            // if we're odd, we had to have come from a left-traversal so we go right
            if (pos & 1) {
                pos = (pos+1)/2;
                
            } else {
                pos /= 2;
                lefts++;
            }
        }
        // gives us the bit of our current position (0 if we're on position 1, and 1 if we're on position 2)
        int bit = !(pos&1);

        // if we have an odd number of left traversals, then flip what bit we're on
        return lefts % 2 == 1 ? !(bit&1) : bit;
    }
};