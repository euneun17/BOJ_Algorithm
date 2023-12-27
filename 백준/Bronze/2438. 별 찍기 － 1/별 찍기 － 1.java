import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException{
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st = new StringTokenizer(br.readLine());
       int n = Integer.parseInt(st.nextToken());

       int i = 1;
       while(i<=n){
           for(i=1; i<=n; i++){
               for(int j=1; j<=i; j++){
                   System.out.print("*");
               }
               System.out.println();
           }
           i++;
       }
    }
}