# Third Semester C++ Coursework Archive

An archive of third-semester university coursework centered on C++, data
structures, object-oriented programming, and Qt/qmake projects. The repository
also preserves a small set of numerical-computing scripts, assignment documents,
diagrams, IDE metadata, and historical archive material from the same semester.

This is an academic record, not a single production-ready application or a
uniformly buildable codebase. The source and directory layout are preserved for
provenance; the descriptions below identify representative entry points based
on the files currently in the archive.

## Clone

```text
https://github.com/xfelipealves/ThirdSemester.git
```

```bash
git clone https://github.com/xfelipealves/ThirdSemester.git
cd ThirdSemester
```

## Featured Work

### AVL-backed game-physics simulation

- [`Estrutura de dados 1/trab avl/Game Physics Felipe Camilo/main.cpp`](<Estrutura%20de%20dados%201/trab%20avl/Game%20Physics%20Felipe%20Camilo/main.cpp>)
- [`AVLTree.h`](<Estrutura%20de%20dados%201/trab%20avl/Game%20Physics%20Felipe%20Camilo/AVLTree.h>)
- [`untitled.pro`](<Estrutura%20de%20dados%201/trab%20avl/Game%20Physics%20Felipe%20Camilo/untitled.pro>)

This is the strongest data-structures project in the archive. It models
players and objects on a bounded grid, stores spatial objects in a templated
AVL tree, keeps player state in a linked list, and processes positional input
for movement, attacks, and block placement or removal. The tree exposes
insertion, search, removal, and balancing rotations, making the project a
useful snapshot of applied tree and linked-list work rather than a general game
engine.

The matching qmake project requests C++11 and lists the implementation sources.
It does not include a ready-made input fixture, so compiling the project alone
does not produce a self-explanatory demonstration.

### Mau Mau card game

- [`Estrutura de dados 1/trab lista pilha fila/maumau/Nova pasta/untitled/main.cpp`](<Estrutura%20de%20dados%201/trab%20lista%20pilha%20fila/maumau/Nova%20pasta/untitled/main.cpp>)
- [`Jogo.cpp`](<Estrutura%20de%20dados%201/trab%20lista%20pilha%20fila/maumau/Nova%20pasta/untitled/Jogo.cpp>)
- [`untitled.pro`](<Estrutura%20de%20dados%201/trab%20lista%20pilha%20fila/maumau/Nova%20pasta/untitled/untitled.pro>)

This multi-file console project coordinates players, cards, a draw pile, a
discard pile, and turn order. The implementation uses custom list and stack
classes, distributes five cards per player, reads a 104-card deck, handles
special-card effects such as direction changes, skipped turns, and forced
drawing, and reports the winner. A second preserved variant lives under
`maumau2/`; both folders retain their coursework PDF.

### Multiple-inheritance vehicle model

[`Tecnicas de programação 2/trab herancamultipla/untitled4/`](<Tecnicas%20de%20programação%202/trab%20herancamultipla/untitled4/>)

This Qt Widgets assignment demonstrates object-oriented modeling with a
`Veiculo` base class, a `Motor` class, and vehicle types such as `Caminhao` and
`CarroPasseio`. The implementation combines inheritance, virtual display
methods, constructors, validation through exceptions, `QString`, a `.ui` form,
and a qmake project. It is a representative GUI exercise for the semester's
programming-techniques work, not a finished vehicle-management product.

### Contact agenda

- [`Tecnicas de programação 2/trabAgenda/versaofinal/untitled7/Agenda.cpp`](<Tecnicas%20de%20programação%202/trabAgenda/versaofinal/untitled7/Agenda.cpp>)
- [`untitled7.pro`](<Tecnicas%20de%20programação%202/trabAgenda/versaofinal/untitled7/untitled7.pro>)

The final-looking agenda variant stores contacts in a linked structure and
supports adding, removing, searching, printing, and ordering contacts. It
models physical and legal persons through separate classes and uses a Qt
Widgets interface. Several neighboring `trabAgenda` folders preserve earlier
or parallel revisions, so the `versaofinal` path is a representative entry
point rather than proof that it is the only canonical version.

### File-backed animal project

[`Tecnicas de programação 2/trab arquivinho/projetoAnimal/projetoAnimal/`](<Tecnicas%20de%20programação%202/trab%20arquivinho/projetoAnimal/projetoAnimal/>)

This Qt/OOP project combines an animal class hierarchy with a small
`Persistencia` helper. The helper appends records to a text file, reads them
back, and rewrites the file through a temporary file when entries are removed.
It is a useful representative of inheritance, GUI work, and introductory file
persistence, while retaining the limitations of a classroom implementation.

## Topics Covered

- AVL trees, binary trees, linked lists, circular lists, stacks, queues, and pointer-based node management.
- Grid search and state updates applied to a small game-physics simulation.
- C++ inheritance, polymorphism, templates, multiple inheritance, constructors, exceptions, and class composition.
- Qt Core/Gui/Widgets applications, `.ui` forms, and qmake project files.
- Text-file persistence and basic record manipulation.
- Preserved numerical-computing scripts under `Fundamentos de computação 3/`, including matrix factorization exercises written for MATLAB/Octave-style environments.

## Directory Map

