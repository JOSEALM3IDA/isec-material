-- F1 EX1
select * from autores;
EXEC LEIBD2020.SQLCHECK(1,1);


-- F1 EX2
select titulo from livros;
EXEC LEIBD2020.SQLCHECK(2,1);


-- F1 EX3
select distinct genero from livros;
EXEC LEIBD2020.SQLCHECK(3,1);


-- F1 EX4
select titulo from livros where preco_tabela between 25 and 35;
EXEC LEIBD2020.SQLCHECK(4,1);


-----------------------------------------------------------------


-- F2 EX1
select codigo_livro, titulo
from livros
where genero = 'Informática';


-- F2 EX2
select titulo
from livros
where genero = 'Policial' and paginas > 500;


-- F2 EX3
select distinct genero
from livros
where paginas > 700 or preco_tabela > 45;


-- F2 EX4
select titulo
from livros
where genero = 'Informática'
order by preco_tabela desc;


-- F2 EX5
select isbn, titulo, preco_tabela, quant_em_stock
from livros
where genero = 'Informática'
order by preco_tabela desc, quant_em_stock asc;


-- F2 EX6
select distinct codigo_autor
from livros;


-- F2 EX7
select titulo
from livros
where genero != 'Policial';


-- F2 EX8
select titulo
from livros
where not genero = 'Policial';


-- F2 EX9
select nome
from autores
where idade > 30 and genero_preferido = 'Policial'
order by nome;


-- F2 EX10
select nome
from autores
where nome like '%r%' and nome like '%d%';


-- F2 EX11
select titulo
from livros
where titulo like 'O%st%' and titulo like 'M%to%';


-- F2 EX12
select titulo
from livros
--where genero = 'Policial' or genero = 'Romance' or genero = 'Aventura';
where genero in ('Policial','Romance','Aventura');


-- F2 EX13
select 'O livro "' || titulo || '" custa ' || preco_tabela || ' euros.' as "Listagem de Livros"
from livros;


-----------------------------------------------------------------


-- F3 EX1
select titulo
from livros, autores
where livros.codigo_autor = autores.codigo_autor
and genero = 'Policial'
and nome = 'Cláudio Tereso';


-- F3 EX2
select titulo
from livros, autores
where livros.codigo_autor = autores.codigo_autor
and genero = 'Policial'
and morada like '%Coimbra%';


-- F3 EX3
select distinct nome
from livros, autores
where livros.codigo_autor = autores.codigo_autor
and genero = genero_preferido;


-- F3 EX4
select titulo, preco_tabela
from livros, vendas, clientes
where vendas.codigo_cliente = clientes.codigo_cliente
and vendas.codigo_livro = livros.codigo_livro
and morada like '%Coimbra%';


-- F3 EX5
select distinct autores.nome
from livros, vendas, autores, clientes
where vendas.codigo_livro = livros.codigo_livro
and vendas.codigo_cliente = clientes.codigo_cliente
and clientes.n_contribuinte = autores.n_contribuinte;


-- F3 EX6
select nome, titulo, genero
from livros, autores
where livros.codigo_autor = autores.codigo_autor
and not genero = genero_preferido
order by nome;


-- F3 EX7
select titulo, preco_tabela * unidades_vendidas * 0.3 as "Rendeu"
from livros;


-- F3 EX8
select titulo, preco_tabela * unidades_vendidas * 0.3 as "Rendimento"
from livros
where preco_tabela * unidades_vendidas * 0.3 > 10000
order by genero, preco_tabela;


-- F3 EX9
select titulo, ROUND(preco_tabela/paginas, 2) as "Custo página", CEIL(preco_tabela/paginas) as "Custo pág.(sup)", FLOOR(preco_tabela/paginas) as "Custo pág.(inf)"
from livros
where paginas between 400 and 700
order by ROUND(preco_tabela/paginas, 2);

-- F3 EX10
select UPPER(titulo) as "Titulo (em maiúsculas)", LOWER(titulo) as "Titulo (em minúsculas)", INITCAP(titulo) as "Titulo (1ª letra maiúscula)"
from livros;


-- F3 EX11
select titulo as "Titulo"
from livros
where UPPER(genero) = 'INFORMÁTICA';


-- F3 EX12
select nome as "Nome completo", substr(nome, 1, instr(nome, ' ') - 1) as "Primeiro Nome", substr(nome, instr(nome, ' ', -1) + 1) as "Ultimo Nome"
from autores;


