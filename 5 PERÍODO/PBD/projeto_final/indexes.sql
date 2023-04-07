--- 1 --- 

CREATE INDEX index_conta ON usuario USING
btree (conta);

--- 2 ---

CREATE INDEX index_compatibilidade ON jogos USING
btree (compatibilidade);

--- 3 ---

CREATE INDEX index_privacidade ON usuario USING
btree (privacidade);

--- 4 ---

CREATE INDEX index_comentarios ON jogos USING
btree (comentarios);