import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        int[] dp = new int[N+1];
        // dp[i]는 i를 만드는 데 필요한 연산의 수

        int i = N-1;  // n-1부터 시작,

        while(i > 0) {
            if(3*i <= N) {  // N 범위 안이면
                dp[i] = Math.min(dp[2*i], Math.min(dp[3*i], dp[i+1])) + 1;  // 3 혹은 2로 나누어 떨어지는 값 중 최소
            } else if(2*i <= N) {
                dp[i] = Math.min(dp[2*i], dp[i+1]) + 1;  // 3 혹은 2로 나누어 떨어지는 값 중 최소
            } else {
                // 1 빼는 경우
                dp[i] = dp[i+1] + 1;
            }
            i--;
        }

        System.out.println(dp[1]);
    }
}