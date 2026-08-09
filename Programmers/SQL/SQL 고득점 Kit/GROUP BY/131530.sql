-- 가격대 별 상품 개수 구하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131530

SELECT
    (price DIV 10000) * 10000 AS price_group,
    COUNT(*) AS products
FROM product
GROUP BY price_group
ORDER BY price_group;