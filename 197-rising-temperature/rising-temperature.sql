SELECT id
FROM
(
    SELECT id, recordDate, temperature,
           LAG(recordDate) OVER(ORDER BY recordDate) AS prevdate,
           LAG(temperature) OVER(ORDER BY recordDate) AS prevtemp
    FROM Weather
) x
WHERE temperature > prevtemp
AND DATEDIFF(recordDate, prevdate) = 1;