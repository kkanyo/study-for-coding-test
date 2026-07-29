-- 년, 월, 성별 별 상품 구매 회원 수 구하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131532

SELECT
    YEAR(sale.sales_date) AS year,
    MONTH(sale.sales_date) AS month,
    info.gender,
    COUNT(DISTINCT info.user_id) AS users
FROM user_info AS info
JOIN online_sale AS sale
    ON info.user_id = sale.user_id
WHERE info.gender IS NOT NULL
GROUP BY
    year,
    month,
    info.gender
ORDER BY
    year,
    month,
    info.gender;