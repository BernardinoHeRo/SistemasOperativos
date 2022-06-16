#!/bin/bash
for tarea in "$@"
do
    $tarea &
done
wait
