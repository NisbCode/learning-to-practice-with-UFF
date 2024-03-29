CREATE TABLE Contas (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    nickname                    VARCHAR(60) NOT NULL,
    email                       VARCHAR(60) NOT NULL UNIQUE,
    senha                       VARCHAR(100) NOT NULL,
    emailRecuperacao            VARCHAR(60),
    celular                     VARCHAR(20),
    PRIMARY KEY(id)
);
CREATE TABLE PermissaoDePrivacidade (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    microfoneLigado             BOOLEAN,
    amigosPodemVerJogos         BOOLEAN,
    podemAssistirLive           BOOLEAN,
    esconderNome                BOOLEAN,
    PRIMARY KEY(id)
);
CREATE TABLE Aparencia (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    tituloEstilo                VARCHAR(60) NOT NULL,
    descricaoEstilo             VARCHAR(100),
    preco                       INT,
    descontos                   INT,
    PRIMARY KEY(id)
);
CREATE TABLE Separadores (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    frase                       VARCHAR(60),
    telaTarget                  VARCHAR(60),
    PRIMARY KEY(id),
    aparencia                   INT,
    CONSTRAINT fk_aparencia FOREIGN KEY(aparencia) REFERENCES Aparencia(id)
);
CREATE TABLE Cargo (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    titulo                      VARCHAR(60) NOT NULL,
    tipoCargo                   VARCHAR(60) NOT NULL,
    PRIMARY KEY(id),
    permissaoDePrivacidade      INT,
    CONSTRAINT fk_permissaoDePrivacidade    FOREIGN KEY(permissaoDePrivacidade) REFERENCES PermissaoDePrivacidade(id),
    aparencia                   INT,
    CONSTRAINT fk_aparencia     FOREIGN KEY(aparencia) REFERENCES Aparencia(id)
);
CREATE TABLE Categoria (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    tag                         VARCHAR(60) NOT NULL,
    descricao                   VARCHAR(350) NOT NULL,
    PRIMARY KEY(id)
);
CREATE TABLE Carteira (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    valor                       INT DEFAULT 0,
    extrato                     VARCHAR(60),
    PRIMARY KEY(id)
);
CREATE TABLE ConfiguracoesDeCompatibilidade (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    cpu                         VARCHAR(60),
    gpu                         VARCHAR(60),
    so                          VARCHAR(60),
    memoria                     VARCHAR(60),
    armazenamento               VARCHAR(60),
    PRIMARY KEY(id)
);
CREATE TABLE Usuario (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    PRIMARY KEY(id),
    conta                       INT UNIQUE,
    CONSTRAINT fk_conta                     FOREIGN KEY(conta) REFERENCES Contas(id),
    cargo                       INT,
    CONSTRAINT fk_cargo                     FOREIGN KEY(cargo) REFERENCES Cargo(id),
    aparencia                   INT,
    CONSTRAINT fk_aparencia                 FOREIGN KEY(aparencia) REFERENCES Aparencia(id),
    carteira                    INT,
    CONSTRAINT fk_carteira                  FOREIGN KEY(carteira) REFERENCES Carteira(id),
    compatibilidade             INT,
    CONSTRAINT fk_compatibilidade           FOREIGN KEY(compatibilidade) REFERENCES ConfiguracoesDeCompatibilidade(id),
    privacidade                 INT,
    CONSTRAINT fk_privacidade           FOREIGN KEY(privacidade) REFERENCES PermissaoDePrivacidade(id)
);
CREATE TABLE Amigos (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    id_usuario                  INT,
    id_amigo                    INT,
    PRIMARY KEY(id),
    id_separador                INT,
    CONSTRAINT fk_separador     FOREIGN KEY(id_separador) REFERENCES Separadores(id),
    CONSTRAINT fk_usuario_1     FOREIGN KEY(id_usuario) REFERENCES Usuario(id),
    CONSTRAINT fk_usuario_2     FOREIGN KEY(id_amigo) REFERENCES Usuario(id)
);
CREATE TABLE Cards (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    preco                       INT,
    PRIMARY KEY(id),
    usuario                     INT,
    CONSTRAINT fk_usuario FOREIGN KEY(usuario) REFERENCES Usuario(id),
    aparencia                   INT,
    CONSTRAINT fk_aparencia FOREIGN KEY(aparencia) REFERENCES Aparencia(id)
);
CREATE TABLE Inventario (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    PRIMARY KEY(id),
    usuario                     INT,
    CONSTRAINT fk_usuario       FOREIGN KEY(usuario) REFERENCES Usuario(id),
    CONSTRAINT fk_cards         FOREIGN KEY(id) REFERENCES Cards(id),
    separadores                 INT,
    CONSTRAINT fk_separadores   FOREIGN KEY(separadores) REFERENCES Separadores(id)
);
CREATE TABLE Comentarios (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    mensagens                   VARCHAR(1000),
    analiseCritica              INT,
    dataEnvio                   DATE,
    telaTarget                  INT,
    PRIMARY KEY(id),
    usuario                     INT,
    CONSTRAINT fk_usuario FOREIGN KEY(usuario) REFERENCES Usuario(id),
    aparencia                   INT,
    CONSTRAINT fk_aparencia FOREIGN KEY(aparencia) REFERENCES Aparencia(id)
);
CREATE TABLE Empresa (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    nome                        VARCHAR(60) NOT NULL,
    PRIMARY KEY(id),
    aparencia                   INT,
    CONSTRAINT fk_aparencia     FOREIGN KEY(aparencia) REFERENCES Aparencia(id)
);
CREATE TABLE Jogos (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    nome                        VARCHAR(60) NOT NULL,
    descricao                   VARCHAR(350) NOT NULL,
    instalacoesPendentes        BOOLEAN,
    analiseCritica              INT,
    datalancamento              DATE,
    desejado                    BOOLEAN,
    precoOriginal               double precision,
    precoCompleto               double precision,
    preco                       double precision,
    descontos                   INT,
    PRIMARY KEY(id),
    categoria                   INT,
    CONSTRAINT fk_categoria         FOREIGN KEY(categoria) REFERENCES Categoria(id),
    empresa                     INT,
    CONSTRAINT fk_empresa           FOREIGN KEY(empresa) REFERENCES Empresa(id),
    comentarios                 INT,
    CONSTRAINT fk_comentarios       FOREIGN KEY(comentarios) REFERENCES Comentarios(id),
    compatibilidade             INT,
    CONSTRAINT fk_compatibilidade   FOREIGN KEY(compatibilidade) REFERENCES ConfiguracoesDeCompatibilidade(id)
);
CREATE TABLE Dlc (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    nome                        VARCHAR(60) NOT NULL,
    descricao                   VARCHAR(350) NOT NULL,
    instalacoesPendentes        BOOLEAN,
    analiseCritica              INT,
    datalancamento              DATE,
    precoOriginal               double precision,
    preco                       double precision,
    descontos                   INT,
    PRIMARY KEY(id),
    categoria                   INT,
    CONSTRAINT fk_categoria         FOREIGN KEY(categoria) REFERENCES Categoria(id),
    jogos                       INT,
    CONSTRAINT fk_jogos         FOREIGN KEY(jogos) REFERENCES Jogos(id),
    empresa                     INT,
    CONSTRAINT fk_empresa           FOREIGN KEY(empresa) REFERENCES Empresa(id),
    comentarios                 INT,
    CONSTRAINT fk_comentarios       FOREIGN KEY(comentarios) REFERENCES Comentarios(id),
    compatibilidade             INT,
    CONSTRAINT fk_compatibilidade   FOREIGN KEY(compatibilidade) REFERENCES ConfiguracoesDeCompatibilidade(id)
);
CREATE TABLE Conquistas (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    titulo                      VARCHAR(60) NOT NULL,
    descricao                   VARCHAR(350) NOT NULL,
    jogos                       INT,
    CONSTRAINT fk_jogos         FOREIGN KEY(jogos) REFERENCES Jogos(id),
    dlc                       INT,
    CONSTRAINT fk_dlc         FOREIGN KEY(dlc) REFERENCES Dlc(id),
    PRIMARY KEY(id)
);
CREATE TABLE Biblioteca (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    PRIMARY KEY(id),
    jogos                       INT,
    CONSTRAINT fk_jogos         FOREIGN KEY(jogos) REFERENCES Jogos(id),
    usuario                     INT,
    CONSTRAINT fk_usuario       FOREIGN KEY(usuario) REFERENCES Usuario(id),
    separadores                 INT,
    CONSTRAINT fk_separadores   FOREIGN KEY(separadores) REFERENCES Separadores(id)
);
CREATE TABLE Loja (
    id                              INT GENERATED BY DEFAULT AS IDENTITY,
    PRIMARY KEY(id),
    usuario                     INT,
    CONSTRAINT fk_usuario           FOREIGN KEY(usuario) REFERENCES Usuario(id),
    jogos                       INT,
    CONSTRAINT fk_jogos             FOREIGN KEY(jogos) REFERENCES Jogos(id),
    cargo                       INT,
    CONSTRAINT fk_cargo             FOREIGN KEY(cargo) REFERENCES Cargo(id),
    amigos                      INT,
    CONSTRAINT fk_amigos            FOREIGN KEY(amigos) REFERENCES Amigos(id),
    categoria                       INT,
    CONSTRAINT fk_categoria         FOREIGN KEY(categoria) REFERENCES Categoria(id),
    aparencia                       INT,
    CONSTRAINT fk_aparencia         FOREIGN KEY(aparencia) REFERENCES Aparencia(id),
    carteira                    INT,
    CONSTRAINT fk_carteira          FOREIGN KEY(carteira) REFERENCES Carteira(id),
    compatibilidade             INT,
    CONSTRAINT fk_compatibilidade   FOREIGN KEY(compatibilidade) REFERENCES ConfiguracoesDeCompatibilidade(id)
);
CREATE TABLE ListaDeDesejos (
    id                              INT GENERATED BY DEFAULT AS IDENTITY,
    PRIMARY KEY(id),
    jogos                       INT,
    CONSTRAINT fk_jogos             FOREIGN KEY(jogos) REFERENCES Jogos(id),
    separadores                     INT,
    CONSTRAINT fk_separadores       FOREIGN KEY(separadores) REFERENCES Separadores(id)
);
CREATE TABLE Noticias (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    titulo                      VARCHAR(60) NOT NULL,
    descricao                   VARCHAR(100),
    criada                      DATE,
    publicada                   BOOLEAN,
    PRIMARY KEY(id),
    jogos                       INT,
    CONSTRAINT fk_jogos             FOREIGN KEY(jogos) REFERENCES Jogos(id),
    comentarios                 INT,
    CONSTRAINT fk_comentarios       FOREIGN KEY(comentarios) REFERENCES Comentarios(id),
    separadores                 INT,
    CONSTRAINT fk_separadores       FOREIGN KEY(separadores) REFERENCES Separadores(id)
);
CREATE TABLE Chat (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    mensagens                   VARCHAR(1000),
    dataEnvio                   DATE,
    PRIMARY KEY(id),
    usuario                     INT,
    CONSTRAINT fk_usuario FOREIGN KEY(usuario) REFERENCES Usuario(id),
    aparencia                   INT,
    CONSTRAINT fk_aparencia FOREIGN KEY(aparencia) REFERENCES Aparencia(id)
);
CREATE TABLE Mods (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    nome                        VARCHAR(60) NOT NULL,
    descricao                   VARCHAR(350) NOT NULL,
    instalacoesPendentes        BOOLEAN,
    analiseCritica              INT,
    datalancamento              DATE,
    PRIMARY KEY(id),
    categoria                   INT,
    CONSTRAINT fk_categoria         FOREIGN KEY(categoria) REFERENCES Categoria(id),
    empresa                     INT,
    CONSTRAINT fk_empresa           FOREIGN KEY(empresa) REFERENCES Empresa(id),
    comentarios                 INT,
    CONSTRAINT fk_comentarios       FOREIGN KEY(comentarios) REFERENCES Comentarios(id),
    compatibilidade             INT,
    CONSTRAINT fk_compatibilidade   FOREIGN KEY(compatibilidade) REFERENCES ConfiguracoesDeCompatibilidade(id),
    chat                        INT,
    CONSTRAINT fk_chat              FOREIGN KEY(chat) REFERENCES Chat(id)
);
CREATE TABLE ListaDeJogosSeguidos (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    PRIMARY KEY(id),
    jogos                       INT,
    CONSTRAINT fk_jogos         FOREIGN KEY(jogos) REFERENCES Jogos(id),
    categoria                   INT,
    CONSTRAINT fk_categoria     FOREIGN KEY(categoria) REFERENCES Categoria(id),
    separadores                 INT,
    CONSTRAINT fk_separadores   FOREIGN KEY(separadores) REFERENCES Separadores(id)
);
CREATE TABLE Comunidade (
    id                          INT GENERATED BY DEFAULT AS IDENTITY,
    descontos                   INT,
    PRIMARY KEY(id),
    categoria                   INT,
    CONSTRAINT fk_categoria                     FOREIGN KEY(categoria) REFERENCES Categoria(id),
    comentarios                 INT,
    CONSTRAINT fk_comentarios                   FOREIGN KEY(comentarios) REFERENCES Comentarios(id),
    compatibilidade             INT,
    CONSTRAINT fk_compatibilidade               FOREIGN KEY(compatibilidade) REFERENCES ConfiguracoesDeCompatibilidade(id),
    CONSTRAINT fk_biblioteca                    FOREIGN KEY(id) REFERENCES Biblioteca(id),
    CONSTRAINT fk_noticias                      FOREIGN KEY(id) REFERENCES Noticias(id),
    CONSTRAINT fk_mods                          FOREIGN KEY(id) REFERENCES Mods(id),
    CONSTRAINT fk_listaDeJogosSeguidos          FOREIGN KEY(id) REFERENCES ListaDeJogosSeguidos(id),
    separadores                 INT,
    CONSTRAINT fk_separadores                   FOREIGN KEY(separadores) REFERENCES Separadores(id),
    dlc                         INT,
    CONSTRAINT fk_dlc                           FOREIGN KEY(dlc) REFERENCES Dlc(id),
    jogos                       INT,
    CONSTRAINT fk_jogos                         FOREIGN KEY(jogos) REFERENCES Jogos(id)
);




