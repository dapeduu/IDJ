# IDJ

## Setup

You must have homebrew installed, to install the dependencies, bear and pkg-config are also required for building and ide support. 

Then run `brew bundle` to install the dependencies.

## Build

`make debug` or `make release` to build the project.

On the first time, run `bear -- make debug|release` to generate the compile_commands.json file for better ide support. 

## Run

`./JOGO`

## Observations

The makefile was modified so that on macos we prefer getting the libraries from pkg config, instead of framework, so we can just brew install everything.