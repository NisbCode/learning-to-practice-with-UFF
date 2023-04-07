CREATE TABLE Passageiro (
    cpf INTEGER PRIMARY KEY,
    nome VARCHAR(25) NOT NULL,
    endereco VARCHAR(25) NOT NULL,
    telefone VARCHAR(25) NOT NULL,
    avaliacao_pas INTEGER NOT NULL
);

CREATE TABLE Motoristas (
    cpf_moto INTEGER PRIMARY KEY,
    cnh VARCHAR(25) NOT NULL,
    nome VARCHAR(25) NOT NULL,
    endereco VARCHAR(25) NOT NULL,
    telefone VARCHAR(25) NOT NULL,
    avaliacao_moto VARCHAR(25) NOT NULL
);

CREATE TABLE Data (
    id_data INTEGER PRIMARY KEY,
    dia INTEGER NOT NULL,
    mes INTEGER NOT NULL,
    ano INTEGER NOT NULL,
    cpf INTEGER NOT NULL,
    FOREIGN KEY(cpf) REFERENCES Passageiro(cpf)
);

CREATE TABLE Viagem (
    id_viagem INTEGER PRIMARY KEY,
    cpf INTEGER NOT NULL,
    id_data INTEGER NOT NULL,
    origem_cidade INTEGER NOT NULL,
    destino_cidade INTEGER NOT NULL,
    FOREIGN KEY(cpf) REFERENCES Passageiro(cpf)
    FOREIGN KEY(id_data) REFERENCES Data(id_data)
    FOREIGN KEY(origem_cidade) REFERENCES Cidade(id_cidade)
    FOREIGN KEY(destino_cidade) REFERENCES Cidade(id_cidade)
);

CREATE TABLE Duracao (
    id_duracao INTEGER PRIMARY KEY,
    tempo_inicio DATETIME, 
    tempo_fim DATETIME
);

CREATE TABLE Regiao (
    id_regiao INTEGER PRIMARY KEY,
    regiao VARCHAR(25) NOT NULL
);

CREATE TABLE Cidade (
    id_cidade INTEGER PRIMARY KEY,
    cidade VARCHAR(25) NOT NULL,
    id_regiao INTEGER,
    FOREIGN KEY(id_regiao) REFERENCES Regiao(id_regiao)
);

CREATE TABLE Marca (
    id_marca INTEGER PRIMARY KEY,
    marca VARCHAR(25) NOT NULL
);

CREATE TABLE Modelo (
    id_modelo INTEGER PRIMARY KEY,
    id_marca INTEGER NOT NULL,
    modelo VARCHAR(25) NOT NULL,
    FOREIGN KEY(id_marca) REFERENCES Marca(id_marca)
);

CREATE TABLE Carro (
    placa VARCHAR(25) PRIMARY KEY,
    chassi VARCHAR(25) NOT NULL,
    ano INTEGER NOT NULL,
    tipo VARCHAR(25) NOT NULL,
    id_modelo INTEGER NOT NULL,
    FOREIGN KEY(id_modelo) REFERENCES Modelo(id_modelo)
);

CREATE TABLE Fato_quantidade (
    placa INTEGER,
    id_cidade INTEGER,
    id_duracao INTEGER,
    id_viagem INTEGER,
    cpf INTEGER,
    quantidade INTEGER,
    FOREIGN KEY(placa) REFERENCES Carro(placa)
    FOREIGN KEY(id_cidade) REFERENCES Cidade(id_cidade)
    FOREIGN KEY(id_duracao) REFERENCES Duracao(id_duracao)
    FOREIGN KEY(id_viagem) REFERENCES Viagem(id_viagem)
    FOREIGN KEY(id_viagem) REFERENCES Viagem(id_viagem)
    FOREIGN KEY(cpf) REFERENCES Passageiro(cpf)
);



-- insert some values
INSERT INTO Viagem VALUES (1, 1, 1, 1, 2);
INSERT INTO Viagem VALUES (2, 2, 2, 2, 3);
INSERT INTO Viagem VALUES (3, 2, 2, 3, 4);
INSERT INTO Viagem VALUES (4, 2, 2, 3, 2);
INSERT INTO Viagem VALUES (5, 2, 2, 2, 4);