INSERT INTO Contas(id, nickname, email, senha, emailRecuperacao, celular)
VALUES (0, 'Nisb', 'emailExemplo1@emailexemplo.com', 'senhadificil22', 'emailExemplo2@emailexemplo.com', '+55021985588558');
INSERT INTO Contas(id, nickname, email, senha, emailRecuperacao, celular)
VALUES (1, 'Fê', 'emailExemplo2@emailexemplo.com', 'senhadificil44', 'emailExemplo4@emailexemplo.com', '+55021975757575');
INSERT INTO Contas(id, nickname, email, senha, emailRecuperacao, celular)
VALUES (2, 'boo', 'emailExemplo3@emailexemplo.com', 'senhadificil66', 'emailExemplo6@emailexemplo.com', '+55021985123558');


INSERT INTO PermissaoDePrivacidade(id, microfoneLigado, amigosPodemVerJogos, podemAssistirLive, esconderNome)
VALUES (0, TRUE, TRUE, TRUE, TRUE);
INSERT INTO PermissaoDePrivacidade(id, microfoneLigado, amigosPodemVerJogos, podemAssistirLive, esconderNome)
VALUES (1, TRUE, TRUE, TRUE, FALSE);
INSERT INTO PermissaoDePrivacidade(id, microfoneLigado, amigosPodemVerJogos, podemAssistirLive, esconderNome)
VALUES (2, FALSE, FALSE, FALSE, FALSE);


