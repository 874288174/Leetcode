select a.user_id buyer_id, join_date, count(seller_id) as orders_in_2019
from Users a
left join Orders b on a.user_id = b.buyer_id and b.order_date between '2019-01-01' and '2019-12-31'
group by a.user_id