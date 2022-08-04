def merge(arr1, arr2):
    i,j=0,0
    mergedarr = []
    while i<len(arr1) and j<len(arr2):
        if arr1[i]<arr2[j]:
            mergedarr.append(arr1[i])
            i+=1
        else:
            mergedarr.append(arr2[j])
            j+=1


    mergedarr.extend(arr1[i:])
    mergedarr.extend(arr2[j:])
    

    return mergedarr


def divide(arr):
    if len(arr)<=1:
        return arr
    else:

        mid = len(arr)//2
        
        left = divide(arr[0:mid])
        right = divide(arr[mid:])

        sorted_arr = merge(left, right)

        return sorted_arr



arr = [45 , 16,1,6, 64, 9, 16,1, 94,-16, -19 ]
print(divide(arr))