select a.Id
from Weather a
join Weather b on a.Temperature > b.Temperature and datediff(a.RecordDate, b.RecordDate) = 1