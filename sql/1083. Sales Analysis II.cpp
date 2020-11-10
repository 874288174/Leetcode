select s.buyer_id
from product p
join sales s
where p.product_id = s.product_id
group by s.buyer_id
having sum(p.product_name = 'S8') > 0 and sum(p.product_name = 'iphone') < 1



select distinct buyer_id
from Sales
where buyer_id in
                (
                    select buyer_id
                    from Sales a
                    join Product b on a.product_id = b.product_id and product_name = "S8"
                )
     and buyer_id not in
                (
                    select buyer_id
                    from Sales a
                    join Product b on a.product_id = b.product_id and product_name = "iPhone"
                )

