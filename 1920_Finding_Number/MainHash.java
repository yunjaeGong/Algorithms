import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        String[] nums = br.readLine().split(" ");
        Set<Integer> hs = Arrays.stream(nums).mapToInt(Integer::parseInt).boxed().collect(Collectors.toSet());

        int M = Integer.parseInt(br.readLine());
        Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt)
                .forEach(x -> sb.append(hs.contains(x)?1:0).append("\n"));

        System.out.println(sb);
    }
}