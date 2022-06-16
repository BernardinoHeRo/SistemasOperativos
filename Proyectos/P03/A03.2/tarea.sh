#!/bin/bash
inicio=$(date +%s%3N)
sleep $1
fin=$(date +%s%3N)
tiempo=$(echo "scale=3;($fin-$inicio)/1000.0" | bc)
echo "$2 en $tiempo segundos"