INSERT INTO Aparencia(id, tituloEstilo, descricaoEstilo, preco, descontos)
VALUES (0, 'Default', 'Um simples momento mas um grande inicio', 0, 0);
INSERT INTO Aparencia(id, tituloEstilo, descricaoEstilo, preco, descontos)
VALUES (1, 'PREMIUN', 'Pro seu jeito gamer de ser', 7, 2);
INSERT INTO Aparencia(id, tituloEstilo, descricaoEstilo, preco, descontos)
VALUES (2, 'Light', 'Simples, porém, memorável', 4, 0);


INSERT INTO Separadores(id, frase, telaTarget, aparencia)
VALUES (0, 'Linear', 'Principal', 1);
INSERT INTO Separadores(id, frase, telaTarget, aparencia)
VALUES (1, 'Quadrado', 'Biblioteca', 0);
INSERT INTO Separadores(id, frase, telaTarget, aparencia)
VALUES (2, 'Listrado', 'Lista de Desejos', 2);


INSERT INTO ConfiguracoesDeCompatibilidade(id, cpu, gpu, so, memoria, armazenamento)
VALUES (0, 'Intel-5', 'GEFORCE RTX-620', 'Windows', '16 RAM', '1T');
INSERT INTO ConfiguracoesDeCompatibilidade(id, cpu, gpu, so, memoria, armazenamento)
VALUES (1, 'Intel-7', 'GEFORCE GTX-1050', 'Linux', '12 RAM', '1T');
INSERT INTO ConfiguracoesDeCompatibilidade(id, cpu, gpu, so, memoria, armazenamento)
VALUES (2, 'Intel Xeon', 'GEFORCE GTX-1650', 'Windows', '16 RAM', '1T');



