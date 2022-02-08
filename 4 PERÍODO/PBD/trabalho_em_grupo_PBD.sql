/* CRIAÇÃO DAS TABELAS */

CREATE TABLE Cliente (
cnpj varchar(14) PRIMARY KEY,
razao_social varchar(100),
representante varchar(50),
telefone varchar(11)
);

CREATE TABLE FemanaSoft (
cnpj varchar(14) PRIMARY KEY,
razao_social varchar(100),
endereco varchar(100),
telefone varchar(11)
);

CREATE TABLE Cargo (
idCargo integer PRIMARY KEY,
diretoria boolean,
comercial boolean,
infra boolean,
negocio boolean,
homologador boolean,
dba boolean,
frontender boolean,
devNet boolean,
devJava boolean,
designUxUi boolean
);

CREATE TABLE Funcionario (
idFuncionario integer PRIMARY KEY,
cpf varchar(11),
nome varchar(100),
telefone varchar(11),
pis varchar(11),
idCargo int,
CONSTRAINT fk_FunCarg FOREIGN KEY(idCargo) REFERENCES Cargo(idCargo)
);

CREATE TABLE Comercial (
idComercial integer PRIMARY KEY,
email varchar(50),
telefone varchar(11),
idFuncionario int,
CONSTRAINT fk_FunCom FOREIGN KEY(idFuncionario) REFERENCES Funcionario(idFuncionario)
);

CREATE TABLE Produto (
idProduto integer PRIMARY KEY,
prodNet integer,
prodJava integer
);

CREATE TABLE Infra (
idInfra integer PRIMARY KEY,
tarefaInfra varchar(100),
idFuncionario int,
CONSTRAINT fk_FunInfr FOREIGN KEY(idFuncionario) REFERENCES Funcionario(idFuncionario)
);

CREATE TABLE Suporte (
idChamado integer PRIMARY KEY,
descricao varchar(100),
data date,
idFuncionario int,
CONSTRAINT fk_FunSup FOREIGN KEY(idFuncionario) REFERENCES Funcionario(idFuncionario)
);

CREATE TABLE Negocio (
idNegocio integer PRIMARY KEY,
solucao varchar(100),
idChamado int,
CONSTRAINT fk_SupNeg FOREIGN KEY(idChamado) REFERENCES Suporte(idChamado),
idFuncionario int,
CONSTRAINT fk_FunNeg FOREIGN KEY(idFuncionario) REFERENCES Funcionario(idFuncionario),
idProduto int,
CONSTRAINT fk_ProdNeg FOREIGN KEY(idProduto) REFERENCES Produto(idProduto)
);

CREATE TABLE SupNego (
idSupNego integer PRIMARY KEY,
idChamado int,
CONSTRAINT fk_SupSupNeg FOREIGN KEY(idChamado) REFERENCES Suporte(idChamado),
idNegocio int,
CONSTRAINT fk_SupFunNeg FOREIGN KEY(idNegocio) REFERENCES Negocio(idNegocio)
);

CREATE TABLE DesignUxUi (
idDesignUxUi integer PRIMARY KEY,
solucao varchar(100),
idChamado int,
CONSTRAINT fk_SupDes FOREIGN KEY(idChamado) REFERENCES Suporte(idChamado),
idFuncionario int,
CONSTRAINT fk_FunDes FOREIGN KEY(idFuncionario) REFERENCES Funcionario(idFuncionario),
idProduto int,
CONSTRAINT fk_ProdDes FOREIGN KEY(idProduto) REFERENCES Produto(idProduto)
);

CREATE TABLE Homologacao (
idHomologacao integer PRIMARY KEY,
resolucao varchar(100),
idChamado int,
CONSTRAINT fk_SupHom FOREIGN KEY(idChamado) REFERENCES Suporte(idChamado),
idFuncionario int,
CONSTRAINT fk_FunHom FOREIGN KEY(idFuncionario) REFERENCES Funcionario(idFuncionario),
idProduto int,
CONSTRAINT fk_ProdHom FOREIGN KEY(idProduto) REFERENCES Produto(idProduto)
);

CREATE TABLE EquipeNet (
idEquipeNet integer PRIMARY KEY,
funcionalidades varchar(100),
idChamado int,
CONSTRAINT fk_SupNet FOREIGN KEY(idChamado) REFERENCES Suporte(idChamado),
idFuncionario int,
CONSTRAINT fk_FunNet FOREIGN KEY(idFuncionario) REFERENCES Funcionario(idFuncionario),
idProduto int,
CONSTRAINT fk_ProdNet FOREIGN KEY(idProduto) REFERENCES Produto(idProduto)
);

