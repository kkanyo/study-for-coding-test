-- 물고기 종류 별 잡은 수 구하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/293257#

SELECT
    COUNT(info.id) AS fish_count,
    name.fish_name
FROM fish_info AS info
JOIN fish_name_info AS name
    ON info.fish_type = name.fish_type
GROUP BY info.fish_type
ORDER BY fish_count DESC;