import java.io.*;
import java.util.*;

public class Test {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        Deque<Integer> stack = new LinkedList<>();

        for(int i=0;i<N;++i) {
            String[] str = br.readLine().split(" ");

            switch(str[0]) {
                case "push": stack.addLast(Integer.parseInt(str[1])); break;
                case "pop": sb.append(stack.isEmpty()?-1:stack.pollLast()); break;
                case "top": sb.append(stack.isEmpty()?-1:stack.getLast()); break;
                case "size": sb.append(stack.size()); break;
                case "empty": sb.append(stack.isEmpty()?1:0); break;
            }
            if(!str[0].equals("push"))
                sb.append("\n");
            
        }

        System.out.println(sb);
    }
}