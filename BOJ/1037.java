package BaekjoonOnlineJudge;

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

    public static int solution(List<Integer> divisors) {
        divisors.sort(Integer::compare);

        return divisors.get(0) * divisors.get(divisors.size() - 1);
    }

    public static List<Integer> input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = "";

        int n = 0;
        List<Integer> values = new ArrayList<>();

        if ((input = br.readLine()) != null) {
            n = Integer.parseInt(input);
        }

        while ((input = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(input);

            for (int i = 0; i < n; i++) {
                values.add(Integer.parseInt(st.nextToken()));
            }
        }

        br.close();

        return values;
    }
}