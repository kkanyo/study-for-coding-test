import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(Integer.toString(solution(input())));
        bw.close();
    }

    public static int solution(List<Integer> values) {
        int E = values.get(0);
        int S = values.get(1);
        int M = values.get(2);

        // 16n + 1
        // 28n + 1
        // 19n + 1
        // year % 16
        
        int i = 1;
        while (i % 15 == E) {

        }

        return 0;
    }

    public static List<Integer> input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = "";

        List<Integer> values = new ArrayList<>();

        if ((input = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(input);

            for (int i = 0; i < 3; i++) {
                values.add(Integer.parseInt(st.nextToken()));
            }
        }

        br.close();

        return values;
    }
}