-- F3 EX13
select UPPER(titulo) as "Titulo (em maisculas)", LOWER(genero) as "genero (min.)", INITCAP(autores.nome) as "Nome Autor (1a letra)"
from livros, autores, editoras
where livros.codigo_autor = autores.codigo_autor
and livros.codigo_editora = editoras.codigo_editora
and UPPER(editoras.nome) = 'FCA - EDITORA'
order by autores.nome;


-- F3 EX14
select titulo
from livros
where length(titulo) > 20;


-- F3 EX15
select titulo, preco_tabela as "PRECO", ROUND(preco_tabela * 1.1355, 1) as "PRECO_COM_AUMENTO"
from livros
where genero = 'Policial';


-----------------------------------------------------------------


-- F4 EX1
select titulo
from livros
where to_char(data_edicao, 'DD-MM-YYYY') like '%2011';


--F4 EX2
select to_char(sysdate,'HH:MI:SS AM') as "Hora Actual", to_char(sysdate,'DD, Month, YYYY') as "Data Actual"
from dual;


--F4 EX3
select titulo as "Titulo", preco_tabela as "Preço"
from livros
where sysdate - data_edicao < 3000;


--F4 EX4
select distinct titulo
from livros, vendas, clientes
where livros.codigo_livro = vendas.codigo_livro
and vendas.codigo_cliente = clientes.codigo_cliente
and upper(morada) like '%LISBOA%'
and to_char(data_venda, 'DD-MM-YYYY') LIKE '%02-2014'
order by titulo;


--F4 EX5
select titulo
from livros, vendas
where livros.codigo_livro = vendas.codigo_livro
and upper(genero) = 'INFORMÁTICA'
and to_char(data_edicao, 'MM-YYYY') = to_char(data_venda, 'MM-YYYY')
order by titulo;


--F4 EX6
select nome
from autores, livros
where autores.codigo_autor = livros.codigo_autor
and upper(genero) = 'INFORMÁTICA'
and paginas > 190
and data_edicao between to_date('21-06-2013','DD-MM-YYYY') and to_date('22-09-2013','DD-MM-YYYY');


--F4 EX7
select titulo as "Titulo", to_char(data_edicao, 'YYYY-MM-DD HH24:MI:SS') as "DATA_EDICAO", trunc(months_between(sysdate,data_edicao)/12) as "Num. de anos"
from livros
where upper(genero) = 'INFORMÁTICA'
order by titulo;


--F4 EX8
select nome
from clientes, vendas, livros
where clientes.codigo_cliente = vendas.codigo_cliente
and vendas.codigo_livro = livros.codigo_livro
and upper(genero) = 'INFORMÁTICA'
and to_char(data_venda, 'HH24') < 17
and to_char(data_venda, 'D') = 3
and to_char(data_venda, 'DD') <= 7;


--F4 EX9
select nome from autores
minus select nome from autores, livros
where autores.codigo_autor = livros.codigo_autor;


--F4 EX10
select nome from autores
minus select nome from autores, livros
where autores.codigo_autor = livros.codigo_autor
or to_char(data_edicao, 'YYYY') = to_char(sysdate, 'YYYY');


-----------------------------------------------------------------


-- F5 EX 1
select count(CODIGO_LIVRO) as "Total livros de Informática"
from livros
where upper(genero) = 'INFORMÁTICA';


-- F5 EX2
select count(codigo_livro) as "Total de Livros", avg(preco_tabela) as "Preço Médio", sum(unidades_vendidas) as "Total de livros vendidos"
from livros;


-- F5 EX3
select genero, count(codigo_livro) as "QUANTIDADE"
from livros
group by genero
order by genero;


-- F5 EX4
select titulo, min(preco_unitario) as "P_MAIS_BAIXO", max(preco_unitario) as "P_MAIS_ALTO", round(avg(preco_unitario), 2) as "P_MEDIO"
from livros, vendas
where livros.codigo_livro = vendas.codigo_livro
and upper(genero) = 'INFORMÁTICA'
group by titulo
order by titulo;


-- F5 EX5
select genero, max(preco_tabela) - min(preco_tabela) as "DIFERENCA"
from livros
group by genero
order by genero;


