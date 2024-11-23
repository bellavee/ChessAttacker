# Chess Attacker

Chess Attacker is a unique turn-based tactical RPG that combines chess mechanics with roguelike elements. Players control a single chess piece that changes its movement pattern over time while surviving against enemy chess pieces in an expansive battlefield.

## Description

In Chess Attacker, you start as a king piece in a vast chess arena, surrounded by enemy pieces hunting you down. Your piece's role changes each turn, adding strategic depth and variety to gameplay. Navigate through various chapters, each introducing unique enemy types and challenging boss battles.

### Key Features

- Turn-based tactical gameplay
- Dynamic piece transformation system
- 5 unique chapters with distinct enemies and mechanics
- Boss battles with special abilities and patterns
- Piece storage system similar to Tetris' piece holding
- Fog of war system with limited visibility
- Multiple enemy types with unique movement patterns

## Building from Source

### Prerequisites

- CMake (3.15 or higher)
- C++ Compiler with C++17 support
- Raylib (latest stable version)

### Build Instructions

1. Clone the repository:
```bash
git clone https://github.com/bellavee/ChessAttacker.git
cd ChessAttacker
```

2. Create a build directory:
```bash
mkdir build
cd build
```

3. Generate build files with CMake:
```bash
cmake ..
```

4. Build the project:
```bash
cmake --build .
```

### Running the Game

After building, you can find the executable in the `build` directory:
```bash
./ChessAttacker  # On Unix-like systems
ChessAttacker.exe  # On Windows
```

## Project Structure

```
ChessAttacker/
├── src/             # Source files
├── include/         # Header files
├── assets/         # Game assets (sprites, sounds, etc.)
├── CMakeLists.txt  # CMake configuration
└── README.md       # This file
```