INSERT INTO Carteira(id, valor, extrato)
VALUES (0, 57.32, 5198989744656);
INSERT INTO Carteira(id, valor, extrato)
VALUES (1, 78.59, 5198989479168);
INSERT INTO Carteira(id, valor, extrato)
VALUES (2, 5.37, 51989891789189);


INSERT INTO Cargo(id, titulo, tipoCargo, permissaoDePrivacidade, aparencia)
VALUES (0, 'Default', 'Jogadores padrões', 2, 0);
INSERT INTO Cargo(id, titulo, tipoCargo, permissaoDePrivacidade, aparencia)
VALUES (1, 'Líder', 'Influenciadores', 0, 1);


INSERT INTO Usuario(id, conta, cargo, aparencia, carteira, compatibilidade)
VALUES (0, 0, 1, 1, 0, 2);
INSERT INTO Usuario(id, conta, cargo, aparencia, carteira, compatibilidade)
VALUES (1, 1, 1, 1, 1, 0);
INSERT INTO Usuario(id, conta, cargo, aparencia, carteira, compatibilidade)
VALUES (2, 2, 0, 0, 2, 1);


INSERT INTO Amigos(id, id_usuario, id_amigo)
VALUES (0, 0, 1);


INSERT INTO Categoria(id, tag, descricao)
VALUES (0, 'RPG', 'Entre nesse mundo e seja quem você quiser, atue e sinta cada dor e felicidade como a sua própria!!!');
INSERT INTO Categoria(id, tag, descricao)
VALUES (1, 'Administração', 'Coordene cada moeda pra que prospere eternamente.');
INSERT INTO Categoria(id, tag, descricao)
VALUES (2, 'Simulador Vida Real', 'Empregos? Socialização? Já faço tão bem normalmente... VAMOS JOGAR TAMBÉM');
INSERT INTO Categoria(id, tag, descricao)
VALUES (3, 'Terror Psicológico', 'Abordar sobre coisas que pessoas rasas temem sequer pensar...');


