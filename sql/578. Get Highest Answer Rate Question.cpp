#count 不计null行
select question_id as 'survey_log'
from survey_log
where action <> 'skip'
group by question_id
order by count(answer_id) / (count(*) - count(answer_id)) desc
limit 1


#sum里面可以加函数
select question_id as survey_log
from survey_log
group by question_id
order by sum(if(action = 'answer', 1, 0)) / sum(if(action = 'show', 1, 0)) desc
limit 1