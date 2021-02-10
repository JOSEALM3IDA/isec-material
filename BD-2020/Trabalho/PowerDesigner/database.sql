/*==============================================================*/
/* DBMS name:      ORACLE Version 11g                           */
/* Created on:     16-Jan-21 23:17:02                           */
/*==============================================================*/


alter table CONDUZ
   drop constraint FK_CONDUZ_REFERENCE_ESTAFETA;

alter table CONDUZ
   drop constraint FK_CONDUZ_REFERENCE_VEICULO;

alter table CONTEM
   drop constraint FK_CONTEM_ENCOMENDA_ENCOMEND;

alter table CONTEM
   drop constraint FK_CONTEM_REFERE_PR_PRODUTOS;

alter table ENCOMENDAS
   drop constraint FK_ENCOMEND_ENCONTRA__ESTADOS;

alter table ENCOMENDAS
   drop constraint FK_ENCOMEND_ENTREGUE__LOCAIS_D;

alter table ENCOMENDAS
   drop constraint FK_ENCOMEND_FEITA_POR_CLIENTE;

alter table ENCOMENDAS
   drop constraint FK_ENCOMEND_PAGA_USAN_METODOS;

alter table ENTREGA
   drop constraint FK_ENTREGA_ASSOCIA_ENCOMEND;

alter table ENTREGA
   drop constraint FK_ENTREGA_ENTREGUE__ESTAFETA;

alter table ESCOLHA
   drop constraint FK_ESCOLHA_REFERENCE_ENCOMEND;

alter table ESCOLHA
   drop constraint FK_ESCOLHA_REFERENCE_ESTAFETA;

alter table PAGAMENTO
   drop constraint FK_PAGAMENT_PAGAMENTO_ESTAFETA;

alter table PERTENCE_A
   drop constraint FK_PERTENCE_LOCAL_PER_LOCAIS_D;

alter table PERTENCE_A
   drop constraint FK_PERTENCE_REFERE_CL_CLIENTE;

alter table PRODUTOS
   drop constraint FK_PRODUTOS_TEM_DETER_MARCAS;

alter table PRODUTOS
   drop constraint FK_PRODUTOS_VENDE_LOJAS;

alter table VENDIDA_EM
   drop constraint FK_VENDIDA__VENDIDA_E_MARCAS;

alter table VENDIDA_EM
   drop constraint FK_VENDIDA__VENDIDA_E_LOJAS;

drop table CLIENTE cascade constraints;

drop table CONDUZ cascade constraints;

drop index REFERE_FK;

drop index TEM_FK;

drop table CONTEM cascade constraints;

drop index ENCONTRA_SE_FK;

drop index PAGA_USANDO_FK;

drop index FEITA_POR_FK;

drop index ENTREGUE_EM_FK;

drop table ENCOMENDAS cascade constraints;

drop index ENTREGUE_POR_FK;

drop table ENTREGA cascade constraints;

drop table ESCOLHA cascade constraints;

drop table ESTADOS cascade constraints;

drop table ESTAFETA cascade constraints;

drop table LOCAIS_DE_ENTREGA cascade constraints;

drop table LOJAS cascade constraints;

drop table MARCAS cascade constraints;

drop table METODOS_PAGAMENTO cascade constraints;

drop index PAGAMENTO_COMISSOES_FK;

drop table PAGAMENTO cascade constraints;

drop index PERTENCE_A2_FK;

drop index PERTENCE_A_FK;

drop table PERTENCE_A cascade constraints;

drop index VENDE_FK;

drop index TEM_DETERMINADA_FK;

drop table PRODUTOS cascade constraints;

drop table VEICULO cascade constraints;

drop index VENDIDA_EM2_FK;

drop index VENDIDA_EM_FK;

drop table VENDIDA_EM cascade constraints;

/*==============================================================*/
/* Table: CLIENTE                                               */
/*==============================================================*/
create table CLIENTE 
(
   ID_CLIENTE           NUMBER(8)            not null,
   NOME                 VARCHAR2(50)         not null,
   DATA_NASCIMENTO      DATE                 not null,
   TELEMOVEL            NUMBER(9),
   EMAIL                VARCHAR2(50),
   FOTO_URL             VARCHAR2(100),
   constraint PK_CLIENTE primary key (ID_CLIENTE)
);

/*==============================================================*/
/* Table: CONDUZ                                                */
/*==============================================================*/
create table CONDUZ 
(
   ID_ESTAFETA          NUMBER(8)            not null,
   MATRICULA            VARCHAR2(1024)       not null,
   constraint PK_CONDUZ primary key (ID_ESTAFETA, MATRICULA)
);

