 select S.Score, count(*) 'Rank' 
 from Scores S
 join (select distinct Score FROM Scores) S2 on S.Score <= S2.Score 
 group by S.Id
 order by S.Score desc;




select Score,(select count(distinct Score) from Scores where Score >= S.Score) 'Rank'
from Scores S
order by Score desc;