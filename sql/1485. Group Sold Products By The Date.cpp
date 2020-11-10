#group_concat 连接多个字符串， 字符串连接时可以排序， 自定义分隔符

select sell_date, count(distinct product) as num_sold, group_concat(distinct product) as products
from Activities
group by sell_date