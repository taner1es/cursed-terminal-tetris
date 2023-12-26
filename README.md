# cursed-terminal-tetris

A Tetris clone playable on terminal very quickly.

`build size: 28KB`
`debug size: 80KB`
`repo size: 1.5MB`

![Playshot](playshot.gif)

#### Building on debian based OS:

`g++`  : <https://gcc.gnu.org/>

`ncurses` : <https://invisible-island.net/ncurses>

`make` : https://www.gnu.org/software/make/

     sudo apt-get update
     sudo apt install git g++ libncurses-dev make --yes
     git clone https://github.com/taner1es/cursed-terminal-tetris.git
     cd cursed-terminal-tetris
     make
     build/tetris.build
