select business_id
from Events a
join (        
        select event_type, avg(occurences) as avg_o
        from Events
        group by event_type
    ) b on a.event_type = b.event_type and a.occurences > b.avg_o
group by business_id
having count(*) > 1   