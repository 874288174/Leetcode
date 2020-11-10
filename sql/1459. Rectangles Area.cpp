select a.id p1, b.id p2, abs(a.x_value-b.x_value) * abs(a.y_value-b.y_value) as area
from Points a
join Points b on a.id < b.id and a.x_value <> b.x_value and a.y_value <> b.y_value
order by area desc, p1, p2