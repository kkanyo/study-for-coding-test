import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main {
    static int size = 0;

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(Integer.toString(solution(getInput())));

        bw.close();
    }

    public static char[] getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = "";

        if ((input = br.readLine()) != null) {
            size = Integer.parseInt(input);
        }

        char[] candies = new char[size * size];

        int i = 0;
        while ((input = br.readLine()) != null) {
            for (int j = 0; j < size; j++) {
                candies[i++] = input.charAt(j);
            }
        }
        br.close();

        return candies;
    }

    public static int solution(char[] candies) {
        int result = 0;

        // 현재 위치를 기준으로 인접해있는 사탕이 몇개나 반복되는지
        // 양 옆의 사탕과 같은 종류가 열 기준으로 인접한 사탕이 몇개나 있는지
        for (int i = 0; i < candies.length; i++) {
            // 왼쪽 사탕과 같은 종류가 인접한 동일한 사탕이 몇개나 있는지
            char rightCandy = ' ';
            if (i + 1 < size) {
                rightCandy = candies[i + 1];
            }

            int count = 0;
            for (int j = size; j <= candies.length; j += size) {
                if (rightCandy != candies[j]) {
                    break;
                }

                count++;
            }

            for (int j = i - size; j >= 0; j -= size) {
                if (rightCandy != candies[j]) {
                    break;
                }

                count++;
            }

            result = Math.max(result, count);
        }

        return result;
    }
}