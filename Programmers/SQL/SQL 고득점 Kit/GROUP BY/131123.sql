-- 즐겨찾기가 가장 많은 식당 정보 출력하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131123

SELECT 
    rest_info.food_type,
    rest_info.rest_id, 
    rest_info.rest_name, 
    rest_info.favorites
FROM (
    SELECT
        food_type,
        MAX(favorites) AS favorites
    FROM rest_info
    GROUP BY food_type
) max_favorites, rest_info
WHERE  max_favorites.food_type = rest_info.food_type 
    AND max_favorites.favorites = rest_info.favorites
ORDER BY food_type DESC;