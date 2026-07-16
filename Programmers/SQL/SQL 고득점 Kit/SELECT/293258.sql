-- 잔챙이 잡은 수 구하기

SELECT COUNT(*) AS fish_count
FROM fish_info
WHERE length IS NULL; -- 물고기의 길이가 10cm 이하인 경우 NULL