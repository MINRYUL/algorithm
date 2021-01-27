import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int num = Integer.parseInt(br.readLine());
        
        long[] c = new long[100];
        
        c[1] = 1;
        c[2] = 1;
        c[3] = 2;
        
        for(int i = 4; i <= num; i++) {
            c[i] = c[i-1] + c[i-2];
        }
        
        bw.write(c[num] + "\n");
        bw.flush();
        bw.close();
        br.close();
        
    }
}
