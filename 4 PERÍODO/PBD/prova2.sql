A tabela de Item pedido já possui uma chave primária, logo, não pode existir outra, na mesma, não posso
colocar o campo como único, já que podemos ter mais de um item para o mesmo pedido.

/*
Escreva os comandos SQL para criar as tabelas ItemPedido, Produto e Pedido,
incluindo as restrições de integridade que se aplicam. Assuma que, ao excluir um
pedido, todos os itens de pedido relacionados devem ser excluídos
automaticamente. Assuma também que um produto não pode ser excluído caso exista
algum item de pedido relacionado a ele. Além disso, ao alterar o código de um
produto, todos os itens de pedido relacionados devem ser alterados
automaticamente. Em um pedido, assuma que a quantidade não pode ser nula. Se, por
algum motivo, não for possível definir alguma restrição de integridade,
justifique.
*/
CREATE TABLE Cliente (
CodCli integer PRIMARY KEY,
nome varchar (50),
idade int CHECK (idade > 0 AND idade < 160)
);
CREATE TABLE Produto (
CodProd int PRIMARY KEY,
descricao varchar (250)
);
CREATE TABLE Pedido (
numPedido int PRIMARY KEY,
data date,
CodCli int,
CONSTRAINT fk_PedCli FOREIGN KEY (CodCli) REFERENCES Cliente (CodCli)
);
CREATE TABLE ItemPedido (
numItem int PRIMARY KEY,
CodProd int NOT NULL,
Quant int NOT NULL,
PrecoUnit float,
numPedido int NOT NULL,
CONSTRAINT fk_ItemPed FOREIGN KEY (numPedido) REFERENCES Pedido (numPedido) ON
DELETE CASCADE,

CONSTRAINT fk_ItemProd FOREIGN KEY (CodProd) REFERENCES Produto (CodProd) ON
DELETE NO ACTION ON UPDATE CASCADE
);

/* CÓDIGOS DE APOIO PARA AS QUESTÕES */
INSERT INTO Cliente (CodCli, nome, idade) VALUES (01, 'Pablo', 50);
INSERT INTO Cliente (CodCli, nome, idade) VALUES (02, 'Escobar', 80);
INSERT INTO Cliente (CodCli, nome, idade) VALUES (03, 'João da Silva', 22);
INSERT INTO Cliente (CodCli, nome, idade) VALUES (04, 'Melanie', 33);
INSERT INTO Cliente (CodCli, nome, idade) VALUES (05, 'Martinez', 15);
INSERT INTO Cliente (CodCli, nome, idade) VALUES (06, 'Jorge Silva Cardoso
Oliveira', 18);
INSERT INTO Produto (CodProd, descricao) VALUES (01, 'Eu sou um texto que
descreve esse belo produto');
INSERT INTO Produto (CodProd, descricao) VALUES (02, 'Eu também sou um texto que
descreve esse belo produto');
INSERT INTO Produto (CodProd, descricao) VALUES (03, 'Eu sou ainda mais um texto
que descreve esse belo produto, novidade...');
INSERT INTO Pedido (numPedido, data, CodCli) VALUES (07, CURRENT_TIMESTAMP, 03);
INSERT INTO Pedido (numPedido, data, CodCli) VALUES (05, CURRENT_TIMESTAMP, 03);
INSERT INTO Pedido (numPedido, data, CodCli) VALUES (03, CURRENT_TIMESTAMP, 03);
INSERT INTO Pedido (numPedido, data, CodCli) VALUES (04, '01/22/2001', 01);
INSERT INTO Pedido (numPedido, data, CodCli) VALUES (02, '02/01/2000', 01);
INSERT INTO Pedido (numPedido, data, CodCli) VALUES (06, '02/05/2000', 04);
INSERT INTO Pedido (numPedido, data, CodCli) VALUES (111, CURRENT_TIMESTAMP, 04);
INSERT INTO ItemPedido (numItem, Quant, PrecoUnit, numPedido, CodProd) VALUES (3,
1, 4.37, 111, 01);
INSERT INTO ItemPedido (numItem, Quant, PrecoUnit, numPedido, CodProd) VALUES (4,
2, 5.27, 111, 02);
INSERT INTO ItemPedido (numItem, Quant, PrecoUnit, numPedido, CodProd) VALUES (5,
1, 8.89, 111, 03);
INSERT INTO ItemPedido (numItem, Quant, PrecoUnit, numPedido, CodProd) VALUES (6,
19, 8.89, 04, 01);
INSERT INTO ItemPedido (numItem, Quant, PrecoUnit, numPedido, CodProd) VALUES (7,
13, 8.89, 04, 03);

/*
Escreva comandos SQL para incluir um novo pedido no banco de dados, com os
seguintes dados: Pedido número 123, do cliente 02 (assuma que o cliente já está
cadastrado).
*/
INSERT INTO Pedido (numPedido, data, CodCli) VALUES (123, CURRENT_TIMESTAMP, 02);
/*
(a) 2 unidades do produto de código 02, custando 1,00 cada unidade
*/
INSERT INTO ItemPedido (numItem, Quant, PrecoUnit, numPedido, CodProd) VALUES (1,
2, 1.00, 123, 02);
/*
(b) 3 unidades do produto de código 03, custando 2,30 cada unidade
*/
INSERT INTO ItemPedido (numItem, Quant, PrecoUnit, numPedido, CodProd) VALUES (2,
3, 2.30, 123, 03);

/*
Escreva um comando SQL para excluir todos os pedidos do cliente João da Silva.
*/
DELETE FROM Pedido
WHERE CodCli IN (
SELECT CodCli
FROM Cliente
WHERE nome = 'João da Silva');

/*
Faça uma consulta SQL que seleciona os nomes dos clientes que
fizeram algum pedido entre 01/01/2000 e 01/01/2002.
*/
SELECT nome FROM Cliente INNER JOIN Pedido ON Pedido.CodCli = Cliente.CodCli
WHERE (data) between '2000-01-01' AND '2002-01-01';

/*
Faça uma consulta SQL que retorna o valor total do pedido número 111.
*/
SELECT SUM(PrecoUnit * Quant) AS TOTAL
FROM ItemPedido
WHERE numPedido = 111

/*
Faça uma consulta SQL que retorna o nome do cliente e a descrição de produtos que
o cliente pediu em quantidade superior a 10 unidades.
*/
SELECT Cliente.nome, Produto.descricao
FROM Cliente
INNER JOIN Pedido
ON Pedido.CodCli = Cliente.CodCli
INNER JOIN ItemPedido
ON ItemPedido.numPedido = Pedido.numPedido
INNER JOIN Produto
ON Produto.CodProd = ItemPedido.CodProd
WHERE Quant > 10

/*
Faça uma consulta SQL que retorne os nomes dos clientes que nunca fizeram nenhum
pedido
*/
SELECT nome
FROM Cliente
LEFT JOIN Pedido
ON Pedido.CodCli = Cliente.CodCli
WHERE Pedido.CodCli IS NULL;

/*
Faça uma consulta SQL que mostre o número do pedido, o código do produto e a
quantidade solicitada de produtos cuja descrição contenha a palavra “novidade”.
*/
SELECT Pedido.numPedido, Produto.CodProd, ItemPedido.Quant
FROM Pedido
INNER JOIN ItemPedido
ON ItemPedido.numPedido = Pedido.numPedido
INNER JOIN Produto
ON Produto.CodProd = ItemPedido.CodProd
WHERE Produto.descricao LIKE '%novidade%'