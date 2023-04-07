//Perfis
CREATE
(p1:Perfil {nome: "José", data_de_nascimento: "19/05/1987", pais: "Brasil", cidade: "Rio de Janeiro", sexo: "Masculino", religiao: "Ateu", estado_civil: "Casado"}),
(p2:Perfil {nome: "Mauro", data_de_nascimento: "08/11/1992", pais: "Brasil", cidade: "São Paulo", sexo: "Masculino", religiao: "Candomblé", estado_civil: "Separado"}),
(p3:Perfil {nome: "Leda", data_de_nascimento: "26/03/1991", pais: "França", cidade: "París", sexo: "Feminino", religiao: "Ateu", estado_civil: "Solteiro(a)"}),
(p4:Perfil {nome: "Erika", data_de_nascimento: "11/12/1999", pais: "Brasil", cidade: "Curitiba", sexo: "Feminino", religiao: "Católica", estado_civil: "Casada"}),
(p5:Perfil {nome: "Daniel", data_de_nascimento: "30/04/1990", pais: "Portugal", cidade: "Lisboa", sexo: "Masculino", religiao: "Evangélico", estado_civil: "Solteiro(a)"}),
(p6:Perfil {nome: "Edilson", data_de_nascimento: "10/10/1988", pais: "Brasil", cidade: "Rio de Janeiro", sexo: "Masculino", religiao: "Cristão", estado_civil: "Casado"}),
(p7:Perfil {nome: "Aline", data_de_nascimento: "20/09/1982", pais: "Brasil", cidade: "Fortaleza", sexo: "Feminino", religiao: "Agnóstico", estado_civil: "Solteiro(a)"});

//Relacionamentos
MATCH (p:Perfil {nome: "Mauro"}) WITH p
MATCH (s:Perfil) WHERE not s.nome IN ["José", "Mauro"]
CREATE (p)-[:SEGUE]->(s);

MATCH (p:Perfil {nome: "Leda"})
MATCH (s:Perfil) WHERE s.nome IN ["Mauro", "Erika", "Edilson"]
CREATE (p)-[:SEGUE]->(s);

MATCH (p:Perfil {nome: "Erika"})
MATCH (s:Perfil) WHERE s.nome IN ["Mauro", "Leda", "Aline"]
CREATE (p)-[:SEGUE]->(s);

MATCH (p:Perfil {nome: "Daniel"})
MATCH (s:Perfil) WHERE s.nome IN ["Mauro", "Edilson", "Aline"]
CREATE (p)-[:SEGUE]->(s);

MATCH (p:Perfil {nome: "Edilson"})
MATCH (s:Perfil) WHERE s.nome IN ["Mauro", "Leda", "Daniel"]
CREATE (p)-[:SEGUE]->(s);

MATCH (p:Perfil {nome: "Aline"})
MATCH (s:Perfil) WHERE s.nome IN ["Daniel", "Mauro", "Erika", "José"]
CREATE (p)-[:SEGUE]->(s);

MATCH (p:Perfil {nome: "José"})
MATCH (s:Perfil {nome: "Aline"})
CREATE (p)-[:SEGUE]->(s);

//Cenários
MATCH (p:Perfil {nome: "Mauro"})
CREATE (p)-[:ENVIOU]->(m:Mensagem {texto: "Bom dia"}) WITH p, m
MATCH (p)-[:SEGUE]->(amigos_mauro:Perfil) WITH m, amigos_mauro
CREATE (amigos_mauro)<-[:RECEBEU]-(m);

MATCH (p:Perfil {nome: "Mauro"})
CREATE (p)-[:POSTOU]->(f:Foto {foto: "Nova Foto"}) WITH p, f
MATCH (p)-[:SEGUE]->(amigos_mauro:Perfil) WITH f, amigos_mauro
CREATE (amigos_mauro)-[:COMENTOU]->(f);

MATCH (p:Perfil {nome: "Aline"})
CREATE (p)-[:POSTOU]->(t:Poema {nome: "A Pedra"}) WITH p, t
MATCH (p)-[:SEGUE]->(amigos_aline:Perfil) WITH t, amigos_aline
CREATE (amigos_aline)-[:COMENTOU]->(t);

MATCH (a:Perfil {nome: "Aline"})
MATCH (jose:Perfil {nome: "José"})
CREATE (a)-[:ENVIOU]->(ma:Mensagem {texto: "Que mensagem chata"})<-[:RECEBEU]-(jose) WITH ma
MATCH (mauro:Perfil)-[:ENVIOU]-(m_mauro:Mensagem) WHERE m_mauro.texto = "Bom dia" WITH ma, m_mauro
CREATE (ma)-[:FALA_SOBRE]->(m_mauro);