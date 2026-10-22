-- 상품을 구매한 회원 비율 구하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131534

WITH account_joined_2021 AS (
    SELECT 
        user_id
    FROM user_info
    WHERE joined BETWEEN '2021-01-01' AND '2021-12-31'
)

SELECT
    YEAR(sales.sales_date) AS `year`,
    MONTH(sales.sales_date) AS `month`,
    COUNT(DISTINCT sales.user_id) AS `purchased_users`,
    ROUND(COUNT(DISTINCT sales.user_id) / (
        SELECT COUNT(*) FROM account_joined_2021
    ), 1) AS `purchased_ratio`
FROM online_sale AS `sales`
JOIN account_joined_2021 AS `users`
    ON sales.user_id = users.user_id
GROUP BY
    year,
    month
ORDER BY
    year,
    month;
