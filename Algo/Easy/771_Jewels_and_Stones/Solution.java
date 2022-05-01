// 2021-02-02
class Solution {
    int answer;
    public int numJewelsInStones(String jewels, String stones) {
        for (int i=0; i<=(jewels.length() - 1); i++){
            String jchar = jewels.substring(i, i+1);
            for (int n=0; n<=(stones.length() - 1); n++){
                String schar = stones.substring(n, n+1);
                if (jchar.equals(schar)){
                   answer++; 
                }
            }
        }return answer;
    } 
}

