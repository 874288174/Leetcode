select lower(trim(product_name)) product_name, DATE_FORMAT(sale_date, '%Y-%m') sale_date, count(*) total
from Sales
group by lower(trim(product_name)), DATE_FORMAT(sale_date, '%Y-%m')
order by product_name asc, sale_date asc