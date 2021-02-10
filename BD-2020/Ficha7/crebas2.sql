/*==============================================================*/
/* DBMS name:      PostgreSQL 9.x                               */
/* Created on:     16-Nov-20 11:40:43                           */
/*==============================================================*/


drop index TRANSPORTA_FK;

drop index TEM_FK;

drop index ENCOMENDA_PK;

drop table ENCOMENDA;

drop index CONTEM_FK;

drop index ENC_PAO_PK;

drop table ENC_PAO;

drop index PADARIA_PK;

drop table PADARIA;

drop index PAO_PK;

drop table PAO;

drop index VEICULO_PK;

drop table VEICULO;

/*==============================================================*/
/* Table: ENCOMENDA                                             */
/*==============================================================*/
create table ENCOMENDA (
   ID_ENCOMENDA         NUMERIC(6)           not null,
   ID_PADARIA           NUMERIC(4)           not null,
   ID_VEICULO           NUMERIC(4)           not null,
   DATA                 DATE                 not null,
   LOCAL_ENTREGA        VARCHAR(40)          null,
   constraint PK_ENCOMENDA primary key (ID_ENCOMENDA)
);

/*==============================================================*/
/* Index: ENCOMENDA_PK                                          */
/*==============================================================*/
create unique index ENCOMENDA_PK on ENCOMENDA (
ID_ENCOMENDA
);

/*==============================================================*/
/* Index: TEM_FK                                                */
/*==============================================================*/
create  index TEM_FK on ENCOMENDA (
ID_PADARIA
);

/*==============================================================*/
/* Index: TRANSPORTA_FK                                         */
/*==============================================================*/
create  index TRANSPORTA_FK on ENCOMENDA (
ID_VEICULO
);

/*==============================================================*/
/* Table: ENC_PAO                                               */
/*==============================================================*/
create table ENC_PAO (
   ID_PAO               NUMERIC(4)           not null,
   ID_ENCOMENDA         NUMERIC(6)           null,
   QUANTIDADE           NUMERIC(4)           not null,
   constraint PK_ENC_PAO primary key (ID_PAO)
);

/*==============================================================*/
/* Index: ENC_PAO_PK                                            */
/*==============================================================*/
create unique index ENC_PAO_PK on ENC_PAO (
ID_PAO
);

/*==============================================================*/
/* Index: CONTEM_FK                                             */
/*==============================================================*/
create  index CONTEM_FK on ENC_PAO (
ID_ENCOMENDA
);

/*==============================================================*/
/* Table: PADARIA                                               */
/*==============================================================*/
create table PADARIA (
   ID_PADARIA           NUMERIC(4)           not null,
   NOME                 VARCHAR(30)          not null,
   CIDADE               VARCHAR(20)          null,
   TELEFONE             VARCHAR(12)          null,
   CONTRIBUINTE         VARCHAR(9)           null,
   constraint PK_PADARIA primary key (ID_PADARIA)
);

/*==============================================================*/
/* Index: PADARIA_PK                                            */
/*==============================================================*/
create unique index PADARIA_PK on PADARIA (
ID_PADARIA
);

/*==============================================================*/
/* Table: PAO                                                   */
/*==============================================================*/
create table PAO (
   ID_PAO               NUMERIC(4)           not null,
   DESIGNACAO           VARCHAR(30)          not null,
   TIPO                 VARCHAR(30)          null,
   PESO                 NUMERIC(5,2)         null,
   constraint PK_PAO primary key (ID_PAO)
);

/*==============================================================*/
/* Index: PAO_PK                                                */
/*==============================================================*/
create unique index PAO_PK on PAO (
ID_PAO
);

/*==============================================================*/
/* Table: VEICULO                                               */
/*==============================================================*/
create table VEICULO (
   ID_VEICULO           NUMERIC(4)           not null,
   MATRICULA            VARCHAR(8)           not null,
   MARCA                VARCHAR(30)          null,
   MODELO               VARCHAR(30)          null,
   TARA                 NUMERIC(4)           null,
   constraint PK_VEICULO primary key (ID_VEICULO)
);

/*==============================================================*/
/* Index: VEICULO_PK                                            */
/*==============================================================*/
create unique index VEICULO_PK on VEICULO (
ID_VEICULO
);

alter table ENCOMENDA
   add constraint FK_ENCOMEND_TEM_PADARIA foreign key (ID_PADARIA)
      references PADARIA (ID_PADARIA)
      on delete restrict on update restrict;

alter table ENCOMENDA
   add constraint FK_ENCOMEND_TRANSPORT_VEICULO foreign key (ID_VEICULO)
      references VEICULO (ID_VEICULO)
      on delete restrict on update restrict;

alter table ENC_PAO
   add constraint FK_ENC_PAO_CONTEM_ENCOMEND foreign key (ID_ENCOMENDA)
      references ENCOMENDA (ID_ENCOMENDA)
      on delete restrict on update restrict;

alter table ENC_PAO
   add constraint FK_ENC_PAO_REFERE_PAO foreign key (ID_PAO)
      references PAO (ID_PAO)
      on delete restrict on update restrict;

