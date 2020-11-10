select round(avg(a)*100, 2)  average_daily_percent
from ( 
        select (count(distinct b.post_id) / count(distinct a.post_id)) a
        from actions a
        left join removals b on a.post_id = b.post_id
        where extra = 'spam'
        group by action_date 
    ) v