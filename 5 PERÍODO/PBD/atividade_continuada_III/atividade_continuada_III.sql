/*
Questão 1. Considere a execução de uma consulta envolvendo uma seleção em um atributo que possui um índice. É sempre mais eficiente usar
o índice do atributo no processamento? Se a tabela possuir índices desnecessários, isso pode atrapalhar o processamento da consulta? Justifique sua resposta.


Questão 2. Considere as seguintes tabelas e consulta: 
Aluno(mat, nome, id_dept) - mat é PK e id_dept FK para Departamento
Departamento(id_dept, nome_dept) id_dept é PK
SELECT mat, nome, nome_dept
FROM Aluno, Departamento
WHERE Aluno.id_dept = Departamento.id_dept;


a. Apresente a parse-tree dessa consulta. 
b. Apresente a árvore modificada após a etapa de reescrita da consulta.
c. Escreva o pseudo-código para um plano de execução físico para o processamento
do join na consulta acima.


Considere as seguintes tabelas: 
R(A,B,C,D) 
S(E,F,G,H) - E é chave-estrangeira que referencia R(A) 


Desenhe uma árvore otimizada para a
consulta: SELECT A from R, S
WHERE A=5 AND G=7 AND E=A;
*/

1-
Não é sempre mais eficiente usar o índice do atributo no processamento. Isso porque caso a seleção seja muito pouco específica, acaba sendo mais vantajoso fazer uma varredura na tabela.
A tabela possuir índices desnecessários pode atrapalhar o processamento da consulta sim.
Então índices desnecessários podem causar:
- Lentidão para atualizar   (cada novo índice exigiria mais tempo para atualizar o banco caso ocorra uma alteração que afete seus índices);
- Espaço ocupado que prejudicará o cache dos dados ou índices;
- Custo desnecessário       (acessar primeiro o índice para depois acessar o dado pode ter um custo maior que acessar os dados diretamente em certos padrões);
- Dificulta upgrades no modelo de uma base de dados num sistema em produção;
- Manutenção mais custosa   (cada novo índice é um recurso a mais);


2-
a.
            πmat, nome, nome_dept
            |
           |x|Aluno.id_dept=Departamento.id_dept
        /                   \
       πDepartamento       πAluno
       |                    |
      (Departamento)       (Aluno)
b.
            πmat, nome, nome_dept
            |
           |x|Aluno.id_dept=Departamento.id_dept
        /                   \
       πnome_dept, id_dept   πmat, nome, id_dept
       |                      |
      (Departamento)         (Aluno)
c.
load all td from Departamento in memory
load all ta from Aluno in memory
for each td in Departamento (memory)
    for each ta in Aluno (memory)
    if match(ta, td)
    add-result(ta, td)


3-
            πA
            |
           |x|E=A
          /   \
         σA=5  σG=7
        /       \
       πA       πE,G
       |         |
      (R)       (S)
