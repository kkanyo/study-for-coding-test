-- 특정 물고기를 잡은 총 수 구하기

SELECT COUNT(*) AS fish_count
FROM fish_info AS fi
JOIN fish_name_info AS fni
    ON fi.fish_type = fni.fish_type
WHERE fni.fish_name IN ('BASS', 'SNAPPER');