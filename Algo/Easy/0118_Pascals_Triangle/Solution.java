import java.util.*;

// 2021-11-12
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> pascalTri = new ArrayList<List<Integer>>();
        
        List<Integer> firstRow = new ArrayList<Integer>();
        firstRow.add(1);
        pascalTri.add(firstRow);
        
        for (int i = 1; i < numRows; i++) {
            int rowSize = i + 1;
            List<Integer> prevRow = pascalTri.get(i - 1);
            
            List<Integer> row = new ArrayList<Integer>();
            for (int j = 0; j < rowSize; j++) {
                if (j == 0 || j == rowSize-1) {
                    row.add(1);
                } else {
                    int val = prevRow.get(j-1) + prevRow.get(j);
                    row.add(val);
                }              
            }
            pascalTri.add(row);
        }
        return pascalTri;
    }
}