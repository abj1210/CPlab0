#! /bin/bash

NAME=闻嘉迅_211220091.zip

rm -f ${NAME}
cd Code
make clean 
cd ../
zip -r ${NAME} ./Code/* ./README.md ./report.pdf


