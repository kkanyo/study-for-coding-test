-- 5월 식품들의 총매출 조회하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131117

WITH food_order_by_product_202205 AS (
    SELECT
        product_id,
        SUM(amount) AS amount
    FROM food_order
    WHERE produce_date BETWEEN '2022-05-01' AND '2022-05-31'
    GROUP BY product_id
)

SELECT
    products.product_id,
    products.product_name,
    products.price * orders.amount AS total_sales
FROM food_product AS products
JOIN food_order_by_product_202205 AS orders
    ON products.product_id = orders.product_id
ORDER BY
    total_sales DESC,
    product_id;
    