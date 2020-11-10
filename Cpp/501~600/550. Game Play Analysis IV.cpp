select
    ROUND((select count(*)
        from Activity
        where (player_id, event_date) in (select player_id, Date(min(event_date)+1)
                                            from Activity
                                            group by player_id)
    ) / count(distinct player_id), 2) as fraction
from Activity;