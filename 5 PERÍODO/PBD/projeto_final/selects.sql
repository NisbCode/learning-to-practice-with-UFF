-- 1. QUAIS PERMISSÕES MINHA CONTA TEM
SELECT p.microfoneligado, p.amigospodemverjogos, p.podemassistirlive, p.escondernome FROM PermissaoDePrivacidade p
Inner Join Cargo ON Cargo.permissaoDePrivacidade = p.id
Inner Join Usuario ON Usuario.cargo = Cargo.id
Inner Join Contas ON Contas.id = Usuario.conta
WHERE Contas.nickname = 'Nisb';

-- 2. QUAL O JOGO COM ANALISE MAIS POSITIVA
SELECT MAX(j.analiseCritica) 
AS analiseCritica 
FROM Jogos j;

-- 3. QUAIS JOGOS QUE POSSUEM PROMOÇÕES (DESCONTOS > 0)
SELECT j.nome FROM Jogos j
WHERE j.descontos > 0;

-- 4. QUAIS JOGOS DE UMA DETERMINADA CATEGORIA
SELECT j.nome FROM Jogos j
Inner Join Categoria c ON c.id = j.categoria
WHERE c.tag = 'Terror Psicológico';

-- 5. QUAIS CONQUISTAS EU POSSO TER RELACIONADAS A DLC DE UM DETERMINADO JOGO
SELECT c.titulo FROM Conquistas c
Inner Join Dlc d ON d.id = c.dlc
Inner Join Jogos j ON j.id = d.jogos
WHERE j.nome = 'RimWorld' AND d.nome = 'Royalty';


-- Feitos por outro aluno
--- 6 ----
SELECT
c.id,                          
c.nickname,                    
c.email,                       
c.senha,                       
c.emailRecuperacao,            
c.celular,
u.aparencia,
cart.valor,
cart.extrato
FROM contas c
INNER JOIN usuario u ON u.conta = c.id
INNER JOIN carteira cart ON u.carteira = cart.id
WHERE u.id = ${id_usuario};

--- 7 ---

SELECT
p.id,
p.microfoneLigado,
p.amigosPodemVerJogos,
p.podemAssistirLive,
p.esconderNome
FROM usuario u
INNER JOIN PermissaoDePrivacidade p ON u.privacidade = p.id
WHERE u.id = ${id_usuario};


--- 8 ----

SELECT
count(b.id) as quantidade_de_jogos
FROM usuario u
INNER JOIN biblioteca b ON b.usuario = u.id
WHERE u.id = ${id_usuario}
GROUP BY u.id, b.id;

--- 9 ---- 

SELECT
j.id,
j.nome,
j.descricao,
j.instalacoesPendentes,
j.analiseCritica,
j.datalancamento,
j.precoOriginal,
j.preco,
j.descontos,
j.categoria,
j.empresa,
j.comentarios,
j.compatibilidade,
c.cpu,
c.gpu,
c.so,
c.memoria,
c.armazenamento
FROM jogos j
INNER JOIN ConfiguracoesDeCompatibilidade c
ON j.compatibilidade = c.id
WHERE j.id = ${id_jogo};


--- 10 ----

SELECT
c.mensagens,
c.analiseCritica,
c.dataEnvio,
c.telaTarget,
c.aparencia,
c.usuario
FROM jogos j
INNER JOIN comentarios c on j.comentarios = c.id
WHERE j.id = ${id_jogo};