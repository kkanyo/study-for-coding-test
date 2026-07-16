-- 업그레이드 된 아이템 구하기

SELECT ii.item_id,
    ii.item_name,
    ii.rarity
FROM item_info AS ii
WHERE ii.item_id IN(
    SELECT it.item_id
    FROM item_tree AS it
    JOIN item_info AS ii2
        ON it.parent_item_id = ii2.item_id
    WHERE ii2.rarity = 'RARE'
)
ORDER BY ii.item_id DESC;

-- JOIN으로 부모 아이템과 자식 아이템을 명확히 나누는 방식
SELECT child.item_id,
       child.item_name,
       child.rarity
FROM item_tree AS tree
JOIN item_info AS parent
  ON tree.parent_item_id = parent.item_id
JOIN item_info AS child
  ON tree.item_id = child.item_id
WHERE parent.rarity = 'RARE'
ORDER BY child.item_id DESC;