INSERT INTO Empresa(id, nome, aparencia)
VALUES (0, 'Ludeon Studios', 2);
INSERT INTO Empresa(id, nome, aparencia)
VALUES (1, 'Fury Studios', 2);
INSERT INTO Empresa(id, nome, aparencia)
VALUES (2, 'Quantic Dream', 2);
INSERT INTO Empresa(id, nome, aparencia)
VALUES (3, 'Concerned/Ape', 2);


INSERT INTO Jogos(id, nome, descricao, instalacoesPendentes, analiseCritica, datalancamento, precoOriginal, desejado, preco, descontos, categoria, empresa)
VALUES (0, 'Stardew Valley', 'Você herdou a antiga fazenda do seu avô, em Stardew Valley. Com ferramentas de segunda-mão e algumas moedas, você parte para dar início a sua nova vida. Será que você vai aprender a viver da terra, a transformar esse matagal em um próspero lar?', FALSE, 10720, '2016-02-26', 24.99, FALSE, 19.99, 20, 2, 3);

INSERT INTO Jogos(id, nome, descricao, instalacoesPendentes, analiseCritica, datalancamento, precoOriginal, desejado, preco, descontos, categoria, empresa)
VALUES (1, 'RimWorld', 'A sci-fi colony sim driven by an intelligent AI storyteller. Generates stories by simulating psychology, ecology, gunplay, melee combat, climate, biomes, diplomacy, interpersonal relationships, art, medicine, trade, and more.', TRUE, 112488, '2018-09-17', 65.99, FALSE, 65.99, 0, 0, 0);

