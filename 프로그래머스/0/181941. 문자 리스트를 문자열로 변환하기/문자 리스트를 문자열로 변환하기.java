class Solution {
    public String solution(String[] arr) {
        String answer = "";
        
        for (int i = 0; i < arr.length; i++){ //array는 객체이므로 length() 메소드가 아닌 그냥 필드값 length 사용
            answer += arr[i];
        }
        
        return answer;
    }
}