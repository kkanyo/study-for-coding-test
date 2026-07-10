package BaekjoonOnlineJudge;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

class Main {
    public static void main(String[] args) throws IOException {
        solution(input());
    }

    public static void solution(List<Integer> values) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for (Integer value : values) {
            int digit = 1;
            long num = 1;

            while (num % value != 0) {
                digit++;
                num = num * 10 + 1;
            }

            bw.write(Integer.toString(digit));
            bw.newLine();
        }
        bw.close();

    }

    public static List<Integer> input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = "";

        List<Integer> values = new ArrayList<>();

        while ((input = br.readLine()) != null) {
            values.add(Integer.parseInt(input));
        }

        br.close();

        return values;
    }
}