-- 조건에 부합하는 중고거래 댓글 조회하기

SELECT ugb.title,
    ugb.board_id,
    ugr.reply_id,
    ugr.writer_id,
    ugr.contents,
    ugr.created_date
FROM used_goods_board AS ugb
JOIN used_goods_reply AS ugr
    ON ugb.board_id = ugr.board_id
WHERE ugb.created_date BETWEEN '2022-10-01' AND '2022-10-31'
ORDER BY ugr.created_date,
    ugb.title;
