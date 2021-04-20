# encoding=utf8

def partition(a, low, high):
    pv = a[high]
    i = low
    for j in range(low, high):
        if a[j] < pv:
            a[i], a[j] = a[j], a[i]
            i += 1
    a[i], a[high] = a[high], a[i]
    return i

def quickSort(a:list, low, high):
    if low < high:
        p = partition(a, low, high)
        quickSort(a, low, p-1)
        quickSort(a, p+1, high)


a = [12,10,3,899,4,5]
quickSort(a, 0, len(a)-1)
print(a)
