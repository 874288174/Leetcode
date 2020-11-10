select product_name, sum(unit) unit
from Products a
join Orders b on a.product_id = b.product_id and order_date like '2020-02%'
group by a.product_id
having sum(unit) >= 100