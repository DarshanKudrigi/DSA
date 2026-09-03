// question: Find all authors who viewed their own articles. Return the result table in any order.

// The Views table has the following columns:
// +-------------+---------+
// | Column Name | Type    |
// +-------------+---------+
// | article_id  | int     |
// | author_id   | int     |
// | viewer_id   | int     |
// +-------------+---------+

//exxxxample 1:
Input:
+-------------+-----------+-----------+
| article_id  | author_id | viewer_id |
+-------------+-----------+-----------+
| 1           | 3         | 5         |
| 2           | 1         | 1         |
| 3           | 2         | 3         |
| 4           | 4         | 4         |
+-------------+-----------+-----------+


Output:
+----+
| id |
+----+
| 1  |
| 4  |
| 3  |
| 2  |
| 4  |
| 3  |
| 2  |
+----+



# Write your MySQL query statement below

SELECT DISTINCT author_id AS id
FROM Views
WHERE author_id = viewer_id
ORDER BY id ASC;
