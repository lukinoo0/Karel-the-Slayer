# ⚔️ Karel the Slayer (console game)

A terminal-based adventure/puzzle game written in **C** using **ncurses**.  
The game renders ASCII-art maps, shows intro/outro screens from text files, and lets you explore, gather resources, and survive hazards.

---

## 🎮 Gameplay

**Karel the Slayer** is a logic adventure game where you move through different ASCII worlds, avoid traps, and complete objectives.  
The game displays a **welcome** screen on start and **end/lost** screens depending on how the game ends.

### 🔸 Map elements:
| Symbol | Meaning |
|--------|----------|
| `^ v < >` | Player (direction faced) |
| `#` | Portal / level transition |
| `&` | Cleared or interacted tile |
| `X` | Trap or enemy |
| `*` | Object or collectible |
| `T` | Tree, decoration |
| `C` | Castle, cave, forest, etc. |

> The game includes multiple maps such as **main map**, **forest**, **cave**, and **final boss** area.  
> Depending on the player’s movement, the game transitions between these maps dynamically.

---

## ⌨️ Controls

- **Arrow keys** → move the player  
- **Q** → quit (available on end screens)  
- **Enter** → continue after end screen  

---

## ⚙️ Build Instructions

### 🧱 Requirements
- **C compiler** (GCC or Clang)
- **ncurses library**

Install ncurses if not already installed:
- macOS: `brew install ncurses`
- Ubuntu/Debian: `sudo apt install libncurses5-dev`
- Fedora: `sudo dnf install ncurses-devel`

---

### 🛠️ Compile manually
```bash
gcc -std=c11 -Wall -Wextra -Werror program.c -lncurses -lm -o karel-the-slayer

If you’re on macOS (Apple Silicon), you may need:

gcc -I/opt/homebrew/opt/ncurses/include -L/opt/homebrew/opt/ncurses/lib program.c -lncurses -lm -o karel-the-slayer

🧰 Makefile

Use this Makefile for simple compilation:

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror
LDLIBS = -lncurses -lm
OUTPUT = karel-the-slayer
SRC = program.c

all: $(OUTPUT)

$(OUTPUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LDLIBS) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT) *.o


To build:

make


To clean:

make clean


🧠 Notes

The game loads ASCII art from .txt files at runtime — these must be in the same folder.

All drawing and movement are handled using ncurses (refresh, move, getch).

Logic switches maps based on coordinates and interactions (e.g., stepping on # triggers a level change).
