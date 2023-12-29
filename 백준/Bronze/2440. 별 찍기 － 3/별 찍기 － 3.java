import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st = new StringTokenizer(br.readLine());
       int n = Integer.parseInt(st.nextToken());

       StringBuilder sb = new StringBuilder();
       for(int i = 0; i<n; i++){
           for(int j = n-i; j>0; j--) {
               sb.append("*");
           }
           sb.append("\n");
       }
       System.out.print(sb);
    }
}