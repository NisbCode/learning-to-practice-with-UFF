select o_orderpriority, count(*) 
as order_count 
from ORDERS 
where o_orderdate >= date '1995-01-01' 
and o_orderdate < date '1995-01-01' + interval '3' month 
and exists (select * from LINEITEM 
    where l_orderkey = o_orderkey and l_commitdate < l_receiptdate) 
group by o_orderpriority 
order by o_orderpriority;



Create index idx_orders on ORDERS (o_orderpriority);

select idx_orders, count(*) 
as order_count 
from ORDERS 
where o_orderdate >= date '1995-01-01' 
and o_orderdate < date '1995-01-01' + interval '3' month 
and exists (select * from LINEITEM 
    where l_orderkey = o_orderkey and l_commitdate < l_receiptdate) 
group by idx_orders 
order by idx_orders;
