# Write your MySQL query statement below

select e.machine_id,round(avg(d.timestamp-e.timestamp),3) as processing_time from activity e join activity d on e.machine_id=d.machine_id and e.process_id=d.process_id and e.activity_type="start" and d.activity_type="end" group by machine_id