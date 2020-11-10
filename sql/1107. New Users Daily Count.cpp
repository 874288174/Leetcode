select t.d login_date, count(t.user_id) user_count
from (
    select user_id, min(activity_date) as d
    from Traffic
    where activity = "login"
    group by user_id
    having datediff('2019-06-30', d) <= 90
) t
group by t.d