```text
Estrutura de dados 1/
├── trab avl/
│   ├── Game Physics Felipe Camilo/  AVL-backed grid simulation and qmake project
│   ├── AVLTree.h                    Additional AVL implementation variant
│   └── Game_Physics_trab_final (1).doc
├── trab lista pilha fila/
│   ├── maumau/                      Mau Mau implementation and coursework PDF
│   └── maumau2/                     Preserved Mau Mau variant and PDF
├── arvore template/untitled/        Tree templates, nodes, and qmake metadata
├── trab ed1/trab/                   Data-structure exercise and project metadata
├── AVLTree.h                         Standalone AVL header variant
├── DList.txt                         Doubly linked-list notes or assignment material
└── PushDListO.txt / trfFelipe.txt   Preserved exercise notes

Fundamentos de computação 3/
├── Prova 2/                          Matrix and numerical-method exercises
└── Prova 4/                          Additional numerical scripts and documents

Tecnicas de programação 2/
├── trab herancamultipla/             Multiple-inheritance exercises and Qt projects
├── trabAgenda/                       Contact-agenda variants and class diagrams
├── trab arquivinho/                  File/persistence and animal projects
├── figurasGeometricas/               Qt geometric-figures project and archive metadata
├── NumRacional*/                     Rational-number exercises and revisions
├── CalcNumCom (1)/                   Complex-number calculator project
├── Ex numero complexo/               Additional complex-number variant
├── Problema de Matriz/               Qt matrix-problem variants
├── exs interface e template/         Interface, template, and calculator exercises
└── heranca/                           Single-inheritance exercises and diagrams
```

The names and nesting above are part of the archive. This curation does not
move or rename coursework directories. It preserves C++ sources and headers,
qmake files, Qt forms, diagrams, PDFs, DOC/PPTX documents, text notes, archive
metadata, and historical IDE files such as `.pro.user`.

## Build and Run

There is no root-level build system, dependency manifest, automated test suite,
or project-wide compile target. Build one selected project at a time after
checking its local project file and expected input or working directory.

### Requirements

- A C++11-capable compiler such as `g++` or a compatible MinGW toolchain.
- `qmake` and a Qt installation for the qmake projects. The GUI assignments
  request Qt Core, Gui, and/or Widgets; console projects may still retain qmake
  metadata even when they do not use the GUI modules.
- MATLAB or GNU Octave for the preserved `.m` scripts. Some scripts use
  Octave-style syntax such as `endfor`, so compatibility should be checked per
  file.

### qmake console project

The AVL simulation can be built from its project directory:

```bash
cd "Estrutura de dados 1/trab avl/Game Physics Felipe Camilo"
qmake untitled.pro
make
./untitled
```

The Mau Mau project follows the same pattern:

```bash
cd "Estrutura de dados 1/trab lista pilha fila/maumau/Nova pasta/untitled"
qmake untitled.pro
make
./untitled
```

Both programs expect positional standard input. Their source does not provide
sample input in the repository, and the exact input protocol is part of the
course assignment. Inspect `main.cpp` before attempting a run.

### Qt Widgets project

For example, the agenda project can be tried with a compatible Qt installation:

```bash
cd "Tecnicas de programação 2/trabAgenda/versaofinal/untitled7"
qmake untitled7.pro
make
./untitled7
```

On systems where the command is versioned, use the installed equivalent such as
`qmake-qt5` or `qmake6`. Qt Creator may better match the historical setup. The
resulting executable name is controlled by the local `.pro` file, and older
projects may need manual adjustments for the installed Qt version.

### Standalone source files

Some exercises can be compiled directly, but most representative projects are
multi-file programs with local headers and GUI forms. For a genuinely
self-contained source, the general pattern is:

```bash
g++ -std=c++11 -O2 path/to/source.cpp -o /tmp/third-semester-example
/tmp/third-semester-example
```

This is a pattern, not a claim that every `.cpp` file is independently
compilable. Prefer the matching `.pro` file when one is present.

## Historical and Academic Limitations

- The archive is a collection of coursework snapshots with no claim of production readiness, security, portability, or complete correctness.
- There is no reproducible root-level build, shared dependency manifest, or automated test coverage.
- Many programs expect positional input, course-provided data, or a particular working directory; those fixtures are not consistently included.
- The qmake projects target a historical Qt/C++11 environment. `.pro.user` files record local IDE state and may not work unchanged on another machine.
- The source includes Portuguese identifiers and console text, inconsistent encoding, platform-specific behavior, and historical implementation choices. This README does not treat those as fixed.
- The archive contains duplicate and intermediate variants, including `maumau2/`, multiple agenda and rational-number folders, repeated matrix projects, and `__MACOSX` extraction metadata. Similar names do not establish a canonical release.
- The numerical scripts are supporting semester material, not C++ projects, and their MATLAB/Octave compatibility must be checked separately.
- Some implementations contain incomplete exercises, rough error handling, or assumptions that have not been audited. Do not infer overall build health from one successful compilation.
- The root `.gitignore` prevents newly generated compiler and Qt build outputs from being added, but it does not remove historical files that are already tracked.

## Cleanup Roadmap

Future maintenance can remain incremental and non-destructive:

1. Inventory each assignment and identify representative versions without deleting coursework or changing directory names.
2. Verify the featured projects individually with documented compiler, qmake, Qt, and input versions.
3. Add small sample input files and per-project run notes where their provenance is clear.
4. Compare duplicate variants and record their differences before marking any path as superseded; retain the originals.
5. Normalize source encoding and user-facing text only in a separate, reviewed change if historical fidelity permits it.
6. Add focused tests or small reproducible build scripts only for explicitly selected teaching examples.
7. Revisit generated IDE metadata and archive extraction artifacts after establishing which historical files are required for provenance.
8. Keep source repairs, behavior changes, moves, renames, and deletions out of documentation-only public-readiness passes unless explicitly requested.

The present curation is intentionally limited to documentation and ignore rules.
It does not rewrite C++ or numerical source, repair exercises, move files,
rename paths, delete coursework, or remove documents and archives.
