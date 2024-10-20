#!/bin/bash

## Compilo código objeto
#g++ -std=c++17 -Wall -I./include -c ./src/Article.cpp 
#g++ -std=c++17 -Wall -I./include -c ./src/ArticleList.cpp 
#g++ -std=c++17 -Wall -I./include -c ./src/Customer.cpp 
#g++ -Wall -std=c++17 -I./include -c ./src/Order.cpp 
#g++ -Wall -std=c++17 -I./include -c main.cpp 

### Compilo el Binario
g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror main.cpp -o app.exe

### Limpio los códigos objeto
#rm ./*.o

### Permisos de ejecución
chmod +x app.exe
