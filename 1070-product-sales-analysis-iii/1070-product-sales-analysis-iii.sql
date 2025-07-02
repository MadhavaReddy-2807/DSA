select s.product_id,s.year as first_year,s.quantity,s.price
from sales s
join (
    select product_id,min(year) as first_year
    from sales p
    group by product_id
) as s1
on s.year=s1.first_year and s1.product_id=s.product_id