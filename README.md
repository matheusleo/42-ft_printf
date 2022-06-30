# 42-ft_printf

O objetivo do projeto é replicar a popular função **printf** da ``<stdlib.h>`` e entender o funcionamento de ``variadic functions`` em C.

## Compilação

### Mandatório

Para compilar a parte mandatória do projeto, basta executar o seguinte comando na root do projeto:

```
	make
```
A parte mandatória consistia em implementar um modelo funcional da printf para os identificadores:

- c
- s
- p
- d
- i
- u
- x
- X
- %

### Bônus

Para compilar a parte bônus do projeto, basta executar o seguinte comando também na root do projeto.

```
make bonus
```
A parte bônus consiste em um super set da parte mandatória que aceita as seguintes flags:

- '#'
- ' ' <- isso é um espaço
- '+'
- '.'
- '-'
- '0'
- field width

## Execução

Para utilizar a função ``ft_printf``, basta executar um dos comandos anteriores e compilar uma função principal que utilize a função

```
	<COMPILADOR> -Wall -Wextra -Werror <FILE> libftprintf.a -I includes
```
