-- 가장 큰 물고기 10마리 구하기


SELECT id,
    length
FROM fish_info
ORDER BY length DESC, id
LIMIT 10;