-- F5 EX6
select titulo, preco_tabela as "PRECO", sum(quantidade) as "NUM_VENDIDOS", sum(preco_tabela * quantidade) as "REC_ESPERADA", sum(preco_unitario * quantidade) as "REC_EFECTIVA"
from livros, vendas
where livros.codigo_livro = vendas.codigo_livro
group by titulo, preco_tabela
order by titulo;


-- F5 EX7
select genero, ceil(avg(preco_tabela)) as "Preço Médio"
from livros
group by genero
having count(codigo_livro) > 4;


-- F5 EX8
select nome, min(preco_tabela) as "Preco Minimo"
from autores, livros
where autores.codigo_autor = livros.codigo_autor
group by nome
having min(preco_tabela) > 30
order by min(preco_tabela);


-- F5 EX9
select cl.codigo_cliente, cl.nome, sum(quantidade) as "N.Livros", round(avg(preco_unitario), 2) as "Preco Medio", count(distinct codigo_autor) as "N. Autores Diferentes"
from clientes cl, vendas v, livros l
where cl.codigo_cliente = v.codigo_cliente
and v.codigo_livro = l.codigo_livro
and upper(morada) like '%LISBOA%'
group by cl.codigo_cliente, cl.nome
having not count(distinct codigo_editora) > 1
and sum(quantidade) > 3
order by cl.nome;


-- F5 EX10 - Solucao 1 - Union
select nome , ''||count(livros.codigo_livro) as "Num. Livros"
from autores, livros
where autores.codigo_autor = livros.codigo_autor
group by nome
union
select nome, 'Nenhum'
from autores
minus
select nome, 'Nenhum'
from autores, livros
where autores.codigo_autor = livros.codigo_autor
order by nome;

-- F5 EX10 - Solucao 2 - Outer join (right join)
select nome , replace(count(livros.codigo_livro), 0, 'Nenhum') as "Num. Livros"
from autores, livros
where autores.codigo_autor = livros.codigo_autor (+) -- Quer o autor tenha livro ou nao
group by nome
order by nome;


-----------------------------------------------------------------


-- F6 EX1
select titulo, preco_tabela
from livros
where upper(genero) like '%INFORMÁTICA%'
and preco_tabela = (
        select max(preco_tabela) from livros
        where upper(genero) like '%INFORMÁTICA%'
        );


-- F6 EX2
select titulo, preco_tabela
from livros
where upper(genero) like '%INFORMÁTICA%'
and preco_tabela = ALL (
        select max(preco_tabela) from livros
        where upper(genero) like '%INFORMÁTICA%'
        );       


-- F6 EX3
select titulo, preco_tabela
from livros l1
where upper(genero) like '%INFORMÁTICA%'
and not exists (
        select * from livros l2
        where l1.preco_tabela < l2.preco_tabela
        and upper(genero) like '%INFORMÁTICA%'
        );       


-- F6 EX4
select l1.titulo, l1.preco_tabela
from livros l1, (select max(preco_tabela) as preco_tabela from livros
                 where upper(genero) like '%INFORMÁTICA%') l2
where l1.preco_tabela = l2.preco_tabela;


-- F6 EX5
-- primeiro resolver: quais os autores com numero de paginas maior que x?
select distinct a.nome
from autores a, livros l
where l.codigo_autor = a.codigo_autor
and paginas > x;
-- segundo resolver: qual o numero medio de paginas por livro?
select avg(paginas) from livros;
-- depois juntar
select distinct a.nome
from autores a, livros l
where l.codigo_autor = a.codigo_autor
and paginas > (select avg(paginas) from livros)
order by 1;


-- F6 EX6
select a1.nome
from autores a1, livros l1
where l1.codigo_autor = a1.codigo_autor
group by a1.nome
having count(l1.titulo) > (select avg(x.nLivros) media from (
                                (select a2.nome, count(l2.codigo_autor) nLivros
                                 from autores a2, livros l2
                                 where l2.codigo_autor = a2.codigo_autor
                                 group by a2.nome) x));


-----------------------------------------------------------------


-- F8 EX1
select titulo, preco_tabela as preco, b.preco_medio, preco_tabela - preco_medio as diferença
from livros, (select codigo_autor as ca, round(avg(preco_tabela), 2) as preco_medio 
              from livros
              where upper(genero) like '%INFORMÁTICA%'
              group by codigo_autor) b            
where upper(genero) like '%INFORMÁTICA%'
and codigo_autor = b.ca
order by 1;


-- F8 EX2
select genero, titulo, unidades_vendidas
from livros, (select genero as g, max(unidades_vendidas) as max_u
              from livros
              group by genero) b
