select a.customer_id, customer_name
from Orders a
join Customers b on a.customer_id = b.customer_id
group by a.customer_id
having sum(product_name = 'A') > 0 and sum(product_name = 'B') > 0 and sum(product_name = 'C') = 0
order by a.customer_id