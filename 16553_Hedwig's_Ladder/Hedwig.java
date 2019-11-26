import java.io.*;
import java.util.*;

public class Hedwig {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        final int MOD = 10007;
        int k, n;
        int []f = new int [1001];

        f[1] = 2;f[2] = 3;
        for(int i=3;i<=1000;++i)
            f[i] = (f[i-1]%MOD + f[i-2]%MOD + i%2)%MOD;

        int N = Integer.parseInt(st.nextToken());

        for(int i=0;i<N;i++) {
            st = new StringTokenizer(br.readLine());
            k = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());
            sb.append((Integer.toString(k) + " " + Integer.toString(f[n])+'\n'));
        }
        System.out.println(sb.toString());
    }
}
