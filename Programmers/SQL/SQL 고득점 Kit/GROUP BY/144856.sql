-- 저자 별 카테고리 별 매출액 집계하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/144856

SELECT
    book.author_id,
    author.author_name,
    book.category,
    SUM(book.price * book_sales.sales) AS total_sales
FROM book_sales
JOIN book
    ON book.book_id = book_sales.book_id
JOIN author
    ON author.author_id = book.author_id
WHERE book_sales.sales_date BETWEEN '2022-01-01' AND '2022-01-31'
GROUP BY
    book.author_id,
    book.category
ORDER BY
    book.author_id ASC,
    book.category DESC;