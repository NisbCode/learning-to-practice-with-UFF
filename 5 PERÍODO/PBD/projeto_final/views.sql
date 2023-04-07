CREATE OR REPLACE VIEW pagina_do_jogo AS
SELECT
count(d.id) as quantidade_de_dlcs,
j.analisecritica,
j.categoria,
j.comentarios,
j.compatibilidade,
j.datalancamento,
j.descontos,
j.descricao,
j.desejado,
j.empresa,
j.instalacoespendentes,
j.nome,
j.preco,
j.precooriginal
FROM jogos j 
LEFT JOIN dlc d ON  d.jogos = j.id
GROUP BY j.id, d.id 


CREATE OR REPLACE VIEW chat_usuario AS
SELECT
c.mensagens,
c.dataEnvio,
c.usuario_recebeu,
c.aparencia
FROM Usuario u
INNER JOIN Chat c ON u.id = c.usuario_enviou

