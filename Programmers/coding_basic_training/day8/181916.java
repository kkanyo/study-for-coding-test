package Programmers.coding_basic_training.day8;

/*
    주사위 게임 3
    https://school.programmers.co.kr/learn/courses/30/lessons/181916
 */

import java.util.*;

class Solution {
    public int solution(int a, int b, int c, int d) {
        Map<Integer, Integer> numberMap = new HashMap<>();
        // 매개변수가 배열이었다면 더욱 간결해질 수 있었을 것이다.
        numberMap.put(a, numberMap.getOrDefault(a, 0) + 1);
        numberMap.put(b, numberMap.getOrDefault(b, 0) + 1);
        numberMap.put(c, numberMap.getOrDefault(c, 0) + 1);
        numberMap.put(d, numberMap.getOrDefault(d, 0) + 1);
        
        // Map은 중복이 되지 않는 다는 것을 이용하여 Map의 크기의 수로
        // 주사위의 눈의 중복 여부를 판단할 수 있다.
        switch (numberMap.size()) {
            case 1:     // 네 주사위에서 나온 숫자가 모두 같음
                return 1111 * a;
            case 2:     // 세 주사위에서 나온 숫자가 같은 경우, 또는 두 주사위에서 나온 숫자가 같고, 나머지 주사위에서 나온 숫자가 같은 경우
                int p = 0;
                
                Iterator<Integer> keys = numberMap.keySet().iterator();
                if (keys.hasNext()) {
                    p = keys.next();
                }
                
                if (keys.hasNext()) {
                    int q = keys.next();
                    
                    if (numberMap.get(q) == 2) {
                        return (p + q) * Math.abs(p - q);
                    }
                    
                    if (numberMap.get(q) == 3) {
                        q = p ^ q ^ (p = q);
                    }
                    
                    return (int)Math.pow(10 * p + q, 2);
                }
                
                break;
            case 3:     // 두 주사위에서 나온 숫자가 같고, 나머지 주사위에서 나온 숫자가 각각 다른 경우우
                int result = 1;
                for (int key : numberMap.keySet()) {
                    if (numberMap.get(key) > 1) {
                        continue;
                    }
                    
                    result *= key;
                }
                
                return result;
            case 4:     // 주사위의 눈이 모두 다름
                return Math.min(Math.min(a, b), Math.min(c, d));
        }
        
        return 0;
    }
}