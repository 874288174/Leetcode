SELECT activity 
FROM Friends 
GROUP BY activity
HAVING COUNT(*) > SOME(SELECT COUNT(*) FROM Friends GROUP BY activity) 
       and COUNT(*) < SOME(SELECT COUNT(*) FROM Friends GROUP BY activity)