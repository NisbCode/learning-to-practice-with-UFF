-- Sempre que o jogador desejar adicionar um jogo a lista de jogos desejados, ele automaticamente irá para a tabela

CREATE OR REPLACE FUNCTION
adicionar_lista_desejo()
RETURNS TRIGGER AS $$
DECLARE 
    i RECORD;
BEGIN
    FOR i IN SELECT * FROM Jogos LOOP
        IF(i.desejado = TRUE) THEN 
            INSERT INTO ListaDeDesejos(jogos, separadores)
            VALUES (i.id, 2);
        ELSE 
            DELETE FROM ListaDeDesejos WHERE jogos = i.id;
        END IF;
    END LOOP;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER adicionar_lista_desejo
AFTER UPDATE OR INSERT ON Jogos
FOR EACH ROW
WHEN(pg_trigger_depth() = 0)
EXECUTE PROCEDURE adicionar_lista_desejo();


-- Eu, como usuário, desejo que o jogo RimWorld(id = 1/target no botão) seja colocado na minha lista de desejo
UPDATE Jogos SET desejado = TRUE WHERE id = 1;



-- Sempre que uma novo dlc for adicionada, ele deve informar pra qual jogo se trata e atualizar o preço do jogo completo com todas as dlcs inclusas
CREATE OR REPLACE FUNCTION
adicionar_dlc()
RETURNS TRIGGER AS $$
DECLARE 
    i RECORD;
    preco_original double precision;
BEGIN
    preco_original = 0;
    SELECT SUM(precoOriginal) INTO preco_original FROM Dlc WHERE jogos = NEW.jogos;
    UPDATE Jogos SET precoCompleto = preco_original WHERE id = NEW.jogos;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER adicionar_dlc
AFTER UPDATE OR INSERT ON Dlc
FOR EACH ROW
EXECUTE PROCEDURE adicionar_dlc();

-- Eu, como usuário, desejo que saber claramente quanto ficaria para possuir o jogo em sua íntegra 
INSERT INTO Dlc(id, nome, descricao, instalacoesPendentes, analiseCritica, datalancamento, precoOriginal, preco, descontos, categoria, jogos)
VALUES (2, 'Norse Lands Edition', 'Em Norse Lands, você recebe habilidades originadas dos deuses nórdicos, comanda unidades poderosas, constrói armamentos inspirados nos vikings, resolve enigmas desafiadores e enfrenta inimigos novos.', TRUE, 283, '2021-11-15', 14.99, 14.99, 0, 1, 2);
INSERT INTO Dlc(id, nome, descricao, instalacoesPendentes, analiseCritica, datalancamento, precoOriginal, preco, descontos, categoria, jogos)
VALUES (3, 'Dead Lands', 'Entre nas terras sombrias do reino. Jogue com monarcas únicos, com poderosas habilidades de Bloodstained, um RPG de ação de horror gótico. Cavalgue o gigantesco besouro corcel que espalha armadilhas, a misteriosa montaria morta-viva que invoca barreiras para impedir o avanço da Ganância. Desenvolver o seu reino nunca foi tão assustador!', TRUE, 72, '2020-05-28', 0, 0, 0, 1, 2);


-- Feitos por: Felipe Lopes
-- FUNCTION AND TRIGGER 1 - Adicionar Amigo
CREATE OR REPLACE FUNCTION criar_amigo()
RETURNS TRIGGER
LANGUAGE PLPGSQL
AS
$criar_amigo$
DECLARE
    amigo_convidado integer;
    amigo_enviou integer;
BEGIN
    SELECT id_usuario, id_amigo
    INTO amigo_enviou, amigo_convidado
    FROM amigos
    WHERE id_usuario = NEW.id_amigo
    AND id_amigo = NEW.id_usuario;
	
    IF amigo_convidado is null AND amigo_enviou is null
    THEN    
        INSERT INTO amigos (id_usuario, id_amigo) 
        VALUES (NEW.id_amigo, NEW.id_usuario);
    END IF;
	RETURN NEW;
END;
$criar_amigo$

CREATE TRIGGER criar_amigo_trigger
AFTER INSERT ON amigos
FOR EACH ROW
EXECUTE PROCEDURE criar_amigo();



-- Function 2 - Trigger 2 - Deletado um Amigo
CREATE OR REPLACE FUNCTION deletar_amigo()
RETURNS TRIGGER
LANGUAGE PLPGSQL
AS
$deletar_amigo$
DECLARE
    amigo_convidado integer;
    amigo_enviou integer;
