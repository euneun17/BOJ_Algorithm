import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        StringBuilder answer = new StringBuilder();
        
        for (int i= 0; i < a.length(); i++){
            char c = a.charAt(i);
            
            if (Character.isUpperCase(c))
                System.out.print(Character.toLowerCase(c));
            else if (Character.isLowerCase(c))
                System.out.print(Character.toUpperCase(c));
        }
    }
}