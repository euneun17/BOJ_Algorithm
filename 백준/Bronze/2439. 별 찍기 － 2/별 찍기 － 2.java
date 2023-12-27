import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       int n = Integer.parseInt(br.readLine());

       for(int i = n; i>0; i--){
           for(int j = i-1; j>0; j--){
               System.out.print(" ");
           }
           for(int k = n+1-i; k>0; k--){
               System.out.print("*");
           }
           System.out.println();
       }
    }
}