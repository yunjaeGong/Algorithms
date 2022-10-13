import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
       // 0/1 knapsack
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] dp = new int[5001];// dp[i]는 i를 만드는 데 필요한 5/3kg 봉지의 수
        Arrays.fill(dp, 1<<30);

        dp[3] = 1; dp[5] = 1;
    
        for(int i=6;i<=n;++i) {
            dp[i] = Math.min(i-3 > 0 && dp[i-3] != 1<<30?dp[i-3] + 1:1<<30, i-5 > 0 && dp[i-5] != -1?dp[i-5] + 1:1<<30);
        }
        System.out.println(dp[n] != 1<<30?dp[n]:-1);
    }
}