/*==============================================================*/
/* Table: CONTEM                                                */
/*==============================================================*/
create table CONTEM 
(
   ID_ENCOMENDA         NUMBER(8)            not null,
   ID_PRODUTO           NUMBER(8)            not null,
   QUANTIDADE           NUMBER(8)            not null,
   PRECO_ATUAL          NUMBER(8,2)          not null,
   constraint PK_CONTEM primary key (ID_ENCOMENDA, ID_PRODUTO)
);

/*==============================================================*/
/* Index: TEM_FK                                                */
/*==============================================================*/
create index TEM_FK on CONTEM (
   ID_ENCOMENDA ASC
);

/*==============================================================*/
/* Index: REFERE_FK                                             */
/*==============================================================*/
create index REFERE_FK on CONTEM (
   ID_PRODUTO ASC
);

/*==============================================================*/
/* Table: ENCOMENDAS                                            */
/*==============================================================*/
create table ENCOMENDAS 
(
   ID_ENCOMENDA         NUMBER(8)            not null,
   ID_LOCAL             NUMBER(8)            not null,
   ID_CLIENTE           NUMBER(8)            not null,
   ID_ESTADO            NUMBER(8)            not null,
   NOME_METODO          VARCHAR2(50)         not null,
   TAXA_ENTREGA         NUMBER(8,2)          not null,
   DATA_ENCOMENDA       DATE                 not null,
   NIF                  NUMBER(9),
   DATA_ENTREGA_DESEJADA DATE                 not null,
   constraint PK_ENCOMENDAS primary key (ID_ENCOMENDA)
);

/*==============================================================*/
/* Index: ENTREGUE_EM_FK                                        */
/*==============================================================*/
create index ENTREGUE_EM_FK on ENCOMENDAS (
   ID_LOCAL ASC
);

/*==============================================================*/
/* Index: FEITA_POR_FK                                          */
/*==============================================================*/
create index FEITA_POR_FK on ENCOMENDAS (
   ID_CLIENTE ASC
);

/*==============================================================*/
/* Index: PAGA_USANDO_FK                                        */
/*==============================================================*/
create index PAGA_USANDO_FK on ENCOMENDAS (
   NOME_METODO ASC
);

/*==============================================================*/
/* Index: ENCONTRA_SE_FK                                        */
/*==============================================================*/
create index ENCONTRA_SE_FK on ENCOMENDAS (
   ID_ESTADO ASC
);

/*==============================================================*/
/* Table: ENTREGA                                               */
/*==============================================================*/
create table ENTREGA 
(
   ID_ENTREGA           NUMBER(8)            not null,
   ID_ENCOMENDA         NUMBER(8)            not null,
   ID_ESTAFETA          NUMBER(8)            not null,
   DATA_ENTREGA         DATE                 not null,
   RATING               NUMBER(3,1),
   constraint PK_ENTREGA primary key (ID_ENTREGA)
);

/*==============================================================*/
/* Index: ENTREGUE_POR_FK                                       */
/*==============================================================*/
create index ENTREGUE_POR_FK on ENTREGA (
   ID_ESTAFETA ASC
);

/*==============================================================*/
/* Table: ESCOLHA                                               */
/*==============================================================*/
create table ESCOLHA 
(
   ID_ENCOMENDA         NUMBER(8)            not null,
   ID_ESTAFETA          NUMBER(8)            not null,
   constraint PK_ESCOLHA primary key (ID_ENCOMENDA, ID_ESTAFETA)
);

/*==============================================================*/
/* Table: ESTADOS                                               */
/*==============================================================*/
create table ESTADOS 
(
   ID_ESTADO            NUMBER(8)            not null,
   NOME_ESTADO          VARCHAR2(30)         not null,
   constraint PK_ESTADOS primary key (ID_ESTADO)
);

/*==============================================================*/
/* Table: ESTAFETA                                              */
/*==============================================================*/
create table ESTAFETA 
(
   ID_ESTAFETA          NUMBER(8)            not null,
   NOME                 VARCHAR2(50)         not null,
   DATA_NASCIMENTO      DATE                 not null,
   TELEMOVEL            NUMBER(9)            not null,
   EMAIL                VARCHAR2(50)         not null,
   POSICAO              VARCHAR2(50)         not null,
   COMISSAO_POR_PAGAR   NUMBER(8,2)          not null,
   FOTO_URL             VARCHAR2(100)        not null,
   constraint PK_ESTAFETA primary key (ID_ESTAFETA)
);

