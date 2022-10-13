import java.util.Scanner;
import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        int T = sc.nextInt();

        int[][] fib = new int[2][];
        fib[0] = new int[41];
        fib[1] = new int[41];

        fib[0][0] = 1;  // 으로 0
        fib[1][1] = 1;

        while(T-- > 0) {

            int N = sc.nextInt();

            for(int i=2;i<=N;++i) {
                fib[1][i] = fib[1][i-1] + fib[1][i-2];
                fib[0][i] = fib[0][i-1] + fib[0][i-2];
            }

            sb.append(fib[0][N]).append(" ").append(fib[1][N]).append("\n");
            Arrays.fill(fib[0], 2, 40, 0);
            Arrays.fill(fib[0], 2, 40, 0);
        }
        System.out.println(sb);;
    }
}