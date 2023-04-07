-- create a table
CREATE TABLE Motoristas (
  cpf_moto INTEGER PRIMARY KEY,
  cnh VARCHAR(25) NOT NULL,
  nome VARCHAR(25) NOT NULL,
  endereco VARCHAR(25) NOT NULL,
  telefone VARCHAR(25) NOT NULL,
  avaliacao_moto VARCHAR(25) NOT NULL
);
CREATE TABLE Carro (
  placa VARCHAR(6) PRIMARY KEY,
  chassi VARCHAR(25) NOT NULL,
  marca VARCHAR(25) NOT NULL,
  modelo VARCHAR(25) NOT NULL,
  ano INTEGER NOT NULL,
  tipo VARCHAR(25) NOT NULL
);
CREATE TABLE MotoristasCarro (
  id_combo INTEGER PRIMARY KEY,
  cpf_moto INTEGER NOT NULL,
  placa VARCHAR(25) NOT NULL,
  FOREIGN KEY(cpf_moto) REFERENCES Motoristas(cpf_moto),
  FOREIGN KEY(placa) REFERENCES Carro(placa)
);
CREATE TABLE Passageiros (
  cpf_pas INTEGER PRIMARY KEY,
  nome VARCHAR(25) NOT NULL,
  endereco VARCHAR(25) NOT NULL,
  telefone VARCHAR(25) NOT NULL,
  avaliacao_pas VARCHAR(25) NOT NULL
);
CREATE TABLE Viagens (
  id_viagem INTEGER PRIMARY KEY,
  origem VARCHAR(25) NOT NULL,
  destino VARCHAR(25) NOT NULL,
  hora_inicio VARCHAR(16) NOT NULL,
  hora_fim VARCHAR(16) NOT NULL,
  cpf_pas INTEGER,
  id_combo INTEGER,
  FOREIGN KEY(cpf_pas) REFERENCES Passageiros(cpf_pas),
  FOREIGN KEY(id_combo) REFERENCES MotoristasCarro(id_combo)
);
