/*
% Tabela com pessoas %
Pessoa(CodPessoa, Nome, idade, UF) -- CodPessoa é chave primária
% Tabela com as receitas. CodPessoa indica a Pessoa que postou a receita no site %
Receita(CodReceita, DataPostagem, Título, ModoPreparo, CodPessoa) -- CodReceita é chave primária
CodPessoa referencia Pessoa (CodPessoa)
% Tabela que informa os ingredientes %
Ingrediente(CodIngrediente, Descrição, Unidade) - CodIngrediente é chave primária
% Tabela que informa os ingredientes de uma determinada receita %
Ingrediente_Receita (CodReceita, CodIngrediente, Quantidade) - (CodReceita,CodIngrediente) é chave primária
CodReceita referencia Receita (CodReceita)
CodIngrediente referencia Ingrediente (CodIngrediente)

Usando essa base de dados, faça a fragmentação horizontal usando os algoritmos de fragmentação horizontal primária e derivada apresentados hoje em aula. Mostre todos os passos do projeto. Considere as consultas a seguir como consultas frequentes nessa base de dados. Não usar mais tabelas que o estritamente necessário!
*/


-- PRIMEIRO PASSO:     TRANSFORMAR EM CÓDIGO
-- 1-  Uma consulta que retorna os códigos das receitas que foram postadas por pessoas com menos de 14 anos.
SELECT Receita.CodReceita FROM Receita 
INNER JOIN Pessoa ON Receita.CodPessoa = Pessoa.CodPessoa 
WHERE Pessoa.idade < 14;
-- 2- Uma consulta que retorna os códigos das receitas que foram postadas por pessoas com mais de 18 anos.
SELECT Receita.CodReceita FROM Receita 
INNER JOIN Pessoa ON Receita.CodPessoa = Pessoa.CodPessoa 
WHERE Pessoa.idade > 18;
-- 3- Um consulta que retorna os nomes das pessoas que residem no Rio de Janeiro (UF = "RJ")
SELECT Nome FROM Pessoa 
WHERE UF = "RJ";
-- 4- Um consulta que retorna os nomes das pessoas que residem em São Paulo (UF = "SP")
SELECT Nome FROM Pessoa 
WHERE UF = "SP";


-- SEGUNDO PASSO:      VERIFICAR POSSIBILIDADE DE FRAGMENTAÇÃO
p1: idade < 14
p2: idade > 18
p3: UF = "RJ"
p4: UF = "SP"


-- TERCEIRO PASSO:     MINTERMOS
O conjunto Pr’ = {p1, p2, p3, p4} é completo e mínimo
– Com base em Pr’, os quatro predicados minterm a seguir podem ser definidos
2n combinações = 24 = 16 mintermos!
1.      p1      ^            p2         ^        p3         ^        p4
2.      p1      ^            p2         ^        p3         ^    ¬   p4
3.      p1      ^            p2         ^    ¬   p3         ^        p4
4.      p1      ^            p2         ^    ¬   p3         ^    ¬   p4
5.      p1      ^    ¬       p2         ^        p3         ^        p4
6.      p1      ^    ¬       p2         ^        p3         ^    ¬   p4
7.      p1      ^    ¬       p2         ^    ¬   p3         ^        p4
8.      p1      ^    ¬       p2         ^    ¬   p3         ^    ¬   p4
9.  ¬   p1      ^            p2         ^        p3         ^        p4
10. ¬   p1      ^            p2         ^        p3         ^    ¬   p4
11. ¬   p1      ^            p2         ^    ¬   p3         ^        p4
12. ¬   p1      ^            p2         ^    ¬   p3         ^    ¬   p4
13. ¬   p1      ^    ¬       p2         ^        p3         ^        p4
14. ¬   p1      ^    ¬       p2         ^        p3         ^    ¬   p4
15. ¬   p1      ^    ¬       p2         ^    ¬   p3         ^        p4
16. ¬   p1      ^    ¬       p2         ^    ¬   p3         ^    ¬   p4

1.      (idade < 14)      ^            (idade > 18)         ^        (UF = "RJ")         ^        (UF = "SP")
2.      (idade < 14)      ^            (idade > 18)         ^        (UF = "RJ")         ^    ¬   (UF = "SP")
3.      (idade < 14)      ^            (idade > 18)         ^    ¬   (UF = "RJ")         ^        (UF = "SP")
4.      (idade < 14)      ^            (idade > 18)         ^    ¬   (UF = "RJ")         ^    ¬   (UF = "SP")
5.      (idade < 14)      ^    ¬       (idade > 18)         ^        (UF = "RJ")         ^        (UF = "SP")
6.      (idade < 14)      ^    ¬       (idade > 18)         ^        (UF = "RJ")         ^    ¬   (UF = "SP")
7.      (idade < 14)      ^    ¬       (idade > 18)         ^    ¬   (UF = "RJ")         ^        (UF = "SP")
8.      (idade < 14)      ^    ¬       (idade > 18)         ^    ¬   (UF = "RJ")         ^    ¬   (UF = "SP")
9.  ¬   (idade < 14)      ^            (idade > 18)         ^        (UF = "RJ")         ^        (UF = "SP")
10. ¬   (idade < 14)      ^            (idade > 18)         ^        (UF = "RJ")         ^    ¬   (UF = "SP")
11. ¬   (idade < 14)      ^            (idade > 18)         ^    ¬   (UF = "RJ")         ^        (UF = "SP")
12. ¬   (idade < 14)      ^            (idade > 18)         ^    ¬   (UF = "RJ")         ^    ¬   (UF = "SP")
13. ¬   (idade < 14)      ^    ¬       (idade > 18)         ^        (UF = "RJ")         ^        (UF = "SP")
14. ¬   (idade < 14)      ^    ¬       (idade > 18)         ^        (UF = "RJ")         ^    ¬   (UF = "SP")
15. ¬   (idade < 14)      ^    ¬       (idade > 18)         ^    ¬   (UF = "RJ")         ^        (UF = "SP")
16. ¬   (idade < 14)      ^    ¬       (idade > 18)         ^    ¬   (UF = "RJ")         ^    ¬   (UF = "SP")

