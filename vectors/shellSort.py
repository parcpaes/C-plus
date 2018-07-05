import random
def shellSort(array):
    n = len(array)
    gap = n/2
    while gap > 0:
        for i in range(gap,n):
            temp = array[i]
            j = i
            while  j >= gap and array[j-gap] >temp:
                array[j] = array[j-gap]
                j -= gap
            array[j] = temp
        gap /= 2
        
        
array = []
for i in range(0,1000000):
	array.append(random.randint(1,1000000));

shellSort(array)
print(array[0])
