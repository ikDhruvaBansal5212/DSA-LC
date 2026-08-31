select id,
    case
     when p_id IS NULL then 'Root'
     when id not in(
        select p_id from tree where p_id is not null
     ) then 'Leaf'
     else 'Inner'
     END as type
     from tree;