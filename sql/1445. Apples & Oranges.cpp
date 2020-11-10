select sale_date, sum(IF(fruit = 'apples', sold_num, -sold_num)) as diff 
from Sales
group by sale_date