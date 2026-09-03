// SQL query to find classes with at least 5 students enrolled

// question leval: Easy
// question type: SQL
// question link: https://leetcode.com/problems/classes-with-at-least-5-students/

// The Courses table has the following columns:
// +-------------+---------+
// | Column Name | Type    |
// +-------------+---------+
// | student     | varchar |
// | class       | varchar |
// +-------------+---------+


exaxmple 1:
Input:
+------------+---------+
| student    | class   |
+------------+---------+
| Alice      | Math    |
| Bob        | Math    |
| Charlie    | Math    |
| David      | Math    |
| Eve        | Math    |
| Frank      | Science |
| Grace      | Science |
| Henry      | Science |
| Irene      | Science |
| Jack       | Science |
+------------+---------+

Output:
+---------+
| class   |
+---------+
| Math    |
+---------+

// example 2:
Input:
+------------+---------+
| student    | class   |
+------------+---------+
| Alice      | Math    |
| Bob        | Math    |
| Charlie    | Math    |
| David      | Math    |
| Eve        | Math    |
| Frank      | Science |
| Grace      | Science |
| Henry      | Science |
| Irene      | Science |
| Jack       | Science |
| Karen      | Science |
| Liam       | Science |
| Mia        | Science |
| Noah       | Science |
| Olivia     | Science |
+------------+---------+

Output:
+---------+
| class   |
+---------+
| Math    |
| Science |
+---------+

// Write your MySQL query statement below






SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(student) >= 5;
