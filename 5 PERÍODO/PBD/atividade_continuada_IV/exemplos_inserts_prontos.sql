-- Caso queira exemplos de teste, esses foram o que eu utilizei durante :)

-- QUESTÃO 1
INSERT INTO funcionario(nome, email, sexo, ddd, salario, telefone, ativo, endereco, cpf, cidade, estado, bairro, pais, login, senha, news)
VALUES ('nomeExemplo1', 'emailExemplo1', 'M', '21', '80', '24688642', 'Y', 'endereco1', '123456789', 'cidade1', 'RJ', 'bairro1', 'Brasil', 'login1', 'senhasenha1', 'news1');
INSERT INTO funcionario(nome, email, sexo, ddd, salario, telefone, ativo, endereco, cpf, cidade, estado, bairro, pais, login, senha, news)
VALUES ('nomeExemplo2', 'emailExemplo2', 'M', '21', '90', '24688642', 'Y', 'endereco2', '234567891', 'cidade2', 'RJ', 'bairro2', 'Brasil', 'login2', 'senhasenha2', 'news2');
INSERT INTO funcionario(nome, email, sexo, ddd, salario, telefone, ativo, endereco, cpf, cidade, estado, bairro, pais, login, senha, news)
VALUES ('nomeExemplo3', 'emailExemplo3', 'F', '21', '100', '24688642', 'Y', 'endereco3', '345678912', 'cidade3', 'RJ', 'bairro3', 'Brasil', 'login3', 'senhasenha3', 'news3');
INSERT INTO funcionario(nome, email, sexo, ddd, salario, telefone, ativo, endereco, cpf, cidade, estado, bairro, pais, login, senha, news)
VALUES ('nomeExemplo4', 'emailExemplo4', 'F', '21', '50', '24688642', 'Y', 'endereco4', '456789123', 'cidade4', 'RJ', 'bairro4', 'Brasil', 'login4', 'senhasenha4', 'news4');
INSERT INTO funcionario(nome, email, sexo, ddd, salario, telefone, ativo, endereco, cpf, cidade, estado, bairro, pais, login, senha, news)
VALUES ('nomeExemplo5', 'emailExemplo5', 'F', '21', '30', '24688642', 'Y', 'endereco5', '567891234', 'cidade5', 'RJ', 'bairro5', 'Brasil', 'login5', 'senhasenha5', 'news5');
INSERT INTO funcionario(nome, email, sexo, ddd, salario, telefone, ativo, endereco, cpf, cidade, estado, bairro, pais, login, senha, news)
VALUES ('nomeExemplo6', 'emailExemplo6', 'F', '21', '20', '24688642', 'Y', 'endereco6', '678912345', 'cidade6', 'RJ', 'bairro6', 'Brasil', 'login6', 'senhasenha6', 'news6');


-- QUESTÃO 2
INSERT INTO faltasJustificativas(faltas, justificativas, id_funcionario) VALUES (4, 2, 1);
INSERT INTO faltasJustificativas(id_funcionario) VALUES (2);
INSERT INTO faltasJustificativas(faltas, id_funcionario) VALUES (3, 3);
INSERT INTO faltasJustificativas(faltas, id_funcionario) VALUES (7, 4);
INSERT INTO faltasJustificativas(faltas, id_funcionario) VALUES (6, 5);
INSERT INTO faltasJustificativas(faltas, id_funcionario) VALUES (1, 6);


UPDATE faltasJustificativas SET faltas = 7 WHERE id_funcionario = 3;
UPDATE faltasJustificativas SET justificativas = 5 WHERE id_funcionario = 4;


-- QUESTÃO 3
INSERT INTO cargo(cargo, nivel, contratacao, id_funcionario) 
VALUES (1, 1, '2015-07-05', 1);
INSERT INTO cargo(cargo, nivel, id_funcionario) 
VALUES (2, 2, 2);
INSERT INTO cargo(cargo, nivel, id_funcionario) 
VALUES (3, 3, 3);
INSERT INTO cargo(cargo, nivel, id_funcionario) 
VALUES (3, 4, 4);
INSERT INTO cargo(cargo, nivel, id_funcionario) 
VALUES (2, 5, 5);
INSERT INTO cargo(cargo, nivel, id_funcionario) 
VALUES (1, 6, 6);
INSERT INTO cargo(cargo, nivel) 
VALUES (3, 7);
