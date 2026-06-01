# The Forge — LPC Exercises for 3Kingdoms

A hands-on coding curriculum for learning LPC programming on
[3Kingdoms MUD](http://3k.org). Each chapter pairs with a section of the
[3K Code Primer](https://3k.org/resources/primer/), giving you
practical exercises to reinforce every concept you read about.

Work through 21 chapters, 56 exercises, and a capstone project that takes
you from "Hello Mud" to building a complete dungeon area.

## Getting Started

1. **Download this repository** — click the green **Code** button above and
   choose **Download ZIP**, or clone with git:
   ```
   git clone https://github.com/locrian3k/the-forge.git
   ```
2. **Open the lessons** — open `web/index.html` in your browser. This is your
   home page with navigation to every chapter.
3. **Read a chapter** in the browser, then open the matching exercise starter
   file in your text editor and fill in the TODOs.
4. **Compare your work** against the solution files when you are done.

No MUD access, compiler, or special tools are needed. Just a browser and a
text editor.

## Repository Layout

```
the-forge/
  web/                    Lesson pages (open index.html in your browser)
    index.html            Home page with chapter grid
    style.css             Dark theme stylesheet
    exercises.js          Progress tracker (saves in your browser)
    chapters/             One HTML page per chapter (0-21)
  exercises/              Starter files with TODOs for you to complete
    ch01_intro/           Chapter 1 exercises
    ch02_types/           Chapter 2 exercises
    ...                   (ch03 through ch21)
  solutions/              Fully commented reference implementations
    ch01_intro/           Chapter 1 solutions
    ch02_types/           Chapter 2 solutions
    ...                   (ch03 through ch21)
  reference/              Quick-reference cheatsheets
    cheatsheet-types.md   One per major topic
    glossary.md           MUD and LPC terminology
  capstone/               Final project templates
    README.md             Capstone overview and phases
    standard/             Standard room track
    dungeon/              3K dungeon room track
    phases/               Phase-by-phase guidance
```

## Curriculum Overview

### Language Basics (Chapters 1-10)
| Chapter | Topic | Exercises |
|---------|-------|-----------|
| 0 | The Big Picture | — |
| 1 | Introduction | 2 |
| 2 | Types | 2 |
| 3 | Variables | 2 |
| 4 | Operators | 3 |
| 5 | Mappings & Arrays | 2 |
| 6 | Functions | 3 |
| 7 | Control Structures | 3 |
| 8 | Modifiers | 2 |
| 9 | Preprocessor | 2 |
| 10 | Inheritance | 3 |

### Building Blocks (Chapters 11-14)
| Chapter | Topic | Exercises |
|---------|-------|-----------|
| 11 | Code Style | 2 |
| 12 | Driver Functions | 3 |
| 13 | Rooms | 4 |
| 14 | Objects | 2 |

### Game Systems (Chapters 15-19)
| Chapter | Topic | Exercises |
|---------|-------|-----------|
| 15 | Weapons | 2 |
| 16 | Armor | 2 |
| 17 | Monsters | 3 |
| 18 | Putting It Together | 4 |
| 19 | Advanced Topics | 4 |

### 3K Extensions (Chapters 20-21)
| Chapter | Topic | Exercises |
|---------|-------|-----------|
| 20 | Dungeon Rooms | 3 |
| 21 | Dungeon Integration | 3 |

## Two Learning Tracks

Every exercise is tagged as one of two difficulty tiers:

- **Apprentice** — Core exercises covering fundamentals. Start here if you are
  new to LPC or programming in general.
- **Journeyman** — Deeper challenges that combine multiple concepts, debug
  existing code, or tackle real-world MUD patterns.

You can do just one track or both.

## How to Use This Curriculum

1. **Read the primer chapter** — each lesson page links to the corresponding
   section of the [3K Code Primer](https://3k.org/resources/primer/).
2. **Read the lesson page** — open the chapter in `web/chapters/` for concept
   recaps, detailed requirements, and hints.
3. **Write your code** — open the matching starter file from `exercises/` in
   your text editor. Follow the TODO comments.
4. **Check your work** — compare against the solution in `solutions/`. The
   solutions are heavily commented to explain the reasoning.
5. **Track your progress** — use the checkboxes on each lesson page. Your
   progress is saved in your browser's local storage.

## The Capstone Project

The curriculum culminates in a multi-phase capstone where you build a complete
dungeon area for 3Kingdoms:

| Phase | Name | After Chapters | What You Build |
|-------|------|----------------|----------------|
| 1 | The Foundation | 1-9 | defs.h, entrance, base room, layout |
| 2 | Atmosphere | 10-14 | Items, searches, readables |
| 3 | Combat | 15-17 | Monsters, weapons, armor |
| 4 | The Boss | 18-19 | Boss fight, unique drop, mechanics |
| 5 | Polish | All | Integration, disease, paths, testing |

Templates and phase guides are in the `capstone/` directory.

## In-Game Validation

When you become a wizard on 3Kingdoms, you will be able to upload your exercises
to the MUD and test them live. Until then, compare your code against the
solutions provided in the `solutions/` directory.

## Reference Materials

The `reference/` directory contains quick-reference cheatsheets for every major
topic, plus a glossary of MUD and LPC terminology. These are designed to be
looked up while you work, not read front to back.

## Contributing

Found a bug in an exercise or solution? Have an idea for a new exercise?
Open an issue or pull request.

## License

This curriculum is released under the MIT License. See [LICENSE](LICENSE) for
details.