where unidades_vendidas = max_u
and genero = b.g
order by genero;


-- F8 EX3
select titulo, to_char(round(unidades_vendidas / s.sum_uv * 100, 1), '990.99') as percent
from livros, editoras, (select sum(unidades_vendidas) as sum_uv 
                        from livros, editoras
                        where livros.codigo_editora = editoras.codigo_editora
                        and nome like '%FCA%') s
where livros.codigo_editora = editoras.codigo_editora
and upper(nome) like '%FCA%'
order by 2 desc, 1;


-- F8 EX4
select titulo
from livros, vendas, clientes
where livros.codigo_livro = vendas.codigo_livro
and vendas.codigo_cliente = clientes.codigo_cliente
and upper(morada) like '%LISBOA'
group by titulo
having sum(quantidade) = (select max(sum(quantidade))
                          from livros, vendas, clientes
                          where livros.codigo_livro = vendas.codigo_livro
                          and vendas.codigo_cliente = clientes.codigo_cliente
                          and upper(morada) like '%LISBOA'
                          group by livros.codigo_livro);


-- F8 EX5
select aa.tl as "Total de Livros", ab.ta as "Total de Autores", ac.te as "Total de Editoras"
from (select count(codigo_livro) as tl from livros) aa,
     (select count(codigo_autor) as ta from autores) ab,
     (select count(codigo_editora) as te from editoras) ac;


-- F8 EX6
select 'O autor ' || aut.nome || ' escreveu ' || count(livros.codigo_livro) || ' e ' || b.num_edit || ' sob a alçada da editora FCA - EDITORA' as "Resultado"
from autores aut, livros, (select codigo_autor, count(codigo_livro) as num_edit
						   from livros l, editoras e
                           where l.codigo_editora = e.codigo_editora
                           and e.nome like '%FCA%'
                           group by codigo_autor) b
where aut.codigo_autor = b.codigo_autor
and aut.codigo_autor = livros.codigo_autor
group by aut.nome, b.num_edit
order by aut.nome;


-----------------------------------------------------------------


-- F9 EX1
select aut.nome, liv.titulo, cl.mpl as "LIVROS FCA", count(liv.codigo_livro) as "Total de Livros"
from autores aut, editoras edi, livros liv, (select codigo_autor as mplca, count(codigo_livro) as mpl
                                             from livros, editoras
                                             where livros.codigo_editora = editoras.codigo_editora
                                             and livros.preco_tabela = (select max(preco_tabela) 
                                                                        from livros, editoras
                                                                        where livros.codigo_editora = editoras.codigo_editora
                                                                        and upper(editoras.nome) like '%FCA%')
                                             and upper(editoras.nome) like '%FCA%'
                                             group by codigo_autor) cl
where aut.codigo_autor = liv.codigo_autor
and liv.codigo_editora = edi.codigo_editora
and liv.codigo_autor = cl.mplca
and upper(edi.nome) like '%FCA%'
group by aut.nome, liv.titulo, cl.mpl;


-- F9 EX2
select aut.nome, NVL(ct.ctl, 0) as "Genero Preferido", count(l.codigo_livro) as "Total de Livros"
from livros l, autores aut, (select aut.codigo_autor as ca, count(codigo_livro) as ctl
                             from livros l, autores aut
                             where l.codigo_autor = aut.codigo_autor (+)
                             and upper(l.genero) = upper(aut.genero_preferido)
                             group by aut.codigo_autor) ct
where l.codigo_autor (+) = aut.codigo_autor
and aut.codigo_autor = ct.ca (+)
group by aut.nome, ct.ctl
order by 1;


-- F9 EX3
select 'O autor ' || aut.nome || ' escreveu ' || b.num_edit || ' de ' || count(livros.codigo_livro) || ' livros para a editora ' || b.ned || '.' as Resultado
from autores aut, livros,
                  (select codigo_autor as ca, e.nome as ned, count(codigo_livro) as num_edit
                   from livros l, editoras e, (select editoras.codigo_editora as ce, max(unidades_vendidas)
                                               from editoras, vendas, livros
                                               where editoras.codigo_editora = livros.codigo_editora
                                               and vendas.codigo_livro = livros.codigo_livro
                                               group by editoras.codigo_editora) d
                   where l.codigo_editora = e.codigo_editora
                   and e.codigo_editora = d.ce
                   group by codigo_autor, e.nome) b
