# Write your MySQL query statement below
select  customer_id, count(*) as count_no_trans from Visits 
 
where visit_id not in (select visit_id from Transactions ) 

GROUP BY customer_id