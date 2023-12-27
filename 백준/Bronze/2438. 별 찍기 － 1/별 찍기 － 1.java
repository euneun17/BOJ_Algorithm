import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException{
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       int n = Integer.parseInt(br.readLine());
       StringBuilder sb1 = new StringBuilder();
       StringBuilder sb2 = new StringBuilder();
       for (int i = 0; i<n; i++){
           sb1.append("*");
           sb2.append(sb1+"\n");
       }
       System.out.print(sb2);
    }
}