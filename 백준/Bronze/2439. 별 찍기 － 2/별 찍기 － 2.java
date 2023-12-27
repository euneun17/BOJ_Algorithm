import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       int n = Integer.parseInt(br.readLine());

       StringBuilder sb = new StringBuilder();
       for(int i = 1; i<=n; i++){
           for(int j = n-i; j>0; j--){
             sb.append(" ");
           }
           for(int k = i; k>0; k--){
               sb.append("*");
           }
           sb.append("\n");
       }
       System.out.print(sb);
    }
}