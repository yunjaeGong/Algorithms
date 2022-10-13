import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();

        Deque<Integer> dq = new LinkedList<>();

        for(int i=0;i<N;++i) {
            String[] inp = br.readLine().split(" ");

            if(inp[0].contains("push")) {
                int val = Integer.parseInt(inp[1]);

                if(inp[0].contains("front"))
                    dq.addFirst(val);
                if(inp[0].contains("back"))
                    dq.addLast(val);
            } else if(inp[0].contains("pop")) {
                if(dq.isEmpty()) {
                    sb.append(-1).append("\n");
                    continue;
                }
                if(inp[0].contains("front"))
                    sb.append(dq.pollFirst()).append("\n");
                if(inp[0].contains("back"))
                    sb.append(dq.pollLast()).append("\n");
            } else if(inp[0].contains("si")) {
                sb.append(dq.size()).append("\n");
            } else if(inp[0].contains("em")) {
                sb.append(dq.isEmpty()?1:0).append("\n");
            } else if(inp[0].equals("front")) {
                sb.append(dq.peekFirst()==null?-1:dq.peekFirst()).append("\n");
            } else {  // back
                sb.append(dq.peekLast()==null?-1:dq.peekLast()).append("\n");
            }
        }
        System.out.println(sb);
    }
}