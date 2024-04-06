class Solution {
    public int solution(String s) {
        int answer = 0;
        
        int xNum = 0; int notXNum = 0;
        char x = s.charAt(0);
        
        for (int i = 0; i < s.length(); i++){   
            if (s.charAt(i) == x){
                xNum++;
            } else notXNum++;
            
            if (xNum == notXNum) {
                answer++;
                xNum = 0;
                notXNum = 0;
                if (i < s.length() - 1) x = s.charAt(i+1);
            } else if (i == s.length() - 1) {
                answer++;
            }
        }
        
        return answer;
    }
}