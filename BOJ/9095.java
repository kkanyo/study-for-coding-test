import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

class Main {
    static final int MAX_NUM = 11;

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        List<Integer> values = solution(input());
        for (int value : values) {
            bw.write(Integer.toString(value));
            bw.newLine();
        }

        bw.close();
    }

    public static List<Integer> solution(List<Integer> values) {
        List<Integer> result = new ArrayList<>();

        for (int i = 1; i <= MAX_NUM; i++) {
            int num = 0;

            if (i == 1 || i == 2) {
                num = 1;
            } else if (i % 2 == 0) {
                
            }

            result.add(num);
        }

        return result;
    }

    public static List<Integer> input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = "";

        List<Integer> values = new ArrayList<>();
        br.readLine();

        while ((input = br.readLine()) != null) {
            values.add(Integer.parseInt(input));
        }

        br.close();

        return values;
    }
}