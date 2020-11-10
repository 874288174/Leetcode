#在group前可以先排序好， group by之后不会影响原先的顺序， 是稳定分组？

select group_id, player_id
from (
    select players.*, sum(if(player_id = first_player, first_score, second_score)) score
    from players
    join matches on player_id = first_player or player_id = second_player
    group by player_id, group_id
    order by score desc, player_id
) tmp
group by group_id







select group_id, player_id
from (
        select group_id, player_id, rank() over (partition by group_id order by score desc, player_id asc) as rnk
        from Players a
        join (
                select player, sum(score) score
                from (
                    select first_player player, first_score score
                    from Matches

                    union  all
                    select second_player player, second_score score
                    from Matches
                ) t
                group by player
            ) a on player_id = player
     ) b
where rnk = 1

