-- 특정 세대의 대장균 찾기
-- https://school.programmers.co.kr/learn/courses/30/lessons/301650

SELECT
    third.id
FROM ecoli_data AS third
JOIN ecoli_data AS second
    ON third.parent_id = second.id
JOIN ecoli_data AS first
    ON second.parent_id = first.id
WHERE first.parent_id IS NULL
ORDER BY third.id;