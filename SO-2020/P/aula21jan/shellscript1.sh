#!/bin/bash

#Script para contar o nº de ficheiros de uma diretoria
#Utilizador indica o nome do utilizador
#Autor: zezocas
#Versão: 0.001
#Data: 21/01/2021
#Alterações: Script criado

#Constantes
DIR="/home/"

#Proteção dos parâmetros de entrada do script
if [ $# -lt 1 ]
then
   echo "Recebi $# argumentos."
   echo "Utilização: $0 [nome1] ([nome2]) (...) ([nomeN])."
   exit -1
else
   echo "Parametros corretos. Vou contar o nº de ficheiros."
fi

#echo "Na diretorio $1 existem `ls -lA $1 | tail -n +2 | wc -l` ficheiros."
#echo "Na diretorio $1 existem $(ls -lA $1 | tail -n +2 | wc -l) ficheiros."

#Deviamos verificar se o $1 contem a palavra /home/ para nao repetir
for i in $*
do
echo "Na diretorio $DIR$i existem `ls -lA $DIR$i | tail -n +2 | wc -l` ficheiros."
done
