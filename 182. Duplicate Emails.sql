# Write your MySQL query statement below
# with gp as (
#     select Email as Email, count(*) as cnt from Person group by Email
# )
# select Email from gp where cnt>1;

select Email from Person group by Email having count(*)>1;