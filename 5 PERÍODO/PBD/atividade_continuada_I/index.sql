-- Criei me baseando em todas as consultas juntas, me perguntando quais indexes são mais usados e fazendo uma média. Separei elas por tabelas.
--1
Create index idx_lineitem on lineitem (l_returnflag, l_linestatus, l_orderkey, l_shipdate, l_discount, l_extendedprice, l_partkey, l_quantity, l_shipmode, l_receiptdate, l_shipinstruct, l_suppkey);
--2
Create index idx_supplier on SUPPLIER (s_suppkey, s_nationkey, s_name);
--3
Create index idx_part on PART (p_brand, p_type, p_size, p_partkey, p_container);
--4
Create index idx_partsupp on PARTSUPP (ps_supplycost, ps_availqty);
--5
Create index idx_orders on ORDERS (o_orderkey, o_orderpriority, o_orderdate, o_totalprice);
--6
Create index idx_nation on NATION (n_name);
--7
Create index idx_customer on CUSTOMER (c_acctbal, c_phone, c_custkey);