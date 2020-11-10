select team_id, team_name, ifnull(sum(point), 0) num_points
from Teams
left join (
                select host_team id, case 
                                            when host_goals = guest_goals then 1
                                            when host_goals > guest_goals then 3
                                            else 0
                                    end as 'point'
                from Matches

                union all

                select guest_team id, case 
                                            when host_goals = guest_goals then 1
                                            when host_goals > guest_goals then 0
                                            else 3
                                    end as 'point'
                from Matches
            ) b on id = team_id
group by team_id
order by num_points desc, team_id asc