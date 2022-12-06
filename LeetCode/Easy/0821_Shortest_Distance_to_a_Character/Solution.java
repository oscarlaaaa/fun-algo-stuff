// 2021-02-24
class Solution {
    public int toChar(String s, int p, char c){

        int count = 0;
        Boolean found = false;
        
        while(found == false){

            if(p - count >= 0){
                if (s.charAt(p - count) == c){
                    found = true;
                    return count;
                } 
            }
            
            if(p + count < s.length()){
                if (s.charAt(p + count) == c){
                    found = true;
                    return count;
                } 
            }
            count++;
        }
        return count;
    }
    
    public int[] shortestToChar(String s, char c) {
        int[] answer = new int[s.length()];

        for(int i=0; i<s.length(); i++){
            
            System.out.println("MAIN COUNT: " + i);
            answer[i] = toChar(s, i, c);
        }
        
        return answer;
    }
}