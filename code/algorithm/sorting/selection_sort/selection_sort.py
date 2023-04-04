def find_smallest(arr):
    smallest = arr [0]
    smallest_index = 0
    for ii in range(1, len(arr)):
        if arr[ii] < smallest:
            smallest = arr[ii]
            smallest_index = ii
    return smallest_index

def selection_sort(arr):
    sort_arr = []
    for ii in range(len(arr)):
        smallest = find_smallest(arr)
        sort_arr.append(arr.pop(smallest))
    return sort_arr

print (selection_sort( [5, 3, 6, 2, 10] ))
