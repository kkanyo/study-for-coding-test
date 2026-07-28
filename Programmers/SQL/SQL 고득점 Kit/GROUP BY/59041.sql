-- 동명 동물 수 찾기
-- https://school.programmers.co.kr/learn/courses/30/lessons/59041

SELECT
    name,
    COUNT(*) AS `count`
FROM animal_ins
WHERE name IS NOT NULL
GROUP BY name
HAVING `count` >= 2
ORDER BY name;