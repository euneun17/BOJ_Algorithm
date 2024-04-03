class Solution {
    public String solution(String[] seoul) {
        String answer = "";
        
        int x = 0;
        for (String str : seoul){
            if (str.equals("Kim")) break;
            x++;
        }
        answer = "김서방은 " + x + "에 있다";
        
        return answer;
    }
}