where aut.codigo_autor = b.ca
and aut.codigo_autor = livros.codigo_autor
group by aut.nome, b.num_edit, b.ned
order by aut.nome;


-- F9 EX4                    
select distinct cl.nome
from clientes cl, vendas v, (select codigo_livro as cliv
                             from livros
                             where preco_tabela = (select min(preco_tabela)
                                                   from livros
                                                   where upper(genero) like '%INFORMÁTICA%')) b
where cl.codigo_cliente = v.codigo_cliente
and v.codigo_livro = b.cliv;


-----------------------------------------------------------------


-- F10 EX1
CREATE TABLE autores2 (
  CODIGO_AUTOR	  NUMBER(4,0) CONSTRAINT pk_autores2 PRIMARY KEY,
  NOME	  VARCHAR2(30 BYTE) CONSTRAINT ck_nome_notnull NOT NULL CONSTRAINT ck_nome_maiuscula CHECK(nome = upper(nome)),
  N_CONTRIBUINTE	  NUMBER(9,0) CONSTRAINT nn_nif NOT NULL CONSTRAINT uk_nif UNIQUE,
  MORADA	  VARCHAR2(50 BYTE),
  IDADE 	NUMBER(4,0) CONSTRAINT ck_idade_menor_200 CHECK(idade BETWEEN 0 and 200),
  SEXO	  CHAR(1 BYTE) CONSTRAINT ck_sexo_m_f CHECK(sexo in ('F', 'M')),
  NACIONALIDADE	  VARCHAR2(20 BYTE),
  GENERO_PREFERIDO	  VARCHAR2(20 BYTE)
);


-- F10 EX2
CREATE TABLE avaliacoes (
  CODIGO_LIVRO    NUMBER(4,0) CONSTRAINT fk_codigo_livro REFERENCES LIVROS(CODIGO_LIVRO),
  CODIGO_CLIENTE    NUMBER(4,0) CONSTRAINT fk_codigo_cliente REFERENCES CLIENTES(CODIGO_CLIENTE),
  NOTA    NUMBER(1) CONSTRAINT ck_nota_1a3 CHECK(nota between 1 and 5),
  CONSTRAINT pk_avaliacoes PRIMARY KEY(CODIGO_LIVRO, CODIGO_CLIENTE)
);


-- F10 EX3
DROP TABLE livros_backup;
CREATE TABLE livros_backup AS (
  SELECT CODIGO_LIVRO,
         CODIGO_EDITORA,
         CODIGO_AUTOR,
         TITULO,
         ISBN,
         upper(GENERO) as GENERO,
         PRECO_TABELA,
         PAGINAS,
         QUANT_EM_STOCK,
         UNIDADES_VENDIDAS,
         DATA_EDICAO
  FROM LIVROS 
);


-- F10 EX4
ALTER TABLE LIVROS_BACKUP ADD (
  CONSTRAINT PK_LIVROS_BK PRIMARY KEY(CODIGO_LIVRO),
  CONSTRAINT FK_LIVROS_BK_COD_ED_EDITORAS FOREIGN KEY(CODIGO_EDITORA) REFERENCES EDITORAS(CODIGO_EDITORA),
  CONSTRAINT FK_LIVROS_BK_COD_AU_AUTORES FOREIGN KEY(CODIGO_AUTOR) REFERENCES AUTORES(CODIGO_AUTOR)
);


-- F10 EX5
INSERT INTO LIVROS_BACKUP VALUES (
  51,
  (SELECT CODIGO_EDITORA FROM EDITORAS WHERE UPPER(NOME) = 'FCA - EDITORA'),
  (SELECT CODIGO_AUTOR FROM AUTORES WHERE INITCAP(NOME) = 'Sérgio Sousa'),
  'Informática para todos', 132424, 'Informática', 24, 430, NULL, 0, SYSDATE
);


-- F10 EX6
INSERT INTO autores2 (CODIGO_AUTOR, NOME, N_CONTRIBUINTE)
  values (45, 'JOSÉ MAGALHÃES', 77665544);


-- F10 EX7
DELETE FROM livros_backup WHERE CODIGO_LIVRO = 51;
  

-- F10 EX8
UPDATE livros_backup 
SET PRECO_TABELA = PRECO_TABELA * 1.1 --, se quiser mais alterações separo por virgula
WHERE GENERO = 'AVENTURA';


