select Expressions.*, case operator
                            when '>' then IF(a.value > b.value, 'true', 'false')
                            when '<' then IF(a.value < b.value, 'true', 'false')
                            else IF(a.value = b.value, 'true', 'false')
                      end as value
from Expressions
join Variables a on left_operand = a.name
join Variables b on right_operand = b.name