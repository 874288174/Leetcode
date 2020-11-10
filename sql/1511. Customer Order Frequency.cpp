select a.customer_id, name
from Customers a
join Orders b on a.customer_id = b.customer_id
join Product c on b.product_id = c.product_id and (order_date like '2020-06%' or order_date like '2020-07%')
group by a.customer_id, name
having sum(IF(order_date like '2020-06%', quantity*price, 0)) >= 100
        and sum(IF(order_date like '2020-07%', quantity*price, 0)) >= 100