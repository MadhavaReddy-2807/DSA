# Write your MySQL query statement below
select u.name,sum(case when r.distance is null then 0 else r.distance end) as travelled_distance 
from Users u
left join Rides r on r.user_id=u.id
group by r.user_id 
order by travelled_distance desc ,u.name 