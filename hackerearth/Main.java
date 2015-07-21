import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.InputStream;
/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Ankit Srivastava
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InReader in = new InReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TwoRepetitions solver = new TwoRepetitions();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}
class TwoRepetitions {
    public void solve(int testNumber, InReader in, OutputWriter out) {
        String s = in.readString();
        int n = s.length();
        int[] sa = SuffixArray.suffixArray(s);
        int[] lcp = SuffixArray.lcp(sa, s);
        int last = 0;
        long ans = 0;
        long dis = 1L * n * (n + 1L) / 2;
        for (int l : lcp) {
            //out.printLine(l);
            int add = l - last;
            if(add > 0){ 
                out.printLine(add);
                ans += add;

            }
            last = l;
            dis -= l;
        }
        //out.printLine(dis - ans);
    }
}
class InReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;
    public InReader(InputStream stream) {
        this.stream = stream;
    }
    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }
    public int readInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }
    public long readLong() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }
    public String readString() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuffer res = new StringBuffer();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }
    public boolean isSpaceChar(int c) {
        if (filter != null)
            return filter.isSpaceChar(c);
        return isWhitespace(c);
    }
    public String next() {
        return readString();
    }
    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}
class OutputWriter {
    private final PrintWriter writer;
    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }
    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }
    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }
    public void printLine(Object... objects) {
        print(objects);
        writer.println();
    }
    public void close() {
        writer.close();
    }
}
class SuffixArray {
    /*
    Code taken from open source repository
     */
    // suffix array in O(n*log(n))
    public static int[] suffixArray(final CharSequence str) {
        int n = str.length();
        Integer[] order = new Integer[n];
        for (int i = 0; i < n; i++)
            order[i] = n - 1 - i;
        Arrays.sort(order, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return Character.compare(str.charAt(o1), str.charAt(o2));
            }
        });
        // sa[i] - suffix on i'th position after sorting by first len characters
        // rank[i] - position of the i'th suffix after sorting by first len characters
        int[] sa = new int[n];
        int[] rank = new int[n];
        for (int i = 0; i < n; i++) {
            sa[i] = order[i];
            rank[i] = str.charAt(i);
        }
        for (int len = 1; len < n; len *= 2) {
            int[] r = rank.clone();
            for (int i = 0; i < n; i++) {
                // condition s1 + len < n simulates 0-symbol at the end of the string
                // a separate class is created for each suffix followed by 0-symbol
                rank[sa[i]] = i > 0 && r[sa[i - 1]] == r[sa[i]] && sa[i - 1] + len < n && r[sa[i - 1] + len / 2] == r[sa[i] + len / 2] ? rank[sa[i - 1]] : i;
            }
            // Suffixes are already sorted by first len characters
            // Now sort suffixes by first len * 2 characters
            int[] cnt = new int[n];
            for (int i = 0; i < n; i++)
                cnt[i] = i;
            int[] s = sa.clone();
            for (int i = 0; i < n; i++) {
                // s[i] - order of suffixes sorted by first len characters
                // (s[i] - len) - order of suffixes sorted only by second len characters
                int s1 = s[i] - len;
                // sort only suffixes of length > len, others are already sorted
                if (s1 >= 0)
                    sa[cnt[rank[s1]]++] = s1;
            }
        }
        return sa;
    }
    // longest common prefixes array in O(n)
    public static int[] lcp(int[] sa, CharSequence s) {
        int n = sa.length;
        int[] rank = new int[n];
        for (int i = 0; i < n; i++)
            rank[sa[i]] = i;
        int[] lcp = new int[n - 1];
        for (int i = 0, h = 0; i < n; i++) {
            if (rank[i] < n - 1) {
                int j = sa[rank[i] + 1];
                while (Math.max(i, j) + h < s.length() && s.charAt(i + h) == s.charAt(j + h)) {
                    ++h;
                }
                lcp[rank[i]] = h;
                if (h > 0)
                    --h;
            }
        }
        return lcp;
    }
}