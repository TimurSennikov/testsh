# TESTSH

## как скомпилировать?

### клонируете репозиторий и вводите:
### gcc main.c tools.c exec.c readCommands.c
### перед вводом команды можете покрутить конфиги в config.h, там всякие цвета разные можно настраивать (USERNAME_COLOR, DIRPATH_COLOR и WARN_COLOR).

## на момент 29.04.2024 версия 5 в ветке main и 4 в develop.

## список изменений версии 5 (от крупных к маленьким):

### появилась встроенная команда "history".
### добавлены новые .c и .h файлы для встроенных команд.
### фикс бага с cd ~, причем версия с этим багом даже не была выложена на гитхаб.
### изменена структура проекта.

#### фан факт: testsh было тестовым названием, но оно мне понравилось и я решил его оставить.
