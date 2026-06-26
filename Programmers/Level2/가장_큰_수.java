package Programmers.Level2;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class 가장_큰_수 {
    public String solution(int[] numbers) {
        List<String> numberStringList = Arrays.stream(numbers)
                .mapToObj(String::valueOf)
                .toList();

        numberStringList = numberStringList.stream()
                .sorted(Comparator.reverseOrder())
                .toList();

        StringBuilder stringBuilder = new StringBuilder();
        numberStringList.forEach(s -> stringBuilder.append(s));

        return stringBuilder.toString();
    }
}
