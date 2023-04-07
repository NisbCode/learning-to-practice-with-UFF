//1Quais são os amigos dos amigos de José?
MATCH (p:Perfil {nome: "José"})-[:SEGUE]->(ada:Perfil)<-[:SEGUE]-(ada_jose:Perfil)
WHERE ada.nome <> "José"
RETURN ada_jose;

//2Quais amigos de José comentaram a foto de Mauro?
MATCH (p:Perfil {nome: "José"})-[:SEGUE]->(amigos:Perfil)-[:COMENTOU]->(f:Foto)<-[:POSTOU]-(m:Perfil {nome: "Mauro"})
RETURN amigos;

//3Atualize a cidade de Aline para Niterói.
MATCH (p:Perfil {nome: "Aline"})
SET p.cidade = "Niterói";

//4Qual o menor caminho seguindo qualquer relacionamento de José para Mauro?
MATCH caminho=(jose:Perfil {nome: "José"})-[]-()-[]-(m:Perfil {nome: "Mauro"})
RETURN caminho;