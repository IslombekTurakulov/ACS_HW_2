# Второе Домашнее задание "Архитектура вычислительных систем"
## Задача: Языки программирования, Вариант 148 (8, 11)
### Автор: Туракулов Исломбек Улугбекович

## Условие задачи
### Общие для всех альтернатив переменные
* Популярность в процентах (TIOBI) — действительное
* Год создания — целое
------
### Общие для всех альтернатив функции
Частное от деления года создания на количество символов в названии (действительное число)
---------
### Базовые альтернативы
#### _Процедурные_

* наличие, отсутствие абстрактных типов данных – булевская величина

#### _Объектно-ориентированные_

* наследование: одинарное, множественное, интерфейса – перечислимый тип

#### _Функциональные_
* типизация – перечислимый тип = строгая, динамическая
* поддержка «ленивых» вычислений – булевский тип

### Функционал
_После размещения данных в контейнер необходимо осуществить их обработку
в соответствии с вариантом задания.
Обработанные данные после этого заносятся в отдельный файл результатов._

Упорядочить элементы контейнера по возрастанию используя сортировку
Сортировка с помощью прямого выбора (Straight Selection).
В качестве ключей для сортировки и других действий используются
результаты функции, общей для всех альтернатив.

---------

## Сборка полученной программы.
```
cmake -B <build_dir> -DCMAKE_BUILD_TYPE=Release
cmake --build <build_dir> --target main
```
Исполняемый файл программы будет расположен в папке `bin`.

---

## Тестирование
Исходные данные для тестирования содержатся в каталоге `tests`.

Файл с результатами прогонов тестов `tests/report.txt`.

Примеры использования программы без тестирующего скрипта. Предполагается, что сейчас мы в корне проекта. Использовался компилятор GCC в ОС Linux
```
# Parse input file with data
./bin/main tests/mixed.txt tests/mixed.out
# Parse input file with random generator setup for the test
./bin/main -n 100 tests/data/random.out.txt tests/random_sorted.out.txt
```

Время работы программы на разных размерах входных данных:
Количество языков программирования | Время работы, seconds | Потребляемая память, KB
--- | --- | ---
7 | < 0.001 | ~2600
100 | < 0.01 | ~2800
1000 | 0.01 | ~3500
5000 | 0.14 | ~4150
10000 | 1.10 | ~4625

---

## Метрики, определяющие характеристики программы:
| Метрика | Значение |
| :---: | --- |
| Число интерфейсных модулей | 6 |
| Число модулей с реализацией | 5 + 1 (дополнительные методы для рандомизации) |
| Общий размер исходных текстов программы | 17.451 KB |
| Размер исполняемого файла релизной сборки (GCC, Linux)__*__ | 34.902 KB |

__*__ Версии подробнее:
```
$ g++ --version
g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

$ lsb_release -a
Distributor ID: Ubuntu
Description:    Ubuntu 20.04.2 LTS
Release:        20.04
Codename:       focal

$ uname -a
Linux DESKTOP-250N7G3 5.10.16.3-microsoft-standard-WSL2 #1 SMP Fri Apr 2 22:23:49 UTC 2021 x86_64 x86_64 x86_64 GNU/Linux
```

## Описание структуры вычислительной системы:
### Размеры фундаментальных типов на машине amd64:
Тип | Размер в байтах
:--- | ---:
int    | 4 
char   | 1 
double | 8 
bool   | 1

Глобальная память:
```
" [-n <number_of_elements>] <input_file> <output_file>\n"  // size: 56
"Incorrect argumens. Number must be in range [1, 10000] but it is equal to "  // size: 72
"Failed to read file."  // size: 21
"Container cannot contain so many elements."  // size: 43
"Malformed input"  // size: 16
"-n"  // size: 3
```
| Таблица классов<br>Базовые Классы     |                                                                                        Container [80004 байт]                                                                                       |
|---------------------------------------|:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|
| Поля                                  | Static: Отсутствует<br><br>Local:<br>int length [4 байта]<br>Language *cont[8 * 10000 байт]                                                                                                         |
| Методы                                | Static: Отсутствует<br><br>Local: <br>void In(FILE *file);<br>void InRnd(int size);<br>void Out(FILE *file);<br>void StraightSelectionSort();<br>void Clear();                                      |
| Enum                                  |                                                                                             Отсутствует                                                                                             |
| Таблица классов<br>Базовые Классы     |                                                                                          Languages [0 байт]                                                                                         |
| Поля                                  | Static:<br>Отсутствует<br><br>Local: <br>Отсутствует                                                                                                                                                |
| Методы                                | Static: Languages *StaticIn(FILE *file); <br>Languages *StaticInRnd();<br><br><br>Local: <br>~Languages();<br>void In(FILE *file);<br>void InRnd();<br>void Out(FILE *file);<br>double Quotinent(); |
| Enum                                  |                                                                                             Отсутствует                                                                                             |

| Таблица классов<br>Производные классы |                                                                              Functional : Languages [26 байт + 0 байт]                                                                              |
|---------------------------------------|:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|
| Поля                                  | Static: <br>Отсутствует<br><br>Local: <br>const char *name_[5 байт];<br>int age_ [4 байт];<br>double popularity_ [8 байт];<br>bool lazy_calculation_ [1 байт];<br>int type_ [4 байт];               |
| Методы                                | Static:<br><br><br><br>Local:<br>~Functional(); <br>void In(FILE *file); <br>void InRnd(); <br>void Out(FILE *file);<br>double Quotinent();                                                         |
| Enum                                  |                                                                                      Enum MAX_LENGTH -> 4 байта                                                                                     |
| Производный класс                     |                                                                            ObjectOriented : Languages [26 байт + 0 байт]                                                                            |
| Поля                                  | Static: <br>Отсутствует<br><br>Local: <br>const char *name_[5 байт];<br>int age_ [4 байт];<br>double popularity_ [8 байт];<br>bool has_abstract_variables_ [1 байт];<br>int type_ [4 байт];         |
| Методы                                | Static:<br><br><br><br>Local:<br>~ObjectOriented(); <br>void In(FILE *file); <br>void InRnd(); <br>void Out(FILE *file);<br>double Quotinent();                                                     |
| Enum                                  |                                                                                      Enum MAX_LENGTH -> 4 байта                                                                                     |
| Производный класс                     | Procedural : Languages [18 байт + 0 байт]                                                                                                                                                           |
| Поля                                  | Static: <br>Отсутствует<br><br>Local: <br>const char *name_[5 байт];<br>int age_ [4 байт];<br>double popularity_ [8 байт];<br>bool has_abstract_variables_ [1 байт];                                |
| Методы                                | Static:<br><br><br><br>Local:<br>~ObjectOriented(); <br>void In(FILE *file); <br>void InRnd(); <br>void Out(FILE *file);<br>double Quotinent();                                                     |
| Enum                                  |                                                                                             Отсутствует                                                                                             |
