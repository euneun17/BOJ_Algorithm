import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st = new StringTokenizer(br.readLine());
       int n = Integer.parseInt(st.nextToken());

       StringBuilder sb = new StringBuilder();
       for(int i = 0; i<n; i++){
           for(int j = n-i-1; j>0; j--){
               sb.append(" ");
           }
           for(int k = 2*i+1; k>0; k--){
               sb.append("*");
           }
           sb.append("\n");
       }
       System.out.print(sb);
    }
}