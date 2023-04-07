//1o. passo:
// Script de criação inicial do banco
create (p1:Perfil {nome: "José", data_de_nascimento: "13/06/2006", pais: "Portugal", cidade: "Lisboa", sexo: "Masculino", religiao: "Ateu", estado_civil: "Separado"}),
(p2:Perfil {nome: "Mauro", data_de_nascimento: "04/04/2004", pais: "Brasil", cidade: "Rio de Janeiro", sexo: "Masculino", religiao: "Candomblé", estado_civil: "Separado"}),
(p3:Perfil {nome: "Leda", data_de_nascimento: "22/03/1998", pais: "México", cidade: "Ciudad de México", sexo: "Feminino", religiao: "Ateu", estado_civil: "Casada"}),
(p4:Perfil {nome: "Erika", data_de_nascimento: "17/06/2000", pais: "Brasil", cidade: "Rio de Janeiro", sexo: "Feminino", religiao: "Agnóstico", estado_civil: "Casada"}),
(p5:Perfil {nome: "Daniel", data_de_nascimento: "30/12/1999", pais: "Brasil", cidade: "Rio de Janeiro", sexo: "Masculino", religiao: "Ateu", estado_civil: "Solteiro"}),
(p6:Perfil {nome: "Edilson", data_de_nascimento: "22/02/2002", pais: "Brasil", cidade: "Rio de Janeiro", sexo: "Masculino", religiao: "Evangélico", estado_civil: "Solteiro"}),
(p7:Perfil {nome: "Aline", data_de_nascimento: "24/10/1972", pais: "Espanha", cidade: "Madrid", sexo: "Feminino", religiao: "Catolicismo", estado_civil: "Separada"});

//2o. passo:
// Ligações de perfis
match (p:Perfil {nome: "Erika"})
match (s:Perfil) where s.nome in ["Mauro", "Leda", "Aline"]
create (p)-[:SEGUE]->(s);
match (p:Perfil {nome: "Aline"})
match (s:Perfil) where s.nome in ["Daniel", "Mauro", "Erika", "José"]
create (p)-[:SEGUE]->(s);
match (p:Perfil {nome: "Daniel"})
match (s:Perfil) where s.nome in ["Mauro", "Edilson", "Aline"]
create (p)-[:SEGUE]->(s);
match (p:Perfil {nome: "Leda"})
match (s:Perfil) where s.nome in ["Mauro", "Erika", "Edilson"]
create (p)-[:SEGUE]->(s);
match (p:Perfil {nome: "Edilson"})
match (s:Perfil) where s.nome in ["Mauro", "Leda", "Daniel"]
create (p)-[:SEGUE]->(s);
match (p:Perfil {nome: "José"})
match (s:Perfil {nome: "Aline"})
create (p)-[:SEGUE]->(s);
match (p:Perfil {nome: "Mauro"}) with p
match (s:Perfil) where not s.nome in ["José", "Mauro"]
create (p)-[:SEGUE]->(s);

match (p:Perfil {nome: "Mauro"})
create (p)-[:ENVIOU]->(m:Mensagem {texto: "Bom dia"}) with p, m
match (p)-[:SEGUE]->(amigos_mauro:Perfil) with m, amigos_mauro
create (amigos_mauro)<-[:RECEBEU]-(m);
match (p:Perfil {nome: "Mauro"})
create (p)-[:POSTOU]->(f:Foto {foto: "Nova Foto"}) with p, f
match (p)-[:SEGUE]->(amigos_mauro:Perfil) with f, amigos_mauro
create (amigos_mauro)-[:COMENTOU]->(f);
match (p:Perfil {nome: "Aline"})
create (p)-[:POSTOU]->(t:Poema {nome: "A Pedra"}) with p, t
match (p)-[:SEGUE]->(amigos_aline:Perfil) with t, amigos_aline
create (amigos_aline)-[:COMENTOU]->(t);
match (a:Perfil {nome: "Aline"})
match (jose:Perfil {nome: "José"})
create (a)-[:ENVIOU]->(ma:Mensagem {texto: "Que mensagem chata"})<-[:RECEBEU]-(jose) with ma
match (mauro:Perfil)-[:ENVIOU]-(m_mauro:Mensagem) where m_mauro.texto = "Bom dia" with ma, m_mauro
create (ma)-[:FALA_SOBRE]->(m_mauro);



//3o. passo:
//Constultas
// 1. Quais são os amigos dos amigos de José?
match (p:Perfil {nome: "José"})-[:SEGUE]->(j:Perfil)<-[:SEGUE]-(j_jose:Perfil)
where j.nome <> "José"
RETURN j_jose;
// 2. Quais amigos de José comentaram a foto de Mauro?
match (p:Perfil {nome: "José"})-[:SEGUE]->(amigos:Perfil)-[:COMENTOU]->(f:Foto)<-[:POSTOU]-(m:Perfil {nome: "Mauro"})
RETURN amigos.nome;
