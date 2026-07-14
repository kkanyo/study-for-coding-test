-- 과일로 만든 아이스크림 고르기

SELECT fh.flavor
FROM first_half AS fh
JOIN icecream_info AS ii
    ON fh.flavor = ii.flavor
WHERE total_order > 3000
    AND ii.ingredient_type = 'fruit_based';