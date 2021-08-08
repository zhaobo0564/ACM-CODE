import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.Queue;
import java.io.BufferedReader;
import java.util.LinkedList;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Jaynil
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        EStringReversal solver = new EStringReversal();
        solver.solve(1, in, out);
        out.close();
    }

    static class EStringReversal {
        int[] bit;

        public void update(int x) {
            while (x < bit.length) {
                bit[x] += 1;
                x += (x & -x);
            }
        }

        public int sum(int x) {
            int ans = 0;
            while (x > 0) {
                ans += bit[x];
                x -= (x & -x);
            }
            return ans;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
           // int n = in.nextInt();
            String x = in.next();
            int n = 
            String xrev = new StringBuilder(x).reverse().toString();
            Queue<Integer> q[] = new LinkedList[26];
            int aa[] = new int[n];
            bit = new int[n + 10];
            for (int i = 0; i < 26; i++) q[i] = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                q[x.charAt(i) - 'a'].add(i);
            }
            long ans = 0;
            for (int i = 0; i < n; i++) {
                aa[q[xrev.charAt(i) - 'a'].poll()] = i + 1;
            }
            int t = 0;
            for (int i = 0; i < n; i++) {
                ans += t - sum(aa[i]);
                t++;
                update(aa[i]);
            }
            out.println(ans);
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

