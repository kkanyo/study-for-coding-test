-- 특정 형질을 가지는 대장균 찾기

SELECT COUNT(*) AS count
FROM ecoli_data
WHERE genotype & 2 = 0
    AND (
        genotype & 5 > 0 
    ); 