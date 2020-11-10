select name customer_name, a.customer_id, order_id, order_date
from Customers a
join (
        select *, dense_rank() over (partition by customer_id  order by order_date desc) as rnk
        from Orders
     ) b on a.customer_id = b.customer_id and rnk <= 3
order by name, a.customer_id, order_date desc