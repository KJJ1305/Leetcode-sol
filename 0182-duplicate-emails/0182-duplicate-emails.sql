# Write your MySQL query statement below

SELECT email from 
(
    select email,Count(email) as cun
    from person
    group by email
) as table2
where cun>1;
