-- 주문량이 많은 아이스크림들 조회하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/133027

SELECT 
    first_half.flavor
FROM first_half
/*
* july.flavor가 first_half.flavor의 외래키라는 조건은 "7월의 모든 맛은 상반기에 존재한다"만 보장
* 반대로 상반기의 어떤 맛이 7월에 없을 수 있으므로, 이 경우 해당 맛을 제외
*/
JOIN ( 
    SELECT 
        flavor,
        SUM(total_order) AS total_order
    FROM july
    GROUP BY flavor
) AS july_flavor_group
    ON first_half.flavor = july_flavor_group.flavor
ORDER BY first_half.total_order + july_flavor_group.total_order DESC
LIMIT 3;

-- 개선
WITH july_orders_by_flavor AS (
    SELECT
        flavor,
        SUM(total_order) AS total_order
    FROM july
    GROUP BY flavor
)

SELECT
    first_half.flavor
FROM first_half
LEFT JOIN july_orders_by_flavor
    ON july_orders_by_flavor.flavor = first_half.flavor
ORDER BY
    first_half.total_order
    + COALESCE(july_orders_by_flavor.total_order, 0) DESC
LIMIT 3;