1.      (idade < 14)      ^            (idade > 18)         ^        (UF = "RJ")         ^        (UF = "SP")   -> Pessoas não podem ter menos de 14 e mais de 18 ao mesmo tempo e Não tem como alguem estar em dois lugares
2.      (idade < 14)      ^            (idade > 18)         ^        (UF = "RJ")         ^    ¬   (UF = "SP")   -> Pessoas não podem ter menos de 14 e mais de 18 ao mesmo tempo
3.      (idade < 14)      ^            (idade > 18)         ^    ¬   (UF = "RJ")         ^        (UF = "SP")   -> Pessoas não podem ter menos de 14 e mais de 18 ao mesmo tempo
4.      (idade < 14)      ^            (idade > 18)         ^    ¬   (UF = "RJ")         ^    ¬   (UF = "SP")   -> Pessoas não podem ter menos de 14 e mais de 18 ao mesmo tempo
5.      (idade < 14)      ^    ¬       (idade > 18)         ^        (UF = "RJ")         ^        (UF = "SP")   -> Pessoas não podem ter menos de 14 e mais de 18 ao mesmo tempo
6.      (idade < 14)      ^    ¬       (idade > 18)         ^        (UF = "RJ")         ^    ¬   (UF = "SP")
7.      (idade < 14)      ^    ¬       (idade > 18)         ^    ¬   (UF = "RJ")         ^        (UF = "SP")
8.      (idade < 14)      ^    ¬       (idade > 18)         ^    ¬   (UF = "RJ")         ^    ¬   (UF = "SP")   -> Não tem como alguem estar em lugar algum
9.  ¬   (idade < 14)      ^            (idade > 18)         ^        (UF = "RJ")         ^        (UF = "SP")   -> Não tem como alguem estar em dois lugares
10. ¬   (idade < 14)      ^            (idade > 18)         ^        (UF = "RJ")         ^    ¬   (UF = "SP")
11. ¬   (idade < 14)      ^            (idade > 18)         ^    ¬   (UF = "RJ")         ^        (UF = "SP")
12. ¬   (idade < 14)      ^            (idade > 18)         ^    ¬   (UF = "RJ")         ^    ¬   (UF = "SP")   -> Não tem como alguem estar em lugar algum
13. ¬   (idade < 14)      ^    ¬       (idade > 18)         ^        (UF = "RJ")         ^        (UF = "SP")   -> Não tem como alguem estar em dois lugares
14. ¬   (idade < 14)      ^    ¬       (idade > 18)         ^        (UF = "RJ")         ^    ¬   (UF = "SP")   -> Pessoas não podem comprar fora desse espaço de idade
15. ¬   (idade < 14)      ^    ¬       (idade > 18)         ^    ¬   (UF = "RJ")         ^        (UF = "SP")   -> Pessoas não podem comprar fora desse espaço de idade
16. ¬   (idade < 14)      ^    ¬       (idade > 18)         ^    ¬   (UF = "RJ")         ^    ¬   (UF = "SP")   -> Não tem como alguem estar em lugar algum e pessoas não podem comprar fora desse espaço de idade

6.      (idade < 14)      ^    ¬       (idade > 18)         ^        (UF = "RJ")         ^    ¬   (UF = "SP")   -> Pessoas com idades diferentes e em locais diferentes
7.      (idade < 14)      ^    ¬       (idade > 18)         ^    ¬   (UF = "RJ")         ^        (UF = "SP")   -> Pessoas com idades diferentes e em locais diferentes
10. ¬   (idade < 14)      ^            (idade > 18)         ^        (UF = "RJ")         ^    ¬   (UF = "SP")   -> Pessoas com idades diferentes e em locais diferentes
11. ¬   (idade < 14)      ^            (idade > 18)         ^    ¬   (UF = "RJ")         ^        (UF = "SP")   -> Pessoas com idades diferentes e em locais diferentes


Mintermos:
1. idade < 14           ^       UF = "RJ"
2. idade < 14           ^       UF = "SP"
3. idade > 18           ^       UF = "RJ"
4. idade > 18           ^       UF = "SP"
Fragmentos:
1. R1: σ idade < 14     ^       UF = "RJ" (Pessoa)
2. R2: σ idade < 14     ^       UF = "SP" (Pessoa)
3. R3: σ idade > 18     ^       UF = "RJ" (Pessoa)
4. R4: σ idade > 18     ^       UF = "SP" (Pessoa)
