-- 대장균의 크기에 따라 분류하기 1

SELECT id,
    (
        CASE
            WHEN size_of_colony <= 100 THEN 'LOW'
            WHEN size_of_colony <= 1000 THEN 'MEDIUM'
            ELSE 'HIGH'
        END
    ) AS size
FROM ecoli_data
ORDER BY id;