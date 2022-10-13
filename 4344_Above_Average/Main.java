import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        while(T-- > 0) {
            String[] strings = br.readLine().split(" ");
            int sum = Stream.of(strings).mapToInt(Integer::parseInt).sum();
            int n = Integer.parseInt(strings[0]);
            
            double avg = (sum - n) / (double)n;

            strings = Arrays.copyOfRange(strings, 1, strings.length);
            
            long cnt = Stream.of(strings).mapToInt(Integer::parseInt).filter(x -> x > avg).count();
            System.out.printf("%.3f%%\n", ((double)cnt/n)*100);
        }
    }
}