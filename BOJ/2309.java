import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

// 풀이 완료
class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        List<Integer> sevenDwarfHeight = solution(getInput());
        sevenDwarfHeight.sort(Integer::compareTo);

        for (Integer height : sevenDwarfHeight) {
            bw.write(Integer.toString(height));
            bw.newLine();
        }

        bw.close();
    }

    public static List<Integer> getInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = "";

        List<Integer> dwarfHeights = new ArrayList<>();
        while ((input = br.readLine()) != null) {
            dwarfHeights.add(Integer.parseInt(input));
        }
        br.close();

        return dwarfHeights;
    }

    public static List<Integer> solution(List<Integer> dwarfHeights) throws IOException {
        final int MAX_SUM_HEIGHTS = 100;
        int totalHeight = dwarfHeights.stream()
                .mapToInt(i -> i)
                .sum();

        for (int i = 0; i < dwarfHeights.size() - 1; i++) {
            int sumHeight = dwarfHeights.get(i);

            for (int j = i + 1; j < dwarfHeights.size(); j++) {
                int height = dwarfHeights.get(j);
                sumHeight += height;

                if (sumHeight + MAX_SUM_HEIGHTS == totalHeight) {
                    dwarfHeights.remove(j);
                    dwarfHeights.remove(i);

                    return dwarfHeights;
                }

                sumHeight -= height;
            }
        }

        return dwarfHeights;
    }
}