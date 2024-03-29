select
	sum(l_extendedprice * l_discount) as revenue
from
	LINEITEM
where
	l_shipdate >= date '1994-01-01'
	and l_shipdate < date '1994-01-01' + interval '1' year
	and l_discount between 0.06 - 0.01 and 0.06 + 0.01
	and l_quantity < 24;



Create index idx_lineitem on lineitem (l_shipdate, l_discount);

select
	sum(l_extendedprice * l_discount) as revenue
from
	LINEITEM
where
	idx_lineitem >= date '1994-01-01'
	and idx_lineitem < date '1994-01-01' + interval '1' year
	and l_discount between 0.06 - 0.01 and 0.06 + 0.01
	and l_quantity < 24;
