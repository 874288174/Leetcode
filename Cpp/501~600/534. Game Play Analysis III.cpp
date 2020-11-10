select a.player_id, a.event_date, sum(b.games_played) as 'games_played_so_far'
from Activity a
join Activity b on a.player_id = b.player_id and a.event_date >= b.event_date
group by a.player_id, a.event_date;



select player_id, event_date, sum(games_played) over(partition by player_id order by event_date) as 'games_played_so_far'
from  activity;