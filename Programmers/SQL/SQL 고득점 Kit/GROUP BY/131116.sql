-- 식품분류별 가장 비싼 식품의 정보 조회하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131116

WITH max_price_by_category AS (
    SELECT
        category,
        MAX(price) AS max_price
    FROM food_product
    WHERE category IN ('과자', '국', '김치', '식용유')
    GROUP BY category
)

SELECT
    product.category,
    product.price AS max_price,
    product.product_name
FROM food_product AS product
JOIN max_price_by_category AS category_max
    ON product.category = category_max.category
   AND product.price = category_max.max_price
ORDER BY product.price DESC;