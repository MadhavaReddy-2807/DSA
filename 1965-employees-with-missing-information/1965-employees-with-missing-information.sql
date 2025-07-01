# Write your MySQL query statement below
select *
from (select e.employee_id
from employees e
left join salaries s on e.employee_id=s.employee_id 
where s.employee_id is null
union
select s.employee_id
from salaries s
left join employees e on e.employee_id=s.employee_id 
where e.employee_id is null) as e1
order by e1.employee_id