INSERT INTO Cidade VALUES (1, "São Gonçalo", 1);
INSERT INTO Cidade VALUES (2, "Niterói", 1);
INSERT INTO Cidade VALUES (3, "Rio de Janeiro", 1);
INSERT INTO Cidade VALUES (4, "Petrópolis", 2);

INSERT INTO Marca VALUES (1, "Ford");
INSERT INTO Marca VALUES (2, "BMW");

INSERT INTO Carro VALUES ("ASD451", "VIN", 1988, "Feio", 1);
INSERT INTO Carro VALUES ("ASDA95", "VIN", 1999, "Feio", 2);
INSERT INTO Carro VALUES ("AFSD61", "VIN", 2005, "Feio", 3);

INSERT INTO Modelo VALUES (1, 1, "Ford Fiesta");
INSERT INTO Modelo VALUES (2, 1, "Ford Mustang");
INSERT INTO Modelo VALUES (3, 2, "BMW X5");

INSERT INTO Duracao VALUES (1, "2012-06-08 12:13:14", "2012-06-08 12:25:16");
INSERT INTO Duracao VALUES (2, "2012-06-08 16:05:14", "2012-06-08 16:49:36");

INSERT INTO Regiao VALUES (1, "Sudeste");
INSERT INTO Regiao VALUES (2, "Norte");

INSERT INTO Passageiro VALUES (48571891515, 'Jorge', 'Rua Antônio Gonçaves, No. 77', '+55 (21) 99631-4298', 4);
INSERT INTO Passageiro VALUES (89741981667, 'Silva', 'Rua Porto Novo, No. 52', '+55 (21) 97625-9675', 3);

INSERT INTO Data VALUES (1, 22, 01, 2002, 48571891515);
INSERT INTO Data VALUES (2, 17, 06, 2000, 89741981667);

INSERT INTO Fato_quantidade(placa, id_cidade, id_viagem, quantidade) 
SELECT "ASD451", Cidade.id_cidade, 1, COUNT(Viagem.id_viagem) FROM Viagem
INNER JOIN Cidade ON Viagem.origem_cidade = Cidade.id_cidade
WHERE Cidade.cidade = "Niterói";

INSERT INTO Fato_quantidade(placa, id_cidade, id_viagem, quantidade) 
SELECT "ASDA95", Cidade.id_cidade, 2, COUNT(Viagem.id_viagem) FROM Viagem
INNER JOIN Cidade ON Viagem.origem_cidade = Cidade.id_cidade
WHERE Cidade.cidade = "Niterói";

INSERT INTO Fato_quantidade(placa, id_cidade, id_viagem, quantidade) 
SELECT "AFSD61", Cidade.id_cidade, 3, COUNT(Viagem.id_viagem) FROM Viagem
INNER JOIN Cidade ON Viagem.origem_cidade = Cidade.id_cidade
WHERE Cidade.cidade = "Rio de Janeiro";

INSERT INTO Fato_quantidade(placa, id_viagem, quantidade) 
SELECT "AFSD61", 4, COUNT(Viagem.id_viagem) FROM Fato_quantidade
INNER JOIN Viagem ON Viagem.id_viagem = 4
INNER JOIN Carro ON Fato_quantidade.placa = Carro.placa
INNER JOIN Modelo ON Carro.id_modelo = Modelo.id_modelo
INNER JOIN Marca ON Modelo.id_marca = Marca.id_marca
WHERE Marca.marca = "BMW";

INSERT INTO Fato_quantidade(id_duracao, id_viagem, quantidade) 
SELECT Duracao.id_duracao, 5, COUNT(Viagem.id_viagem) FROM Fato_quantidade
INNER JOIN Viagem ON Viagem.id_viagem = 5
INNER JOIN Cidade ON Viagem.origem_cidade = Cidade.id_cidade
INNER JOIN Regiao ON Cidade.id_regiao = Regiao.id_regiao
INNER JOIN Duracao ON Fato_quantidade.id_duracao = Duracao.id_duracao
WHERE Cast((JulianDay(tempo_fim) - JulianDay(tempo_inicio)) * 24 * 60 As Integer) < 30 AND Regiao = "Sudeste";

