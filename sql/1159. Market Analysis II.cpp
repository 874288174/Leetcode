select user_id seller_id, IF(item_brand = favorite_brand, 'yes', 'no') 2nd_item_fav_brand
from Users a
left join (
              select *, rank() over (partition by seller_id order by order_date) rk
              from Orders
          ) b on a.user_id = b.seller_id and rk = 2
left join Items c on b.item_id = c.item_id
group by user_id, favorite_brand, item_brand