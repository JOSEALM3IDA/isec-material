/*==============================================================*/
/* DBMS name:      ORACLE Version 11g                           */
/* Created on:     16-Nov-20 12:15:48                           */
/*==============================================================*/


drop table VEICULO2 cascade constraints;

/*==============================================================*/
/* Table: VEICULO2                                              */
/*==============================================================*/
create table VEICULO2 
(
   IDVEICULO            NUMBER               not null,
   MATRICULA            NUMBER               not null,
   MARCA                NUMBER,
   MODELO               NUMBER,
   ID_MOTOR             NUMBER               not null,
   CILINDRADA           NUMBER,
   COMBUSTIVEL          NUMBER,
   CAVALOS              NUMBER,
   constraint PK_VEICULO2 primary key (IDVEICULO)
);

