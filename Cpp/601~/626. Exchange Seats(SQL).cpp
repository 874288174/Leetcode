select
    if(id < (select count(*) from seat), if(mod(id, 2) = 0, id-1, id+1)
                                       , if(mod(id, 2) = 0, id-1, id)) as id, student
from seat
order by id asc;



select
    (case
        when mod(id, 2) != 0 and counts != id then id + 1
        when mod(id, 2) != 0 and counts = id then id
        else id - 1
     end) AS id, student
from seat, (select count(*) as counts from seat) as _
order by id asc;