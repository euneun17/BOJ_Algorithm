import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        
        List<Integer> answerList = new ArrayList<Integer>();
        
        answerList.add(arr[0]);
        for (int i = 1; i < arr.length; i++){
            if (arr[i] == arr[i-1]) continue;
            else answerList.add(arr[i]);
        }
        
        int[] answer = new int[answerList.size()];
        for (int i = 0; i < answer.length; i++){
            answer[i] = answerList.get(i);
        }
        
        return answer;
    }
}