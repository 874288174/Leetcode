select round(ifnull(count(distinct user_id, session_id) / count(distinct user_id), 0), 2) average_sessions_per_user
from Activity
where datediff('2019-07-27', activity_date) < 30
