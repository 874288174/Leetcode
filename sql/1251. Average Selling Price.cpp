select a.product_id, round(sum(units*price)/sum(units), 2) average_price
from UnitsSold a
join Prices b on a.product_id = b.product_id and a.purchase_date between start_date and end_date
group by a.product_id