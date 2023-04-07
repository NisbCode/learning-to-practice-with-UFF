CREATE TABLE faltasJustificativas (
    faltas                          INT NOT NULL DEFAULT 0,
    justificativas                  INT NOT NULL DEFAULT 0,
    id_funcionario                  INT UNIQUE,
    id                              INT GENERATED ALWAYS AS IDENTITY,
    PRIMARY KEY(id),
    CONSTRAINT fk_funcionario       FOREIGN KEY(id_funcionario) REFERENCES funcionario(id)
);



CREATE OR REPLACE FUNCTION
DemitirFunc()
RETURNS TRIGGER AS $$
DECLARE 
    i RECORD;
    ativo VARCHAR(1);
    faltasAtuais INT;
BEGIN
    FOR i IN SELECT * FROM faltasJustificativas WHERE justificativas > 0 LOOP
            faltasAtuais = i.faltas - i.justificativas;
            UPDATE faltasJustificativas SET faltas = faltasAtuais WHERE id_funcionario = i.id_funcionario;
            IF(faltasAtuais < 5) THEN UPDATE funcionario SET ativo = 'Y' WHERE i.id_funcionario = funcionario.id;END IF;
    END LOOP;
    FOR i IN SELECT * FROM faltasJustificativas WHERE faltas > 5 LOOP
            UPDATE funcionario SET ativo = 'N' WHERE i.id_funcionario = funcionario.id;
    END LOOP;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER demitir
AFTER UPDATE ON faltasJustificativas
FOR EACH ROW
WHEN(pg_trigger_depth() = 0)
EXECUTE PROCEDURE DemitirFunc();
