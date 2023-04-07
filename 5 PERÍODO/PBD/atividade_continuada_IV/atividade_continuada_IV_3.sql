CREATE TABLE cargo (
    cargo                           INT NOT NULL DEFAULT 1,
    nivel                           INT NOT NULL DEFAULT 1,
    contratacao                     DATE NOT NULL DEFAULT CAST(NOW() AS DATE),
    id_funcionario                  INT UNIQUE,
    id                              INT GENERATED ALWAYS AS IDENTITY,
    PRIMARY KEY(id),
    CONSTRAINT fk_funcionario       FOREIGN KEY(id_funcionario) REFERENCES funcionario(id)
);


CREATE OR REPLACE FUNCTION
PromocaoFunc(cpf_I INT, nivelDesejado INT)
RETURNS VARCHAR AS $$
DECLARE
	nivelAtual INT;
	diaAtual TIMESTAMP;
	diaDesej TIMESTAMP;
	idFunc INT;
BEGIN
	diaDesej = CURRENT_TIMESTAMP;
	SELECT nivel, contratacao, id_funcionario INTO nivelAtual, diaAtual, idFunc	FROM cargo 
	INNER JOIN funcionario ON id_funcionario = funcionario.id 
	WHERE funcionario.cpf = cpf_I::VARCHAR(255);
	
	IF((nivelAtual + 1 =  nivelDesejado AND nivelDesejado <= 7) AND diaDesej > diaAtual + '3 year'::interval ) THEN
		UPDATE cargo SET contratacao = CURRENT_TIMESTAMP, nivel = nivelDesejado 
		WHERE id_funcionario = idFunc;
		RETURN ('FUNCIONÁRIO SUBIU DE CARGO.');
	END IF;
	RETURN ('FUNCIONÁRIO NÃO FEZ O TEMPO MÍNIMO DE CONTRIBUIÇÃO PARA PODER SUBIR A ESSE CARGO.');
END;
$$ LANGUAGE plpgsql;

SELECT (PromocaoFunc(123456789, 7)) FROM funcionario;
SELECT (PromocaoFunc(123456789, 2)) FROM funcionario;