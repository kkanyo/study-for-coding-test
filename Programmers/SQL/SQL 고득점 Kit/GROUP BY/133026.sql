-- 성분으로 구분한 아이스크림 총 주문량
-- https://school.programmers.co.kr/learn/courses/30/lessons/133026

SELECT 
    ingredient_type,
    SUM(orders.total_order) AS total_order
FROM first_half orders
JOIN icecream_info infos
    ON orders.flavor = infos.flavor
GROUP BY infos.ingredient_type
ORDER BY total_order;