/*==============================================================*/
/* Table: LOCAIS_DE_ENTREGA                                     */
/*==============================================================*/
create table LOCAIS_DE_ENTREGA 
(
   ID_LOCAL             NUMBER(8)            not null,
   RUA                  VARCHAR2(200)        not null,
   NUMERO_PORTA         NUMBER(4)            not null,
   ANDAR                NUMBER(2),
   CODIGO_POSTAL        NUMBER(7)            not null,
   CIDADE               VARCHAR2(50),
   constraint PK_LOCAIS_DE_ENTREGA primary key (ID_LOCAL)
);

/*==============================================================*/
/* Table: LOJAS                                                 */
/*==============================================================*/
create table LOJAS 
(
   ID_LOJA              NUMBER(8)            not null,
   TIPO_LOJA            VARCHAR2(30),
   LOCALIZACAO          VARCHAR2(200)        not null,
   NOME_LOJA            VARCHAR2(30)         not null,
   constraint PK_LOJAS primary key (ID_LOJA)
);

/*==============================================================*/
/* Table: MARCAS                                                */
/*==============================================================*/
create table MARCAS 
(
   ID_MARCA             NUMBER(8)            not null,
   NOME_MARCA           VARCHAR2(30)         not null,
   constraint PK_MARCAS primary key (ID_MARCA)
);

/*==============================================================*/
/* Table: METODOS_PAGAMENTO                                     */
/*==============================================================*/
create table METODOS_PAGAMENTO 
(
   NOME_METODO          VARCHAR2(50)         not null,
   constraint PK_METODOS_PAGAMENTO primary key (NOME_METODO)
);

/*==============================================================*/
/* Table: PAGAMENTO                                             */
/*==============================================================*/
create table PAGAMENTO 
(
   ID_PAGAMENTO         NUMBER(8)            not null,
   ID_ESTAFETA          NUMBER(8)            not null,
   MONTANTE             NUMBER(8,2)          not null,
   DATA_PAGAMENTO       DATE                 not null,
   constraint PK_PAGAMENTO primary key (ID_PAGAMENTO)
);

/*==============================================================*/
/* Index: PAGAMENTO_COMISSOES_FK                                */
/*==============================================================*/
create index PAGAMENTO_COMISSOES_FK on PAGAMENTO (
   ID_ESTAFETA ASC
);

/*==============================================================*/
/* Table: PERTENCE_A                                            */
/*==============================================================*/
create table PERTENCE_A 
(
   ID_CLIENTE           NUMBER(8)            not null,
   ID_LOCAL             NUMBER(8)            not null,
   NOME                 VARCHAR2(50)         not null,
   constraint PK_PERTENCE_A primary key (ID_CLIENTE, ID_LOCAL)
);

/*==============================================================*/
/* Index: PERTENCE_A_FK                                         */
/*==============================================================*/
create index PERTENCE_A_FK on PERTENCE_A (
   ID_CLIENTE ASC
);

/*==============================================================*/
/* Index: PERTENCE_A2_FK                                        */
/*==============================================================*/
create index PERTENCE_A2_FK on PERTENCE_A (
   ID_LOCAL ASC
);

/*==============================================================*/
/* Table: PRODUTOS                                              */
/*==============================================================*/
create table PRODUTOS 
(
   ID_PRODUTO           NUMBER(8)            not null,
   ID_LOJA              NUMBER(8)            not null,
   ID_MARCA             NUMBER(8)            not null,
   PRECO_TABELA         NUMBER(8,2)          not null,
   NOME_PRODUTO         VARCHAR2(30)         not null,
   constraint PK_PRODUTOS primary key (ID_PRODUTO)
);

/*==============================================================*/
/* Index: TEM_DETERMINADA_FK                                    */
/*==============================================================*/
create index TEM_DETERMINADA_FK on PRODUTOS (
   ID_MARCA ASC
);

/*==============================================================*/
/* Index: VENDE_FK                                              */
/*==============================================================*/
create index VENDE_FK on PRODUTOS (
   ID_LOJA ASC
);

/*==============================================================*/
/* Table: VEICULO                                               */
/*==============================================================*/
create table VEICULO 
(
   MATRICULA            VARCHAR2(10)         not null,
   TIPO_VEICULO         VARCHAR2(20),
   DISPONIBILIDADE      SMALLINT             not null,
   MODELO               VARCHAR2(20)         not null,
   MARCA                VARCHAR2(20)         not null,
   constraint PK_VEICULO primary key (MATRICULA)
);

