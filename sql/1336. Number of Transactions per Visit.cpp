select ceil(idx) transactions_count, ifnull(visits_count, 0) visits_count 
from (
        select 0 idx 

        union all

        select @i := @i + 1
        from transactions
        join (select @i := 0) val
        where @i < (
            select count(*) transactions_count
            from transactions 
            group by user_id, transaction_date
            order by transactions_count desc
            limit 1
        )
    ) tmp1
left join (
            select transactions_count, count(*) visits_count
            from (
                select count(t.user_id) transactions_count
                from visits v left join transactions t
                on v.user_id = t.user_id and visit_date = transaction_date
                group by v.user_id, visit_date
            ) tmp
            group by transactions_count
          ) tmp2 on idx = transactions_count



with recursive t(n) as (
                          select 0 
                          union all
                          select n+1 
                          from t where n < (
                                select max(transaction_count)
                                from (
                                      select v.user_id, v.visit_date, count(tr.amount) transaction_count 
                                      from visits v
                                      left join transactions tr on v.user_id=tr.user_id and v.visit_date=tr.transaction_date
                                      group by v.user_id,v.visit_date
                                   ) a
                           )
                        ),
tmp as(
        select v.user_id, v.visit_date, count(t.amount) transaction_count 
        from visits v
        left join transactions t on v.user_id = t.user_id and v.visit_date=t.transaction_date
        group by v.user_id,v.visit_date
      )

select n transactions_count, ifnull(visit_count,0) visits_count 
from t
left join (
             select transaction_count, count(*) visit_count from tmp 
             group by transaction_count
          ) b on t.n = b.transaction_count