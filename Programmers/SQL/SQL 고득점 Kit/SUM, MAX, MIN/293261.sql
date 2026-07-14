-- 물고기 종류 별 대어 찾기

-- 상관 서브 쿼리
SELECT 
    fi.id,
    fni.fish_name,
    fi.length
FROM fish_info AS fi
JOIN fish_name_info AS fni
ON fi.fish_type = fni.fish_type
WHERE length = (
    SELECT MAX(length)
    FROM fish_info AS fi2
    WHERE fi2.fish_type = fi.fish_type
)
ORDER BY fi.id;

-- 집계 후 조인
SELECT
    fi.id,
    fni.fish_name,
    fi.length
FROM fish_info AS fi
JOIN (
    SELECT
        fish_type,
        MAX(length) AS max_length
    FROM fish_info
    GROUP BY fish_type
) AS fm
    ON fi.fish_type = fm.fish_type
   AND fi.length = fm.max_length
JOIN fish_name_info AS fni
    ON fi.fish_type = fni.fish_type
ORDER BY fi.id;