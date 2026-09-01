// SQL query to find classes with at least 5 students enrolled








SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(student) >= 5;
