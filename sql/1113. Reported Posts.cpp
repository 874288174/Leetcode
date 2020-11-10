select extra report_reason, count(distinct post_id) report_count
from Actions
where action_date = '2019-07-04' and extra is not null and action = "report"
group by extra