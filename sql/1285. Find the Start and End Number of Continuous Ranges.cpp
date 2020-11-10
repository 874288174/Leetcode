SELECT min(log_id) start_id, max(log_id) end_id
FROM (
        SELECT log_id, CASE 
                            WHEN @id = log_id - 1 THEN @num := @num
		                    ELSE @num := @num + 1
                       END num
                       , @id := log_id
	    FROM LOGS
        JOIN (SELECT @num := 0, @id := NULL) a
	 ) x
GROUP BY num



select start_id, min(end_id) end_id
from (
        select log_id start_id 
        from logs 
        where log_id-1 not in (select * from logs)
     ) a
join (
        select log_id end_id 
        from logs 
        where log_id + 1 not in (select * from logs)
    ) b
where start_id <= end_id
group by start_id;




SELECT MIN(log_id) start_id, MAX(log_id) end_id
FROM (
         SELECT
            log_id, log_id - row_number() OVER(ORDER BY log_id) as num
        FROM Logs
     ) t
GROUP BY num