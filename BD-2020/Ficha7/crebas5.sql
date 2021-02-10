/*==============================================================*/
/* DBMS name:      ORACLE Version 11g                           */
/* Created on:     16-Nov-20 12:31:19                           */
/*==============================================================*/


alter table POSSUI
   drop constraint FK_POSSUI_REFERENCE_MOTOR;

alter table POSSUI
   drop constraint FK_POSSUI_REFERENCE_VEICULO;

drop table MOTOR cascade constraints;

drop table POSSUI cascade constraints;

drop table VEICULO cascade constraints;

/*==============================================================*/
/* Table: MOTOR                                                 */
/*==============================================================*/
create table MOTOR 
(
   ID_MOTOR             NUMBER               not null,
   CILINDRADA           NUMBER,
   COMBUSTIVEL          NUMBER,
   CAVALOS              NUMBER,
   constraint PK_MOTOR primary key (ID_MOTOR)
);

/*==============================================================*/
/* Table: POSSUI                                                */
/*==============================================================*/
create table POSSUI 
(
   IDVEICULO            NUMBER               not null,
   ID_MOTOR             NUMBER               not null,
   constraint PK_POSSUI primary key (IDVEICULO, ID_MOTOR)
);

/*==============================================================*/
/* Table: VEICULO                                               */
/*==============================================================*/
create table VEICULO 
(
   IDVEICULO            NUMBER               not null,
   MATRICULA            NUMBER               not null,
   MARCA                NUMBER,
   MODELO               NUMBER,
   constraint PK_VEICULO primary key (IDVEICULO)
);

alter table POSSUI
   add constraint FK_POSSUI_REFERENCE_MOTOR foreign key (ID_MOTOR)
      references MOTOR (ID_MOTOR);

alter table POSSUI
   add constraint FK_POSSUI_REFERENCE_VEICULO foreign key (IDVEICULO)
      references VEICULO (IDVEICULO);

