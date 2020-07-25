# Write your MySQL query statement below
# select 
#     Id
# from 
#     Weather w
# where 
#     Temperature > (select Temperature from Weather where RecordDate=DATE_SUB(w.RecordDate, INTERVAL 1 DAY));

select 
    a.Id
from 
    Weather a join Weather b
on
    DATE_SUB(a.recordDate, INTERVAL 1 DAY) = b.RecordDate
where
    a.Temperature > b.Temperature;