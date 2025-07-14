# Write your MySQL query statement below
select sum(a.SecondHighestSalary) as SecondHighestSalary
from (select distinct(e.salary) as SecondHighestSalary
from employee e
limit 1 offset 1) as a
