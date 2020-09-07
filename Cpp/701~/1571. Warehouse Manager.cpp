select name warehouse_name, sum(units*Width*Length*Height) as volume
from Warehouse a
join Products b on a.product_id = b.product_id
group by name