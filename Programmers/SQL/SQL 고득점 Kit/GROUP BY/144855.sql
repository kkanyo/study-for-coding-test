-- 카테고리 별 도서 판매량 집계하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/144855

SELECT 
    category,
    SUM(sales) AS total_sales
FROM book
JOIN book_sales AS sales
    ON book.book_id = sales.book_id
WHERE sales.sales_date BETWEEN '2022-01-01' AND '2022-01-31'
GROUP BY category
ORDER BY category;