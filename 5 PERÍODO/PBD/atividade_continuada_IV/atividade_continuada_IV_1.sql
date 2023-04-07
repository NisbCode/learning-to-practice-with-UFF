CREATE TABLE funcionario (
    nome        VARCHAR(60) NOT NULL,
    email       VARCHAR(60) NOT NULL,
    sexo        VARCHAR(10) NOT NULL,
    ddd         INT,
    salario     INT,
    telefone    VARCHAR(8),
    ativo       VARCHAR(1),
    endereco    VARCHAR(70) NOT NULL,
    cpf         VARCHAR(11) NOT NULL,
    cidade      VARCHAR(20) NOT NULL,
    estado      VARCHAR(2) NOT NULL,
    bairro      VARCHAR(20) NOT NULL,
    pais        VARCHAR(20) NOT NULL,
    login       VARCHAR(12) NOT NULL,
    senha       VARCHAR(12) NOT NULL,
    news        VARCHAR(8),
    id          INT GENERATED ALWAYS AS IDENTITY,
    PRIMARY KEY(id)
);




CREATE OR REPLACE FUNCTION
DiminuirSalario(cpf_I INT, perceReduc INT)
RETURNS FLOAT AS $$
DECLARE 
    sal FLOAT;
BEGIN
    SELECT salario
    INTO sal
    FROM funcionario
    WHERE cpf = cpf_I::varchar(255);

    RETURN sal-(sal*perceReduc/100);
END;
$$ language plpgsql;

SELECT (DiminuirSalario(123456789, 20)) FROM funcionario;
