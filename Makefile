EXECUTABLE := Lab1
GENERATOR := Ninja
.DEFAULT_GOAL := all
.SILENT: run

all: configure compile run

clear:
	rm -rf ./build

configure:
	cmake -S. -B=build -G=${GENERATOR} -DCMAKE_CXX_COMPILER=clang++

compile:
	cmake --build build -j 8

run:
	echo
	echo ---- PROGRAM OUTPUT: ----
	./build/${EXECUTABLE}
