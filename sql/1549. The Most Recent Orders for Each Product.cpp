select product_name, a.product_id, order_id, order_date
from Products a
join (
         select *, rank() over (partition by product_id order by order_date desc) rnk 
         from Orders
     ) b on a.product_id = b.product_id and rnk = 1
order by product_name, a.product_id, order_id