BEGIN
    SELECT id_usuario, id_amigo
    INTO amigo_enviou, amigo_convidado
    FROM amigos
    WHERE id_usuario = OLD.id_amigo
    AND id_amigo = OLD.id_usuario;

    IF amigo_convidado > 0 AND amigo_enviou > 0 
    THEN    
        DELETE FROM amigos WHERE
        id_usuario = OLD.id_amigo AND
        id_amigo = OLD.id_usuario;
    END IF;
	RETURN NEW;
END;
$deletar_amigo$

CREATE OR REPLACE TRIGGER deletar_amigo_trigger
AFTER DELETE ON amigos
FOR EACH ROW
EXECUTE PROCEDURE deletar_amigo();

--Query pra testar essas funções e triggers
insert into amigos (id_amigo, id_usuario) values (2, 1)
select * from amigos
delete from amigos where id_amigo = 2 and id_usuario = 1


-- Function - Trigger - Refazer o preço do jogo
CREATE OR REPLACE FUNCTION preco_desconto()
RETURNS TRIGGER
LANGUAGE PLPGSQL
AS
$preco_desconto$
DECLARE
    var_desconto int;
    preco_original double precision;
	var_desconto_2 double precision;
    var_desconto_porcentagem double precision;
	var_desconto_aplicado double precision;
	var_preco double precision;
BEGIN
    SELECT precoOriginal, descontos, preco
    INTO preco_original, var_desconto, var_preco
    FROM jogos
    WHERE id = NEW.id;

    var_desconto_2 = 100 - var_desconto;
	var_desconto_porcentagem = var_desconto_2 / 100;
	var_desconto_aplicado = preco_original * var_desconto_porcentagem;
	
    IF var_preco = ROUND(var_desconto_aplicado::numeric, 2 )
    THEN
        RETURN NEW;
    ELSIF preco_original is not null AND var_desconto is not null
    THEN
        UPDATE jogos SET preco = ROUND(var_desconto_aplicado::numeric, 2 )
        WHERE id = NEW.id;
    END IF;
	RETURN NEW;
END;
$preco_desconto$

CREATE TRIGGER preco_desconto_trigger
AFTER INSERT or UPDATE ON jogos
FOR EACH ROW
EXECUTE PROCEDURE preco_desconto();


-- Function - Trigger - Refazer o preço da DLC


CREATE OR REPLACE FUNCTION preco_dlc_desconto()
RETURNS TRIGGER
LANGUAGE PLPGSQL
AS
$preco_dlc_desconto$
DECLARE
    var_desconto int;
    preco_original double precision;
	var_desconto_2 double precision;
    var_desconto_porcentagem double precision;
	var_desconto_aplicado double precision;
	var_preco double precision;
BEGIN
    SELECT precoOriginal, descontos, preco
    INTO preco_original, var_desconto, var_preco
    FROM jogos
    WHERE id = NEW.id;

    var_desconto_2 = 100 - var_desconto;
	var_desconto_porcentagem = var_desconto_2 / 100;
	var_desconto_aplicado = preco_original * var_desconto_porcentagem;
	
    IF var_preco = ROUND(var_desconto_aplicado::numeric, 2 )
    THEN
        RETURN NEW;
    ELSIF preco_original is not null AND var_desconto is not null
    THEN
        UPDATE dlc SET preco = ROUND(var_desconto_aplicado::numeric, 2 )
        WHERE id = NEW.id;
    END IF;
	RETURN NEW;
END;
$preco_dlc_desconto$

CREATE TRIGGER preco_dlc_desconto_trigger
AFTER INSERT or UPDATE ON dlc
FOR EACH ROW
EXECUTE PROCEDURE preco_dlc_desconto();

-- Função para retornar todo o valor de um jogo somado as suas dlcs

CREATE OR REPLACE FUNCTION jogo_preco_total(id_jogo int)
RETURNS DOUBLE PRECISION
LANGUAGE PLPGSQL
AS
$jogo_preco_total$
DECLARE
	preco_jogo double precision;
	preco_dlc double precision;
	preco_total double precision;
BEGIN
	
	SELECT preco
	INTO preco_jogo
	FROM jogos
	WHERE id = id_jogo;

	SELECT SUM(preco)
	INTO preco_dlc
	FROM dlc
	WHERE jogos = id_jogo;

	
	IF preco_dlc is not null THEN
		preco_total = preco_jogo + preco_dlc;
		RETURN preco_total;
	ELSE
		RETURN preco_jogo;
	END IF;
END;
$jogo_preco_total$