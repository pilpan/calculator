== Получен Quest. На языке программирования Си разработать программу src/graph.c для построения графиков функций, задаваемых произвольными выражениями. Для вычисления значений выражений использовать алгоритм Дейкстры для перевода выражения в польскую нотацию. Сборку программы осуществлять при помощи Makefile. Имя стадии сборки - all. Исполняемый файл должен храниться в корне в папке build с именем graph. ==

Условия

Размер поля для вывода графиков - прямоугольник 25 на 80 точек.
Область определения - [0; 4 Пи]
Область значений - [-1; 1]
Ориентация координатной плоскости - ось ординат направлена вниз, ось абсцисс - направо.
Центр координат - середина левой границы (точка {0, 13}).
Рисовать оси не нужно.
Ничего кроме графика выводиться не должно.
Значения округляются по правилам математики.


Графика

График должен быть выведен с помощью знаков Звездочек для линии графика и "." для всего остального пространства экрана. ==***

Модули

Разбор строки выражения и получение списка лексем.
Перевод в польскую нотацию и вычисление по ней.
Отрисовка графика в терминале.
Библиотеки для организации динамических структур данных (стэк, список и т.д.).


Пример:
Входные данные: sin(cos(2*x))
Выходные данные:
................................................................................
................................................................................
.........***.................**..................**.................***.........
........*...................*..*................*..*...................*........
............*...................*..............*...................*............
.......*...................*........................*...................*.......
.............*...................*............*...................*.............
..........................*..........................*..........................
......*..................................................................*......
..............*..................................................*..............
..................................*..........*..................................
.........................*............................*.........................
.....*....................................................................*.....
...............*................................................*...............
...................................*........*...................................
....*...................*..............................*...................*....
................*..............................................*................
....................................*......*....................................
.......................*................................*.......................
...*.............*............................................*.............*...
......................*..............*....*..............*......................
..*...............*...................*..*...................*...............*..
**.................***.................**.................***.................**
................................................................................
................................................................................

Использовать можно только <math.h>, <stdio.h>, <stdlib.h>, <string.h> и ваши собственные библиотеки


В этом задании не предусмотрена автопроверка на вывод, ваше изображение может немного отличаться от данного примера


Все возможные операции и функции находятся ниже
