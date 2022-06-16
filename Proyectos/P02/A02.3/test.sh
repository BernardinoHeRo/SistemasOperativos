#!/bin/bash
cd ~/PCL/Proyectos/P02/A02.2
./MCPV < ~/PCL/dev/CO2 > probabilidades
cd ~/PCL/Proyectos/P02/A02.3
./ENCRIPTADOR < ~/PCL/Proyectos/P02/A02.2/probabilidades  archivo_cifrado
rm ~/PCL/Proyectos/P02/A02.2/probabilidades
rm ~/PCL/Proyectos/P02/A02.2/' '
echo "Resultado exitoso"