INSERT INTO Fato_quantidade(id_duracao, id_viagem, quantidade) 
SELECT Duracao.id_duracao, 5, COUNT(Viagem.id_viagem) FROM Fato_quantidade
INNER JOIN Viagem ON Viagem.id_viagem = 5
INNER JOIN Cidade ON Viagem.origem_cidade = Cidade.id_cidade
INNER JOIN Regiao ON Cidade.id_regiao = Regiao.id_regiao
INNER JOIN Duracao ON Fato_quantidade.id_duracao = Duracao.id_duracao
WHERE Cast((JulianDay(tempo_fim) - JulianDay(tempo_inicio)) * 24 * 60 As Integer) < 30 AND Regiao = "Sudeste";

INSERT INTO Fato_quantidade(cpf, id_viagem, quantidade) 
SELECT Passageiro.cpf, 6, COUNT(Viagem.id_viagem) FROM Data
INNER JOIN Passageiro ON Passageiro.cpf = Data.cpf
INNER JOIN Viagem ON Viagem.id_viagem = 6
WHERE mes = 06;




-- Quantidade de viagens por cidade
SELECT quantidade AS quantidade_por_cidade, cidade FROM Fato_quantidade
INNER JOIN Cidade ON Fato_quantidade.id_cidade = Cidade.id_cidade
WHERE Cidade.cidade = "Niterói";
--
SELECT Cidade.id_cidade, Cidade.cidade, COUNT(Viagem.id_viagem) AS quantidade_por_cidade FROM Viagem
INNER JOIN Cidade ON Viagem.origem_cidade = Cidade.id_cidade
WHERE Cidade.cidade = "Niterói";


-- Quantidade de viagens por tipo de veículo e marca
SELECT quantidade AS quantidade_por_veiculo_marca, id_viagem FROM Fato_quantidade
INNER JOIN Carro ON Fato_quantidade.placa = Carro.placa
INNER JOIN Modelo ON Carro.id_modelo = Modelo.id_modelo
INNER JOIN Marca ON Modelo.id_marca = Marca.id_marca
WHERE Marca.marca = "BMW";
--
SELECT Modelo.modelo, Marca.marca, COUNT(Viagem.id_viagem) AS quantidade_por_veiculo_marca FROM Fato_quantidade
INNER JOIN Viagem ON Viagem.id_viagem = 4
INNER JOIN Carro ON Fato_quantidade.placa = Carro.placa
INNER JOIN Modelo ON Carro.id_modelo = Modelo.id_modelo
INNER JOIN Marca ON Modelo.id_marca = Marca.id_marca
WHERE Marca.marca = "BMW";


-- Quantidade de viagens com menos de 30 minutos por região do país
SELECT quantidade AS quantidade_por_30_minutos_regiao FROM Fato_quantidade
INNER JOIN Viagem ON Viagem.id_viagem = 5
INNER JOIN Cidade ON Viagem.origem_cidade = Cidade.id_cidade
INNER JOIN Regiao ON Cidade.id_regiao = Regiao.id_regiao
INNER JOIN Duracao ON Fato_quantidade.id_duracao = Duracao.id_duracao
WHERE Cast((JulianDay(tempo_fim) - JulianDay(tempo_inicio)) * 24 * 60 As Integer) < 30 AND Regiao = "Sul";
--
SELECT COUNT(Viagem.id_viagem) AS quantidade_por_30_minutos_regiao, Cast ((JulianDay(tempo_fim) - JulianDay(tempo_inicio)) * 24 * 60 As Integer) AS duracao FROM Duracao
INNER JOIN Viagem ON Viagem.id_viagem = 5
INNER JOIN Cidade ON Viagem.origem_cidade = Cidade.id_cidade
INNER JOIN Regiao ON Cidade.id_regiao = Regiao.id_regiao
WHERE duracao < 30 AND Regiao = "Sudeste";

-- Quantidade de viagens por passageiros com 4 ou 5 estrelas em um determinado mês ou cidade
SELECT quantidade AS quantidade_passageiro_maior_4_mes FROM Fato_quantidade
INNER JOIN Passageiro ON Fato_quantidade.cpf = Passageiro.cpf
INNER JOIN Data ON Passageiro.cpf = Data.cpf
WHERE avaliacao_pas >= 4 AND mes = 01;
--
SELECT Passageiro.cpf, avaliacao_pas, mes, COUNT(Viagem.id_viagem) AS quantidade_passageiro_maior_4_mes FROM Data
INNER JOIN Viagem ON Viagem.id_viagem = 5
INNER JOIN Passageiro ON Passageiro.cpf = Data.cpf
WHERE avaliacao_pas >= 4 AND mes = 01;