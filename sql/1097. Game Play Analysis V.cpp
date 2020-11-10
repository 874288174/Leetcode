select a1.install_dt,
       count(*) installs,
       round(count(a2.event_date)/count(*),2) Day1_retention
from (
        select player_id, min(event_date) install_dt
        from Activity
        group by player_id
     ) a1
left join Activity a2 on a1.player_id = a2.player_id
                and datediff(a2.event_date, a1.install_dt) = 1
group by a1.install_dt