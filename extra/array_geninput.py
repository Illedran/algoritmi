from random import shuffle
from numpy.random import randint

length=10000000
with open("input.txt", 'w') as f:
    f.write(str(length)+'\n')
    f.write(' '.join([str(i) for i in randint(-2**31,2**31-1,size=length)]))
