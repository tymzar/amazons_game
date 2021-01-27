# epfu20W-104-E-amazons

## Table of contents

- [Short description](#short-description)
- [Project Members](#project-members)
- [Reports](#reports)
- [Typing Conventions](#typing-convention)
- [Manual and automatic tests](#manual-and-automatic-tests)
- [Running the code](#running-the-code)

## Short description

This is an extended version of board game "The Amazons".
The game is played on a chess-like board.
The goal of the players is collect as much treasure as they can by moving their amazons on the board.
Player which collects most treasure wins

## Project Members

- Tymon Żarski {- Project manager -}
- Jan Szachno {+ Guardian of the flock +}
- Mateusz Jakubowski {- Paymaster -}
- Cagla Kuleasan {- Master of the C language -}

## Project documentation on website

[Projet documentation](https://tymzar.github.io/amazons_www_site/ 'Projet documentation')

## Reports

All meeting reports are available in [Docs](https://gitlab-stud.elka.pw.edu.pl/mjakubo3/epfu20w-104-E-amazons/-/tree/master/Docs 'Projets Docs')

Moreover, flowcharts can be found in this directory

## Typing Convention

```
Struct              TitleCase
Struct Members      lower_case or lowerCase

Enum                ETitleCase
Enum Members        ALL_CAPS or lowerCase

Public functions    pfx_TitleCase (pfx = two or three letter module prefix)
Private functions   lower_case
Trivial variables   i,x,n,f etc...
Local variables     lower_case or lowerCase
Global variables    g_lowerCase or g_lower_case (searchable by g_ prefix)
```

## Manual and automatic tests

In directory "Docs/Manual Tests" we have provided logs form correctly working game. Including compilation and move validation, command line parameters validation also read and write capabilities.

We have done automated tests on a game tester (amazon disc provided by tutor). All test takes has been passed. During test we haven't met any errors or bugs.

## Running the code

### For LinuxOS

Navigate to the `Source` folder.
Then use the commands:

- For interactive mode

```
1. make interactive   // To generate compiled output file
2. ./interactive      // To run compiled code
```

- For autonomous mode

```
1. make autonomous   // To generate compiled output file
2. ./autonomous      // To run compiled code
```

### For WindowsOS

1. Install make for windows [YT-Tutorial](https://www.youtube.com/watch?v=taCJhnBXG_w 'Projects Libs')

2. Navigate to the `Source` folder.
   Then use the commands:

- For interactive mode

```
1. make interactive && make clean   // To generate compiled output file
2. ./interactive.exe  // To run compiled code
```

- For autonomous mode

```
1. make autonomous && make clean   // To generate compiled output file
2. ./autonomous.exe  // To run compiled code
```