CREATE TABLE EquipeJava (
idEquipeJava integer PRIMARY KEY,
endPoints varchar(100),
idChamado int,
CONSTRAINT fk_SupJava FOREIGN KEY(idChamado) REFERENCES Suporte(idChamado),
idFuncionario int,
CONSTRAINT fk_FunJava FOREIGN KEY(idFuncionario) REFERENCES Funcionario(idFuncionario),
idProduto int,
CONSTRAINT fk_ProJava FOREIGN KEY(idProduto) REFERENCES Produto(idProduto)
);

CREATE TABLE EquipeDBA (
idEquipeDBA integer PRIMARY KEY,
nivelPermissao varchar(100),
idChamado int,
CONSTRAINT fk_SupDba FOREIGN KEY(idChamado) REFERENCES Suporte(idChamado),
idFuncionario int,
CONSTRAINT fk_FunDba FOREIGN KEY(idFuncionario) REFERENCES Funcionario(idFuncionario),
idProduto int,
CONSTRAINT fk_ProdDba FOREIGN KEY(idProduto) REFERENCES Produto(idProduto)
);

CREATE TABLE EquipeFrontend (
idEquipeFrontEnd integer PRIMARY KEY,
telas varchar(100),
idChamado int,
CONSTRAINT fk_SupFro FOREIGN KEY(idChamado) REFERENCES Suporte(idChamado),
idFuncionario int,
CONSTRAINT fk_FunFro FOREIGN KEY(idFuncionario) REFERENCES Funcionario(idFuncionario),
idProduto int,
CONSTRAINT fk_ProdFro FOREIGN KEY(idProduto) REFERENCES Produto(idProduto)
);



/* INSERÇÕES */

/* Cliente */
INSERT INTO Cliente(cnpj, razao_social, representante, telefone) VALUES ('12345678901234', 'sou uma razao social',            'sou um representante', '22171721700');
INSERT INTO Cliente(cnpj, razao_social, representante, telefone) VALUES ('86168163856460', 'sou uma incrível razao social',   'sou um representante', '22171721700');
INSERT INTO Cliente(cnpj, razao_social, representante, telefone) VALUES ('48048643705684', 'sou uma triste razao social',     'sou um representante', '22171721700');
INSERT INTO Cliente(cnpj, razao_social, representante, telefone) VALUES ('16523368106825', 'sou razao social limitada',       'sou um representante', '22171721700');
INSERT INTO Cliente(cnpj, razao_social, representante, telefone) VALUES ('51035235268181', 'sou uma razao social pensativa',  'sou um representante', '22171721700');

/* FemanaSoft */
INSERT INTO FemanaSoft(cnpj, razao_social, endereco, telefone) VALUES ('40028697262359', 'sou uma razao social diferenciada',            'Rua Jorge da Silva',    '22171721700');
INSERT INTO FemanaSoft(cnpj, razao_social, endereco, telefone) VALUES ('45242434832423', 'sou uma razao social diferenciada',            'Rua Porque Sim',        '22171721700');
INSERT INTO FemanaSoft(cnpj, razao_social, endereco, telefone) VALUES ('48056349036406', 'sou uma razao social diferenciada',            'Rua Carlos Antonio',    '22171721700');
INSERT INTO FemanaSoft(cnpj, razao_social, endereco, telefone) VALUES ('44542422048368', 'sou uma razao social diferenciada',            'Rua Rua de Souza',      '22171721700');
INSERT INTO FemanaSoft(cnpj, razao_social, endereco, telefone) VALUES ('45434848566480', 'sou uma razao social diferenciada',            'Rua Adriana',           '22171721700');

/* Cargo */
INSERT INTO Cargo(idCargo, diretoria, comercial, infra, negocio, homologador, dba, frontender, devNet, devJava, designUxUi) VALUES (1, true, false, false, false, false, false, false, false, false, false);
INSERT INTO Cargo(idCargo, diretoria, comercial, infra, negocio, homologador, dba, frontender, devNet, devJava, designUxUi) VALUES (2, false, true, false, false, false, false, false, false, false, false);
INSERT INTO Cargo(idCargo, diretoria, comercial, infra, negocio, homologador, dba, frontender, devNet, devJava, designUxUi) VALUES (3, false, false, false, false, false, false, true, false, false, false);
INSERT INTO Cargo(idCargo, diretoria, comercial, infra, negocio, homologador, dba, frontender, devNet, devJava, designUxUi) VALUES (4, false, false, false, false, true, false, false, false, false, false);
INSERT INTO Cargo(idCargo, diretoria, comercial, infra, negocio, homologador, dba, frontender, devNet, devJava, designUxUi) VALUES (5, false, false, false, false, false, false, false, false, false, true);

