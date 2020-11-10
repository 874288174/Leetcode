SELECT  CASE 
            WHEN tag = 0 THEN 'failed'
            ELSE 'succeeded' 
        END as period_state,
        MIN(date) as start_date,
        MAX(date) as end_date
FROM (
        SELECT *,
                @group := IF(@prev = tag, @group, @group+1) as group_id,
                @prev := tag
        FROM (
                SELECT fail_date as date, 0 as tag
                FROM Failed
                UNION
                SELECT success_date as date, 1 as tag
                FROM Succeeded
             ) a
        JOIN (SELECT @group := -1, @prev := -1) b
        WHERE date LIKE '2019%'
        ORDER BY date ASC
    ) t
GROUP BY group_id
ORDER BY start_date