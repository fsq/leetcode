# Write your MySQL query statement below
with gp as (
    select class, count(distinct student) as cnt from courses group by class
)
select class from gp where cnt>=5;