select avg(Number) as median from 
(
    select Number, @c1 + 1 as 'c1', (@c1 := @c1 + Frequency) as 'c2', t2.s
    from Numbers
    join (select @c1 := 0) t1
    join (select sum(Frequency) as s from Numbers) t2
    order by Number
) tmp
where c1 <= s/2 + 1 and c2 >= s/2;


