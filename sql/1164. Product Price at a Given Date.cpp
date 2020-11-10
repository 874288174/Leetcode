select distinct a.product_id, ifnull(b.new_price,10) as price 
from Products a 
left join (
                select *, row_number() over ( partition by product_id order by change_date desc) as rk 
                from Products 
                where change_date <= '2019-08-16'
          ) b on a.product_id = b.product_id and rk = 1






select product_id as product_id,10 as price 
from Products 
group by product_id
having min(change_date) > '2019-08-16'

union

select product_id, new_price price
from Products
where (product_id, change_date) in ( 
                                        select product_id, max(change_date)
                                        from Products
                                        where change_date <= '2019-08-16'
                                        group by product_id
                                    )