-- F10 EX9
DELETE FROM LIVROS_BACKUP WHERE PRECO_TABELA < (SELECT AVG(PRECO_TABELA) FROM LIVROS_BACKUP WHERE GENERO = 'INFORMÁTICA');


-- F10 EX10
DROP TABLE AUTORES_BACKUP;
CREATE TABLE AUTORES_BACKUP AS (SELECT * FROM AUTORES);


-- F10 EX11
ALTER TABLE AUTORES_BACKUP ADD (NLIVROS   NUMBER(3,0) DEFAULT 0 CONSTRAINT CK_NLIVROS_0_150 CHECK(NLIVROS BETWEEN 0 AND 150));


-- F10 EX12
UPDATE AUTORES_BACKUP AB
SET NLIVROS = NVL((SELECT COUNT(CODIGO_LIVRO) CNT
                   FROM LIVROS
                   WHERE CODIGO_AUTOR = AB.CODIGO_AUTOR
                   GROUP BY CODIGO_AUTOR), 0);


-- F10 EX13
UPDATE AUTORES_BACKUP AB SET GENERO_PREFERIDO = (SELECT L.GENERO -- Ir aos livros agrupados por autor e genero. Contar os livros. Manter apenas as linhas onde o numero de livros nesse grupo é igual ao maximo de livros
                                                 FROM LIVROS L
                                                 WHERE L.CODIGO_AUTOR = AB.CODIGO_AUTOR
                                                 AND ROWNUM = 1 -- Manter apenas uma linha de output (quando o autor escrever igual quantidade máxima de dois ou mais generos)
                                                 GROUP BY L.CODIGO_AUTOR, L.GENERO
                                                 HAVING COUNT(L.CODIGO_LIVRO) = (SELECT MAX(COUNT(LL.CODIGO_LIVRO)) -- Escolher o numero maximo de livros dentro de cada genero de cada autor
                                                                                 FROM LIVROS LL
                                                                                 WHERE L.CODIGO_AUTOR = LL.CODIGO_AUTOR -- restringindo ao autor atual
                                                                                 GROUP BY LL.CODIGO_AUTOR, LL.GENERO));


-- F10 EX14
CREATE TABLE EDITORAS_BACKUP AS (SELECT * FROM EDITORAS);


-- F10 EX15
DROP TABLE EDITORAS_BACKUP;


-- F10 EX16
ALTER TABLE LIVROS_BACKUP ADD (EDICAO   NUMBER(7));


-- F10 EX17
UPDATE LIVROS_BACKUP LB SET UNIDADES_VENDIDAS = NVL((SELECT SUM(V.QUANTIDADE)
                                                     FROM VENDAS V
                                                     WHERE V.CODIGO_LIVRO = LB.CODIGO_LIVRO),0);


-- F10 EX18
UPDATE VENDAS_BACKUP VB SET TOTAL_VENDA = (SELECT V.QUANTIDADE * V.PRECO_UNITARIO
                                           FROM VENDAS V
                                           WHERE VB.CODIGO_VENDA = V.CODIGO_VENDA);
										   

-- F10 EX19
CREATE TABLE VENDAS_BACKUP AS (SELECT * FROM VENDAS);


-- F10 EX20
DELETE FROM VENDAS_BACKUP VB WHERE TO_CHAR(DATA_VENDA, 'DD-MON-YYYY') LIKE '%-JAN-%';


-- F10 EX21
DELETE FROM VENDAS_BACKUP WHERE CODIGO_LIVRO = (SELECT CODIGO_LIVRO
                                                FROM LIVROS, (SELECT AUTORES.CODIGO_AUTOR CA, MAX(PRECO_TABELA) MPT
                                                              FROM LIVROS, AUTORES
                                                              WHERE LIVROS.CODIGO_AUTOR = AUTORES.CODIGO_AUTOR
                                                              AND NOME = 'Sérgio Sousa'
                                                              GROUP BY AUTORES.CODIGO_AUTOR) MC
                                                WHERE CODIGO_AUTOR = MC.CA
                                                AND PRECO_TABELA = MC.MPT);


-----------------------------------------------------------------


-- F11 EX1
create sequence exp_sequencia; -- Cria sequencia exp_sequencia que começa a 1 e incrementa por 1

select exp_sequencia.currval from dual; -- Erro, pois a sequencia nao foi inicializada

