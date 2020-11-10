select name
from salesperson
where sales_id not in (
                        select sales_id
                        from orders a
                        join company b on a.com_id = b.com_id 
                        where b.name = 'RED'
                    )