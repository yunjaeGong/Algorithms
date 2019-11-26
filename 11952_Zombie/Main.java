import java.io.IOException;
import java.util.*;


public class Main {
    private static boolean[] danger;
    private static boolean[] zombie;
    static int N, M, K, S, p, q;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        K = sc.nextInt();
        S = sc.nextInt();

        p = sc.nextInt();
        q = sc.nextInt();

        danger = new boolean[N + 1]; // visited
        zombie = new boolean[N + 1]; // 점령당한 도시

        Queue<Integer> Q = new LinkedList<>(); // 점령된 도시들
        for(int i=0; i<K; ++i) {
            int u = sc.nextInt();
            Q.offer(u);
            zombie[u] = true;
        }

        ArrayList<Integer>[] path = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            path[i] = new ArrayList<>();
        }

        for(int i=0; i<M; ++i) {
            int v1 = sc.nextInt();
            int v2 = sc.nextInt();

            path[v1].add(v2);
            path[v2].add(v1);
        }

        setCost(path, Q);
        System.out.println(dijkstra(path));
    }

    private static void setCost(ArrayList<Integer>[] path, Queue<Integer> Q) {
        for (int i = 0; i < S; i++) {
            if (Q.isEmpty()) break;
            int size = Q.size();
            for (int j = 0; j < size; ++j) {
                int current = Q.poll();

                for (int next : path[current]) {
                    if (danger[next]) continue;
                    danger[next] = true;
                    Q.offer(next);
                }
            }
        }
    }

    private static long dijkstra(ArrayList<Integer>[] path) {
        long[] d = new long[N + 1];
        Arrays.fill(d, Long.MAX_VALUE);
        d[1] = 0;

        PriorityQueue<Point> pq = new PriorityQueue<Point>();
        pq.offer(new Point(1, 0));

        while (!pq.isEmpty()) {
            Point tmp = pq.poll();
            if (d[tmp.cur] < tmp.weight) continue;
            for (int adj : path[tmp.cur]) {
                int cost = p;
                if (zombie[adj]) continue;
                if (adj == N) cost = 0;
                else if (danger[adj]) cost = q;
                if (d[adj] > d[tmp.cur] + cost) {
                    d[adj] = d[tmp.cur] + cost;
                    pq.offer(new Point(adj, d[adj]));
                }
            }
        }
        return d[N];
    }

    public static class Point implements Comparable<Point> {
        int cur;
        long weight;

        public Point(int t, long w) {
            this.cur = t;
            this.weight = w;
        }
        @Override
        public int compareTo(Point a) {
            return Long.compare(this.weight, a.weight);
        }
    }
}


