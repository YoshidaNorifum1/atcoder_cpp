#!/usr/bin/zsh

mkdir $1
cd $1
mkdir a
mkdir b
mkdir c
mkdir d
mkdir e
mkdir f

touch ./a/main.cpp
touch ./b/main.cpp
touch ./c/main.cpp
touch ./d/main.cpp
touch ./e/main.cpp
touch ./f/main.cpp

cat ../source.txt > ./a/main.cpp
cat ../source.txt > ./b/main.cpp
cat ../source.txt > ./c/main.cpp
cat ../source.txt > ./d/main.cpp
cat ../source.txt > ./e/main.cpp
cat ../source.txt > ./f/main.cpp
