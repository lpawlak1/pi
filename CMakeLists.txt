cmake_minimum_required(VERSION 3.16)
project(pi C)

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -lm")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -lm")
endif()
set(CMAKE_C_STANDARD 11)

link_libraries(m)
add_executable(st c1/stopnie.c)
add_executable(za c1/przyjazn.c)
add_executable(do c1/doskonale.c)

add_executable(perf c2/perf.c)
add_executable(primes c2/primes.c)
add_executable(fibo c2/fibo.c)

add_executable(half c3/half.c)
add_executable(narc c3/narc.c)
add_executable(weight c3/weight.c)

add_executable(min c4/min.c)
#add_executable(pair c4/pair.c)
add_executable(pri c4/pri.c)

add_executable(fact c5/fact.c)
add_executable(merge c5/merge.c)
add_executable(neigh c5/neigh.c)

add_executable(field c6/field.c)
add_executable(spiral c6/spiral.c)
add_executable(square c6/square.c)

add_executable(rec c7/rec.c)
add_executable(rom c7/rom.c)
add_executable(tri c7/tri.c)

add_executable(stamp c8/stamp.c)
add_executable(seq c8/seq.c)
add_executable(bin c8/bin.c)

add_executable(main main.c)
