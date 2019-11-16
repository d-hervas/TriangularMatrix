# TriangularMatrix
(Forked from https://github.com/fylux/TriangularMatrix)

This is a shamelessly simple, minimalistic, memory efficient implementation of a triangular matrix in C++.

## What is/Why use a triangular matrix?
[The author of the original TMatrix class can explain it better than I do.](https://fylux.github.io/2017/03/07/Symmetric-Triangular-Matrix/)

## Why this triangular matrix?
Surprisingly enough, to my knowledge, there are no other simple and modern triangular matrix implementations apart from this one. The usual C++ solve-it-all library, Boost, ties a really, really old, confusing and bloated matrix implementation to the whole uBLAS module. [The page itself strongly suggests you shouldn't use the library because it's outdated](https://www.boost.org/doc/libs/1_71_0/libs/numeric/ublas/doc/index.html), and that was written in 2012 (!). Other symmetrical matrix implementations suffer from similar problems: they're either vastly outdated, bloated with whole linear algebra libraries you have to drag to your project even though you're never gonna use, or are outright not optimized and will take the space of a whole matrix.

## What does this fork add?
The biggest difference between this version and fylux's one is that the static C-style arrays have been replaced by the more flexible C++ templated vectors. This means it's now possible to create extremely big, dynamic matrices (as big as your computer's memory, really) without blowing up the heap when trying to allocate memory.
It also adds a few optimization tricks, a more modern syntax, and some useful methods (i.e you can pre-allocate memory before filling your matrix in case you want it to have a fixed size). 

The code is probably not the cleanest, but it's simple enough that it should be self-explanatory.

## Hey, wouldn't it be cool if you added the bracket operat...
[Nope, ](https://isocpp.org/wiki/faq/operator-overloading#matrix-subscript-op) [it's really](https://isocpp.org/wiki/faq/operator-overloading#matrix-array-of-array) [ not worth it.](https://isocpp.org/wiki/faq/operator-overloading#matrix-c-style-subscript)**

TLDR: It's really messy to implement and even if you get it to work, it'll very likely be slower than using the getter/setter. Don't bother. Trust me, it's not like I tried to do it or anything, and when I got it to work it really was slower and the class had doubled in lines of code, haha. It would've been funny if that had been the case though, right? Haha.