/* Funcionario */
INSERT INTO Funcionario(idFuncionario, cpf, nome, telefone, pis, idCargo) VALUES (1, '12345678901', 'Gustavo da Lorenço',       '22171721700', '21383583554', 1);
INSERT INTO Funcionario(idFuncionario, cpf, nome, telefone, pis, idCargo) VALUES (2, '10987654321', 'Adriana da Silva Ribeiro', '22171721700', '21383583554', 2);
INSERT INTO Funcionario(idFuncionario, cpf, nome, telefone, pis, idCargo) VALUES (3, '56810838468', 'Amanda Marques Porto',     '22171721700', '21383583554', 3);
INSERT INTO Funcionario(idFuncionario, cpf, nome, telefone, pis, idCargo) VALUES (4, '01813518168', 'Melanie Martinez',         '22171721700', '21383583554', 4);
INSERT INTO Funcionario(idFuncionario, cpf, nome, telefone, pis, idCargo) VALUES (5, '70165165213', 'Bruno Madrigal',           '22171721700', '21383583554', 5);

/* Comercial */
INSERT INTO Comercial(idComercial, email, telefone, idFuncionario) VALUES (1, 'exemplo1@gmail.com', '22171721700', 1);
INSERT INTO Comercial(idComercial, email, telefone, idFuncionario) VALUES (2, 'exemplo2@gmail.com', '22171721700', 2);
INSERT INTO Comercial(idComercial, email, telefone, idFuncionario) VALUES (3, 'exemplo3@gmail.com', '22171721700', 3);
INSERT INTO Comercial(idComercial, email, telefone, idFuncionario) VALUES (4, 'exemplo4@gmail.com', '22171721700', 4);
INSERT INTO Comercial(idComercial, email, telefone, idFuncionario) VALUES (5, 'exemplo5@gmail.com', '22171721700', 5);

/* Produto */
INSERT INTO Produto(idProduto, prodNet, prodJava) VALUES (1, 1, 1);
INSERT INTO Produto(idProduto, prodNet, prodJava) VALUES (2, 2, 2);
INSERT INTO Produto(idProduto, prodNet, prodJava) VALUES (3, 3, 3);
INSERT INTO Produto(idProduto, prodNet, prodJava) VALUES (4, 4, 4);
INSERT INTO Produto(idProduto, prodNet, prodJava) VALUES (5, 5, 5);

/* Infra */
INSERT INTO idInfra(idInfra, tarefaInfra, idFuncionario) VALUES (1, 'consertar a tv', 1);
INSERT INTO idInfra(idInfra, tarefaInfra, idFuncionario) VALUES (2, 'imprimir arquivo', 2);
INSERT INTO idInfra(idInfra, tarefaInfra, idFuncionario) VALUES (3, 'comprar mais papel', 3);
INSERT INTO idInfra(idInfra, tarefaInfra, idFuncionario) VALUES (4, 'consertar cafeteira', 4);
INSERT INTO idInfra(idInfra, tarefaInfra, idFuncionario) VALUES (5, 'manutencao dos computadores', 5);

/* Suporte */
INSERT INTO idChamado(idChamado, descricao, idFuncionario, data) VALUES (1, 'formatar computador', '2022-17-06', 1);
INSERT INTO idChamado(idChamado, descricao, idFuncionario, data) VALUES (2, 'atender cliente', '2022-18-06', 2);
INSERT INTO idChamado(idChamado, descricao, idFuncionario, data) VALUES (3, 'verificar ssd', '2022-19-06', 3);
INSERT INTO idChamado(idChamado, descricao, idFuncionario, data) VALUES (4, 'trocar placa mae', '2022-20-06', 4);
INSERT INTO idChamado(idChamado, descricao, idFuncionario, data) VALUES (5, 'consertar entradas P2', '2022-21-06', 5);

