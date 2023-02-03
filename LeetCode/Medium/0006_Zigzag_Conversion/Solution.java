// 2021-06-08
class Solution {
    public String convert(String s, int numRows) {
        
        // Base case of single row
        if (numRows == 1) return s;
        
        // Create array that holds StringBuilder for each row
        StringBuilder[] rows = new StringBuilder[numRows];

        // Initialize array of StringBuilder
        for (int i = 0; i < rows.length; i++){
            rows[i] = new StringBuilder();
        }
        
        // Character position, whether we are zigging or zagging, and the row number
        int count = 0;
        int change = 1;
        int rowNo = 0;
        
        while (count < s.length()) {
            
            // Add character into designated StringBuilder position
            rows[rowNo].append(s.charAt(count));
            
            // Change zigzag direction
            if (rowNo + change == numRows || rowNo + change < 0) {
                change = -change;
            }
            count++;
            rowNo += change;
        }
        
        // Append all together
        for (int i = 1; i < rows.length; i++) {
            rows[0].append(rows[i]);
        }
        
        return rows[0].toString();
    }
}