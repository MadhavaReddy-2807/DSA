# Write your MySQL query statement below
select d.date_id,d.make_name,count(distinct(lead_id)) as unique_leads,count(distinct(partner_id)) as unique_partners
from dailysales d
group by d.date_id,d.make_name
