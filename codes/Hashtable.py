import matplotlib
import numpy as np
import matplotlib.pyplot as plt
from random import choice

class HashTable:
    def __init__(self, h, n=10):
        self.h = h
        self.n = n
        self.bucket = [[] for i in range(n)]

    def insert(self, x):
        self.bucket[self.h(x)].append(x)

    def delete(self, x):
        poss = self.bucket[self.h(x)]
        for i in range(len(poss)):
            if poss[i] == x:
                return poss.pop(i)
        return None

    def find(self, x):
        poss = self.bucket[self.h(x)]
        for i in range(len(poss)):
            if poss[i] == x:
                return poss[i]
        return None

def mi_Mod(x, n=10):
    return x % n

HT = HashTable(mi_Mod, 10)

x = 1234567
y = 76554334234
HT.insert(x)

print(HT.find(x))

def randomFn(x, n=10):
    return choice(range(n))

print(randomFn(52))
print(randomFn(3235235))

HT = HashTable(randomFn, 10)

x = 1234567
y = 76554334234
HT.insert(x)
print(HT.find(x))

print(randomFn(52))
print(randomFn(3235235))
print(randomFn(52))
print(randomFn(3235235))

def RandomHashFun(M, n=10):
    fnTable = [None for i in range(M)]
    for x in range(M):
        fnTable[x] = choice(range(n))

    def randomFn(x):
        return fnTable[x]

    return randomFn

randomFn2 = RandomHashFun(1000, 10)
print(randomFn2(52))
print(randomFn2(324))
print(randomFn2(52))
print(randomFn2(324))

HT = HashTable(randomFn2, 10)
x = 123
y = 76
HT.insert(x)
