
import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        Deque<Character> stack = new LinkedList<>();
        int T = sc.nextInt();

        while(T-- > 0) {
            String str = sc.nextLine();

            for(int i=0;i<str.size();++i) {
                char c_i = str.chsrAt(i);
                if(c_i == '(') {
                    stack.addLast(str.charAt(i));  // 여는 괄호이면
                } else {  // 닫는 괄호이면
                    if(stack.isEmpty()) {
                        sb.append("NO\n");
                        break;  // break for
                    }
                    stack.pollLast();
                }
            }
            if(stack.isEmpty()) {
                sb.append("YES\n");
            }
        }
        System.out.println(sb);
    }
}