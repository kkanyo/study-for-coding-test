-- 5월 식품들의 총매출 조회하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131117

SELECT
    book.book_id,
    author.author_name,
    book.published_date
FROM book
JOIN author
    ON book.author_id = author.author_id
        AND book.category = '경제'
ORDER BY published_date;