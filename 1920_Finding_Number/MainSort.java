
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        String[] nums = br.readLine().split(" ");
        int[] arr = Arrays.stream(nums).mapToInt(Integer::parseInt).sorted().toArray();

        int M = Integer.parseInt(br.readLine());
        Arrays.stream(br.readLine().split(" "))  // stream으로
                .mapToInt(Integer::parseInt).forEach(x -> sb.append(bin_search(x, arr)).append("\n")); 
                // map으로 binary search 수행

        System.out.println(sb);
    }

    static int bin_search (final int target, int[] arr) {
        int s = 0, t = arr.length-1;

        while(s <= t) {
            int mid = (s + t) / 2;
            if(arr[mid] == target)
                return 1; // 존재
            if(arr[mid] < target)
                s = mid + 1;
            else
                t = mid - 1;
        }
        return 0;
    }
}