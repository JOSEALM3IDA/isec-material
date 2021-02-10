#!/bin/bash

UC="Sistemas Operativos"
trap 'echo Trap: X=${X} Y=${Y} Z=${Z}.' DEBUG
X=10
((X+=2))
Y=4
Z=$((X+Y+2))
echo "Se não estudar para ${UC} vou ter no máximo $(((X+Y+2)/2)) \
mas também posso ter ${Y}. Porém, se me aplicar, posso até ter $((Z+2))."

