#对于null, referee_id <> 2 和 !(referee_id = 2) 都不成立

select name
from customer
where ifnull(referee_id, 0) <> 2