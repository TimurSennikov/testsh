###TESTSH###

как скомпилировать?

.c файлы закидываете в / директории, .h в директорию /headers, и вводите команду
gcc main.c tools.c exec.c
перед вводом команды можете покрутить конфиги в config.h, там всякие цвета разные можно настраивать (USERNAME_COLOR и DIRPATH_COLOR).

на момент 29.04.2024 версия 4 в обоих ветках (develop и main).
последнее изменение: добавлено cd как в современных shell, а именно поддержка тильды.
