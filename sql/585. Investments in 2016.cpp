select sum(TIV_2016) as 'TIV_2016'
from  insurance
where TIV_2015 in (select TIV_2015 from insurance group by TIV_2015 having count(*) > 1)
    and concat(lat, lon) in (select concat(lat,lon) from insurance group by concat(lat,lon) having count(*) = 1)





SELECT SUM(TIV_2016) as TIV_2016
FROM (
        SELECT
            *,
            count(*) over(partition by TIV_2015) as cnt_1,
            count(*) over(partition by LAT, LON) as cnt_2
        FROM insurance
    ) a 
WHERE a.cnt_1 > 1 AND a.cnt_2 < 2
