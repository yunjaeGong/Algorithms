import java.io.*;
import java.util.Scanner;
import java.util.stream.Stream;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[301];
        int[] dp = new int[301];
        for(int i=1;i<=n;++i) {
            arr[i] = sc.nextInt();
        }
        dp[1] = arr[1]; dp[2] = arr[1] + arr[2];

        for(int i=3;i<=n;++i) {
            dp[i] = arr[i] + Math.max(dp[i-2], dp[i-3] + arr[i-1]);  // 두 계단, 한 계단
        }

        System.out.println(dp[n]);
    }

}