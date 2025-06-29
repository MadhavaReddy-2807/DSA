SELECT
    id,
    CASE WHEN SUM(CASE WHEN month = 'Jan' THEN revenue ELSE 0 END) = 0 THEN NULL
         ELSE SUM(CASE WHEN month = 'Jan' THEN revenue ELSE 0 END)
    END AS Jan_Revenue,
    
    CASE WHEN SUM(CASE WHEN month = 'Feb' THEN revenue ELSE 0 END) = 0 THEN NULL
         ELSE SUM(CASE WHEN month = 'Feb' THEN revenue ELSE 0 END)
    END AS Feb_Revenue,
    
    CASE WHEN SUM(CASE WHEN month = 'Mar' THEN revenue ELSE 0 END) = 0 THEN NULL
         ELSE SUM(CASE WHEN month = 'Mar' THEN revenue ELSE 0 END)
    END AS Mar_Revenue,
    
    CASE WHEN SUM(CASE WHEN month = 'Apr' THEN revenue ELSE 0 END) = 0 THEN NULL
         ELSE SUM(CASE WHEN month = 'Apr' THEN revenue ELSE 0 END)
    END AS Apr_Revenue,
    
    CASE WHEN SUM(CASE WHEN month = 'May' THEN revenue ELSE 0 END) = 0 THEN NULL
         ELSE SUM(CASE WHEN month = 'May' THEN revenue ELSE 0 END)
    END AS May_Revenue,
    
    CASE WHEN SUM(CASE WHEN month = 'Jun' THEN revenue ELSE 0 END) = 0 THEN NULL
         ELSE SUM(CASE WHEN month = 'Jun' THEN revenue ELSE 0 END)
    END AS Jun_Revenue,
    
    CASE WHEN SUM(CASE WHEN month = 'Jul' THEN revenue ELSE 0 END) = 0 THEN NULL
         ELSE SUM(CASE WHEN month = 'Jul' THEN revenue ELSE 0 END)
    END AS Jul_Revenue,
    
    CASE WHEN SUM(CASE WHEN month = 'Aug' THEN revenue ELSE 0 END) = 0 THEN NULL
         ELSE SUM(CASE WHEN month = 'Aug' THEN revenue ELSE 0 END)
    END AS Aug_Revenue,
    
    CASE WHEN SUM(CASE WHEN month = 'Sep' THEN revenue ELSE 0 END) = 0 THEN NULL
         ELSE SUM(CASE WHEN month = 'Sep' THEN revenue ELSE 0 END)
    END AS Sep_Revenue,
    CASE WHEN SUM(CASE WHEN month = 'Oct' THEN revenue ELSE 0 END) = 0 THEN NULL
         ELSE SUM(CASE WHEN month = 'Oct' THEN revenue ELSE 0 END)
    END AS Oct_Revenue,
    CASE WHEN SUM(CASE WHEN month = 'Nov' THEN revenue ELSE 0 END) = 0 THEN NULL
         ELSE SUM(CASE WHEN month = 'Nov' THEN revenue ELSE 0 END)
    END AS Nov_Revenue,
    
    CASE WHEN SUM(CASE WHEN month = 'Dec' THEN revenue ELSE 0 END) = 0 THEN NULL
         ELSE SUM(CASE WHEN month = 'Dec' THEN revenue ELSE 0 END)
    END AS Dec_Revenue

FROM
    Department
GROUP BY
    id;
