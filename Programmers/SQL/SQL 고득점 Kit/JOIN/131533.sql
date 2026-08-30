-- 상품 별 오프라인 매출 구하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131533

SELECT
    product.product_code,
    product.price * SUM(sales.sales_amount) AS `sales`
FROM product
JOIN offline_sale AS sales
    ON product.product_id = sales.product_id
GROUP BY product.product_id
ORDER BY
    sales DESC,
    product.product_code;