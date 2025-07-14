select *
from(
select s1.score,(select count(distinct(s2.score))
from scores s2
where s1.score<s2.score)+1 as "rank"
from scores s1) as a
order by a.rank