.h файлы по структуре лежат в директории headers, мне было лень настолько точно их переносить

как скомпилировать?

.c файлы закидываете в / директории, .h в директорию /headers, и вводите команду
gcc main.c tools.c exec.c
перед вводом команды можете покрутить конфиги в config.h, там всякие цвета разные можно настраивать (USERNAME_COLOR и DIRPATH_COLOR).
