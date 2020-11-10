select '[0-5>' BIN, sum(if(duration < 300, 1, 0)) TOTAL from Sessions 
union select '[5-10>' bin, sum(if(300 <= duration and duration<600, 1, 0)) total from Sessions
union select '[10-15>' bin, sum(if(600 <= duration and duration<900, 1, 0)) total from Sessions 
union select '15 or more' bin, sum(if(900 <= duration, 1, 0)) total from Sessions  