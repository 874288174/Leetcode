select a.country_name, case
                          when avg(b.weather_state) <= 15 then 'Cold'
                          when avg(b.weather_state) >= 25 then 'Hot'
                          else 'Warm'
                       end as weather_type
from Countries a
join Weather b on a.country_id = b.country_id and b.day like '2019-11%'
group by a.country_name