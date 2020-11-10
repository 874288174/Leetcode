select item_category Category,  sum(if(date_format(order_date,'%W')='Monday',quantity,0)) as Monday,
                                sum(if(date_format(order_date,'%W')='Tuesday',quantity,0)) as Tuesday,
                                sum(if(date_format(order_date,'%W')='Wednesday',quantity,0)) as Wednesday,
                                sum(if(date_format(order_date,'%W')='Thursday',quantity,0)) as Thursday,
                                sum(if(date_format(order_date,'%W')='Friday',quantity,0)) as Friday,
                                sum(if(date_format(order_date,'%W')='Saturday',quantity,0)) as Saturday,
                                sum(if(date_format(order_date,'%W')='Sunday',quantity,0)) as Sunday
from Items a
left join Orders b on a.item_id = b.item_id
group by item_category
order by item_category
