from random import shuffle

length=20
with open("input.txt", 'w') as f:
    f.write(str(length-1)+'\n')
    nums=range(1,length)
    shuffle(nums)
    f.write(' '.join([str(i) for i in nums]))