/* Homologacao */
INSERT INTO Homologacao(idHomologacao, resolucao, idChamado, idFuncionario, idProduto) VALUES (1, 'texto de resolução', 1, 1, 1);
INSERT INTO Homologacao(idHomologacao, resolucao, idChamado, idFuncionario, idProduto) VALUES (2, 'texto de resolução', 2, 2, 2);
INSERT INTO Homologacao(idHomologacao, resolucao, idChamado, idFuncionario, idProduto) VALUES (3, 'texto de resolução', 3, 3, 3);
INSERT INTO Homologacao(idHomologacao, resolucao, idChamado, idFuncionario, idProduto) VALUES (4, 'texto de resolução', 4, 4, 4);
INSERT INTO Homologacao(idHomologacao, resolucao, idChamado, idFuncionario, idProduto) VALUES (5, 'texto de resolução', 5, 5, 5);

/* EquipeNet */
INSERT INTO EquipeNet(idEquipeNet, funcionalidades, idChamado, idFuncionario, idProduto) VALUES (1, 'texto de funcionalidades', 1, 1, 1);
INSERT INTO EquipeNet(idEquipeNet, funcionalidades, idChamado, idFuncionario, idProduto) VALUES (2, 'texto de funcionalidades', 2, 2, 2);
INSERT INTO EquipeNet(idEquipeNet, funcionalidades, idChamado, idFuncionario, idProduto) VALUES (3, 'texto de funcionalidades', 3, 3, 3);
INSERT INTO EquipeNet(idEquipeNet, funcionalidades, idChamado, idFuncionario, idProduto) VALUES (4, 'texto de funcionalidades', 4, 4, 4);
INSERT INTO EquipeNet(idEquipeNet, funcionalidades, idChamado, idFuncionario, idProduto) VALUES (5, 'texto de funcionalidades', 5, 5, 5);

/* EquipeJava */
INSERT INTO EquipeJava(idEquipeJava, endPoints, idChamado, idFuncionario, idProduto) VALUES (1, 'texto sobre endpoints', 1, 1, 1);
INSERT INTO EquipeJava(idEquipeJava, endPoints, idChamado, idFuncionario, idProduto) VALUES (2, 'texto sobre endpoints', 2, 2, 2);
INSERT INTO EquipeJava(idEquipeJava, endPoints, idChamado, idFuncionario, idProduto) VALUES (3, 'texto sobre endpoints', 3, 3, 3);
INSERT INTO EquipeJava(idEquipeJava, endPoints, idChamado, idFuncionario, idProduto) VALUES (4, 'texto sobre endpoints', 4, 4, 4);
INSERT INTO EquipeJava(idEquipeJava, endPoints, idChamado, idFuncionario, idProduto) VALUES (5, 'texto sobre endpoints', 5, 5, 5);

/* EquipeDBA */
INSERT INTO EquipeDBA(idEquipeDBA, nivelPermissao, idChamado, idFuncionario, idProduto) VALUES (1, 'basico 1', 1, 1, 1);
INSERT INTO EquipeDBA(idEquipeDBA, nivelPermissao, idChamado, idFuncionario, idProduto) VALUES (2, 'basico 2', 2, 2, 2);
INSERT INTO EquipeDBA(idEquipeDBA, nivelPermissao, idChamado, idFuncionario, idProduto) VALUES (3, 'medio', 3, 3, 3);
INSERT INTO EquipeDBA(idEquipeDBA, nivelPermissao, idChamado, idFuncionario, idProduto) VALUES (4, 'alto', 4, 4, 4);
INSERT INTO EquipeDBA(idEquipeDBA, nivelPermissao, idChamado, idFuncionario, idProduto) VALUES (5, 'adm', 5, 5, 5);

/* EquipeFrontend */
INSERT INTO EquipeFrontend(idEquipeFrontend, telas, idChamado, idFuncionario, idProduto) VALUES (1, 'home', 1, 1, 1);
INSERT INTO EquipeFrontend(idEquipeFrontend, telas, idChamado, idFuncionario, idProduto) VALUES (2, 'config', 2, 2, 2);
INSERT INTO EquipeFrontend(idEquipeFrontend, telas, idChamado, idFuncionario, idProduto) VALUES (3, 'user', 3, 3, 3);
INSERT INTO EquipeFrontend(idEquipeFrontend, telas, idChamado, idFuncionario, idProduto) VALUES (4, 'login', 4, 4, 4);
INSERT INTO EquipeFrontend(idEquipeFrontend, telas, idChamado, idFuncionario, idProduto) VALUES (5, 'error', 5, 5, 5);


/* BUSCAS */


