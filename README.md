# TESTSH

## как скомпилировать?

### клонируете репозиторий и вводите:
### gcc -o testsh main.c tools.c exec.c readCommands.c
### при правильной компиляции в файле testsh будет shell.

### перед вводом команды можете покрутить конфиги в config.h, там всякие цвета разные можно настраивать (USERNAME_COLOR, DIRPATH_COLOR, WARN_COLOR, SIGN).

## на момент 29.04.2024 версия 5 в ветке main и 4 в develop.

## список изменений версии 6 (от крупных к маленьким):
### добавлено больше встроенных комманд (список ниже).
### hostname теперь отображается после username (полная строка: username@hostname dirpath SIGN , (пробел перед , не случайно) последний можете изменить в config.h).

# список встроенных комманд
## history - история комманд.
## testshCredits - благодарности.
## help - помощь.

#### фан факт: testsh было тестовым названием, но оно мне понравилось и я решил его оставить.
