select a.Name
from Candidate a
join Vote b on a.id = b.CandidateId
group by a.id
order by count(*) desc
limit 0, 1





select Name
from Candidate
where id = (
                select CandidateId 
                from Vote
                group by CandidateId
                order by count(*) desc
                limit 1
            )