select exp_sequencia.nextval from dual; -- Inicializa a sequencia e devolve o valor atual (1)

select exp_sequencia.nextval from dual;  -- Incrementa a sequencia e devolve o valor atual (2)

select exp_sequencia.nextval from dual;  -- Incrementa a sequencia e devolve o valor atual (3)

select exp_sequencia.currval from dual; -- Devolve o valor atual da sequencia

drop sequence exp_sequencia; -- Destroi a sequencia exp_sequencia


-- F11 EX2
DROP TABLE EDITORAS_BACKUP;
CREATE TABLE EDITORAS_BACKUP AS (SELECT * FROM EDITORAS);
ALTER TABLE EDITORAS_BACKUP ADD (
  CONSTRAINT PK_ID_EDITORA_BK PRIMARY KEY (CODIGO_EDITORA),
  CONSTRAINT UK_N_CONTRIB_BK UNIQUE (N_CONTRIBUINTE));
  

-- F11 EX3
CREATE SEQUENCE SEQ_EDITBACK
  START WITH 4
  INCREMENT BY 1
  NOCYCLE
  NOMAXVALUE;


-- F11 EX4
ALTER TABLE EDITORAS_BACKUP MODIFY (MORADA VARCHAR(60));
INSERT INTO EDITORAS_BACKUP VALUES (seq_editback.nextval, 'D.Quixote', 901111111, 'Rua Cidade de Córdova, n.2 2610-038 Alfragide', 707252252, 707252253);
INSERT INTO EDITORAS_BACKUP VALUES (seq_editback.nextval, 'Almedina', 901212121, 'Rua Fernandes Tomás, n.º 76 a 80, 3000-167 Coimbra', 239851903, 239851904);


-- F11 EX5
select seq_editback.currval from dual;
select seq_editback.nextval from dual;
select seq_editback.currval from dual;


-- F11 EX6
DROP SEQUENCE seq_editback;


-- F11 EX7
CREATE VIEW LIVROS_INFORMATICA AS
SELECT * FROM LIVROS
WHERE upper(genero) = 'INFORMÁTICA';


-- F11 EX8
insert into livros_informatica (codigo_livro, titulo,isbn, genero) values (30,'Uma noite de Verão', 8000000001,'Informática');
insert into livros_informatica (codigo_livro, titulo,isbn, genero) values (31,'O céu é azul',8000000002,'Romance');
insert into livros (codigo_livro, codigo_editora, codigo_autor,titulo,isbn, genero) values (32,2, 2,'Longe de tudo',8000000003,'Informática');


-- F11 EX9
DELETE FROM LIVROS
WHERE CODIGO_LIVRO IN (30, 31, 32);


-- F11 EX10
DROP VIEW LIVROS_INFORMATICA;


-- F11 EX11
DROP TABLE LIVROS_BACKUP;
CREATE TABLE LIVROS_BACKUP AS (SELECT * FROM LIVROS);


-- F11 EX12
DROP VIEW AUTOR_LIVRO;
CREATE VIEW AUTOR_LIVRO AS
SELECT AU.NOME, L.TITULO
FROM AUTORES AU, LIVROS_BACKUP L
WHERE AU.CODIGO_AUTOR = L.CODIGO_AUTOR;


-- F11 EX13
SELECT * FROM AUTOR_LIVRO;
DELETE LIVROS_BACKUP;
SELECT * FROM AUTOR_LIVRO; -- Não é possível vizualizar nada, pois a vista não guarda informação e apagamos os registos na tabela original


-- F11 EX14
DROP TABLE LIVROS_BACKUP;
SELECT * FROM AUTOR_LIVRO; -- ERRO, pois a View está a tentar aceder a uma tabela que não existe


-- F11 EX15
DROP VIEW LIVROS_VENDIDOS;
CREATE VIEW LIVROS_VENDIDOS AS
SELECT L.TITULO, AU.NOME, SUM(V.QUANTIDADE) AS QUANT_VEND
FROM LIVROS L, VENDAS V, AUTORES AU
WHERE L.CODIGO_LIVRO = V.CODIGO_LIVRO
AND L.CODIGO_AUTOR = AU.CODIGO_AUTOR
GROUP BY V.CODIGO_LIVRO, L.TITULO, AU.NOME
ORDER BY 3 DESC;


-- F11 EX16
SELECT * FROM USER_TABLES;


-- F11 EX17
SELECT * FROM USER_CONSTRAINTS;