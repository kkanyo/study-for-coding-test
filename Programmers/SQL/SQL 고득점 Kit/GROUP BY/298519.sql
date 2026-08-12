-- 특정 조건을 만족하는 물고기별 수와 최대 길이 구하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/298519

SELECT
    COUNT(*) AS fish_count,
    MAX(length) AS max_length,
    fish_type
FROM fish_info AS info
GROUP BY fish_type
HAVING AVG(IFNULL(length, 10)) >= 33
ORDER BY fish_type;