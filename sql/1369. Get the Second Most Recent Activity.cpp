select username, activity, startDate, endDate
from (
        select *, rank() over (partition by username order by startDate desc) as rnk
                , count(*) over (partition by username) as cnt
        from UserActivity
    ) t
where cnt = 1 or  rnk = 2