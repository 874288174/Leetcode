select seller_id
from sales 
group by seller_id
having sum(price) >= all(select sum(price) over(partition by seller_id) from sales)