INSERT INTO Jogos(id, nome, descricao, instalacoesPendentes, analiseCritica, datalancamento, precoOriginal, desejado, preco, descontos, categoria, empresa)
VALUES (2, 'Kingdom Two Crowns', 'Construa o seu reino e proteja-o da ameaça dos greed na nova evolucao da premiada série de micro estratégia! Experimente novas tecnologias, unidades, inimigos, montarias e segredos no novo modo campanha solo ou cooperativo.', FALSE, 11229, '2018-12-11', 37.99, FALSE, 37.99, 0, 1, 1);

INSERT INTO Jogos(id, nome, descricao, instalacoesPendentes, analiseCritica, datalancamento, precoOriginal, desejado, preco, descontos, categoria, empresa)
VALUES (3, 'Detroit: Become Human', 'Detroit: Become Human coloca o destino da humanidade e dos androides em suas mãos. Todas as suas escolhas afetam o resultado do jogo, com uma das narrativas mais intrinsecamente ramificadas já criadas.', TRUE, 46703, '2020-06-18', 134.99, FALSE, 134.99, 0, 3, 2);


INSERT INTO Dlc(id, nome, descricao, instalacoesPendentes, analiseCritica, datalancamento, precoOriginal, preco, descontos, categoria, jogos)
VALUES (0, 'Royalty', 'The Empire has arrived. Their refugee fleet settles the rimworld, and seeks allies. Their honor-bound culture wields hyper-advanced technology, while bowing to the ancient traditions of kings and queens.', TRUE, 7365, '2020-02-24', 37.99, 37.99, 0, 0, 1);
INSERT INTO Dlc(id, nome, descricao, instalacoesPendentes, analiseCritica, datalancamento, precoOriginal, preco, descontos, categoria, jogos)
VALUES (1, 'Ideology', 'Belief systems define social roles for leaders, moral guides, and skill specialists. They invoke rituals from gentle festivals to brutal sacrifices. They guide preferences around food, comfort, love, technology, and violence. They venerate specific animals, desire different apparel and tattoos, and give access to different buildings and strategies.', TRUE, 46703, '2020-06-18', 37.99, 37.99, 0, 0, 1);




INSERT INTO Conquistas(id, titulo, descricao, jogos)
VALUES (1, 'Velho Maninheiro', 'Pegue 24 peixes diferentes', 0);
INSERT INTO Conquistas(id, titulo, descricao, jogos)
VALUES (2, 'Coleção Completa', 'Complete a coleção do museu', 0);
INSERT INTO Conquistas(id, titulo, descricao, jogos)
VALUES (3, 'Monocultura', 'Envie 300 itens de uma variedade só pelo correio', 0);

INSERT INTO Conquistas(id, titulo, descricao, dlc)
VALUES (4, 'Divino', 'Faça seus colonos se curvarem a você involuntariamente', 0);
INSERT INTO Conquistas(id, titulo, descricao, dlc)
VALUES (5, 'O Herdeiro', 'Prepare seu filho e o convença a seguir seu legado', 0);
INSERT INTO Conquistas(id, titulo, descricao, dlc)
VALUES (6, 'Taça do Reino', 'Faça seu primeiro festival', 0);
INSERT INTO Conquistas(id, titulo, descricao, dlc)
VALUES (7, 'Simbologia', 'Crie uma tatuagem única para o reino', 1);

INSERT INTO Conquistas(id, titulo, descricao, jogos)
VALUES (8, 'Vem cá, gatinho', 'Recrute um gato', 2);