/*==============================================================*/
/* Table: VENDIDA_EM                                            */
/*==============================================================*/
create table VENDIDA_EM 
(
   ID_MARCA             NUMBER(8)            not null,
   ID_LOJA              NUMBER(8)            not null,
   constraint PK_VENDIDA_EM primary key (ID_MARCA, ID_LOJA)
);

/*==============================================================*/
/* Index: VENDIDA_EM_FK                                         */
/*==============================================================*/
create index VENDIDA_EM_FK on VENDIDA_EM (
   ID_MARCA ASC
);

/*==============================================================*/
/* Index: VENDIDA_EM2_FK                                        */
/*==============================================================*/
create index VENDIDA_EM2_FK on VENDIDA_EM (
   ID_LOJA ASC
);

alter table CONDUZ
   add constraint FK_CONDUZ_REFERENCE_ESTAFETA foreign key (ID_ESTAFETA)
      references ESTAFETA (ID_ESTAFETA);

alter table CONDUZ
   add constraint FK_CONDUZ_REFERENCE_VEICULO foreign key (MATRICULA)
      references VEICULO (MATRICULA);

alter table CONTEM
   add constraint FK_CONTEM_ENCOMENDA_ENCOMEND foreign key (ID_ENCOMENDA)
      references ENCOMENDAS (ID_ENCOMENDA);

alter table CONTEM
   add constraint FK_CONTEM_REFERE_PR_PRODUTOS foreign key (ID_PRODUTO)
      references PRODUTOS (ID_PRODUTO);

alter table ENCOMENDAS
   add constraint FK_ENCOMEND_ENCONTRA__ESTADOS foreign key (ID_ESTADO)
      references ESTADOS (ID_ESTADO);

alter table ENCOMENDAS
   add constraint FK_ENCOMEND_ENTREGUE__LOCAIS_D foreign key (ID_LOCAL)
      references LOCAIS_DE_ENTREGA (ID_LOCAL);

alter table ENCOMENDAS
   add constraint FK_ENCOMEND_FEITA_POR_CLIENTE foreign key (ID_CLIENTE)
      references CLIENTE (ID_CLIENTE);

alter table ENCOMENDAS
   add constraint FK_ENCOMEND_PAGA_USAN_METODOS foreign key (NOME_METODO)
      references METODOS_PAGAMENTO (NOME_METODO);

alter table ENTREGA
   add constraint FK_ENTREGA_ASSOCIA_ENCOMEND foreign key (ID_ENCOMENDA)
      references ENCOMENDAS (ID_ENCOMENDA);

alter table ENTREGA
   add constraint FK_ENTREGA_ENTREGUE__ESTAFETA foreign key (ID_ESTAFETA)
      references ESTAFETA (ID_ESTAFETA);

alter table ESCOLHA
   add constraint FK_ESCOLHA_REFERENCE_ENCOMEND foreign key (ID_ENCOMENDA)
      references ENCOMENDAS (ID_ENCOMENDA);

alter table ESCOLHA
   add constraint FK_ESCOLHA_REFERENCE_ESTAFETA foreign key (ID_ESTAFETA)
      references ESTAFETA (ID_ESTAFETA);

alter table PAGAMENTO
   add constraint FK_PAGAMENT_PAGAMENTO_ESTAFETA foreign key (ID_ESTAFETA)
      references ESTAFETA (ID_ESTAFETA);

alter table PERTENCE_A
   add constraint FK_PERTENCE_LOCAL_PER_LOCAIS_D foreign key (ID_LOCAL)
      references LOCAIS_DE_ENTREGA (ID_LOCAL);

alter table PERTENCE_A
   add constraint FK_PERTENCE_REFERE_CL_CLIENTE foreign key (ID_CLIENTE)
      references CLIENTE (ID_CLIENTE);

alter table PRODUTOS
   add constraint FK_PRODUTOS_TEM_DETER_MARCAS foreign key (ID_MARCA)
      references MARCAS (ID_MARCA);

alter table PRODUTOS
   add constraint FK_PRODUTOS_VENDE_LOJAS foreign key (ID_LOJA)
      references LOJAS (ID_LOJA);

alter table VENDIDA_EM
   add constraint FK_VENDIDA__VENDIDA_E_MARCAS foreign key (ID_MARCA)
      references MARCAS (ID_MARCA);

alter table VENDIDA_EM
   add constraint FK_VENDIDA__VENDIDA_E_LOJAS foreign key (ID_LOJA)
      references LOJAS (ID_LOJA);

