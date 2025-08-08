# 🎮 Platformer Game

A simple but fun **2D platformer** built in C++ using **SFML**.  
Jump, avoid enemies, and reach the goal.

---

## 📜 Game Overview
You play as a character navigating through platforms and avoiding enemies along the way.  
Your goal is to **reach the door** at the end of each level without losing your life.

---

## 🎯 Features
- Main Menu along with pause screens during gameplay
- Smooth player movement & jumping
- Enemy + Platform movement
- Axis-Aligned Bounding Box (AABB) collision detection system
- Level based game i.e. five levels
- Background music & sound effects
- Resource loading for textures, fonts, and audio

---

## 📂 Project Structure
```bash
  .
├── resources/
│   ├── assets/           # Images
│   ├── arial.ttf         # Font
│   ├── music.ogg         # Background music
│
├── sfml/include/SFML     # SFML
├── src/                  # All C++ source files
├── 2D-Platformer.sln     # Visual Studio solution
├── 2D-Platformer.vcxproj     # Visual C++ project file containing build settings
├── 2D-Platformer.vcxproj.filters     # Stores the virtual folder structure for source files in Visual Studio
└── README.md
```
---

## 🎮 Controls
| Key        | Action           |
|------------|------------------|
| **A / ←**  | Move Left        |
| **D / →**  | Move Right       |
| **Space**  | Jump             |
| **Esc**    | Pause Game        |

---

## 🛠 Development Setup

### Prerequisites
- **Visual Studio 2019/2022** with the **Desktop development with C++** workload installed  
- **SFML 2.5.1** (download from [https://www.sfml-dev.org/download.php](https://www.sfml-dev.org/download.php))

---

### Building the Project (Windows, Visual Studio)
1. Clone or download this repository  
```bash
git clone https://github.com/ajawad06/2D-Platformer.git
cd 2D-Platformer
```
2. Open 2D-Platformer.sln in Visual Studio

3. Configure SFML in Visual Studio:

    a) Go to Project → Properties → C/C++ → General → Additional Include Directories and add: 
   ```bash
    SFML/include
   ```

    b) Go to Linker → General → Additional Library Directories and add:
    ```bash
      SFML/lib
    ```

    c) Go to Linker → Input → Additional Dependencies and add:
      ```vbnet
    sfml-graphics.lib
    sfml-window.lib
    sfml-system.lib
    sfml-audio.lib
    ```
    d) Copy the required .dll files from:
    ```bash
    SFML/bin
    ```
    into the same folder as your compiled .exe

4. Make sure the Platform is set to x64

5. Press Ctrl + F5 to build and run

