#!/bin/bash
./tarea.sh 4 Tarea1 &
./tarea.sh 3 Tarea2 &
wait
./tarea.sh 2 Tarea3 &
./tarea.sh 1 Tarea4 &
wait
