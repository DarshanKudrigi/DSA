// question: Find all authors who viewed their own articles. Return the result table in any order.

// The Views table has the following columns:
// +-------------+---------+
// | Column Name | Type    |
// +-------------+---------+
// | article_id  | int     |
// | author_id   | int     |
// | viewer_id   | int     |






# Write your MySQL query statement below

SELECT DISTINCT author_id AS id
FROM Views
WHERE author_id = viewer_id
ORDER BY id ASC;
