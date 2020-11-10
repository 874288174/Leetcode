select stock_name, sum(IF(operation = 'Buy', -price, price)) capital_gain_loss
from Stocks
group by stock_name
