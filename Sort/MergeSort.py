def merge_sort(arr, n):
    if len(arr) <= 1:
        return arr
    middle = n // 2
    left = merge_sort(arr[:middle], len(arr[:middle]))
    right = merge_sort(arr[middle:], len(arr[middle:]))
    return merge(left, right)

def merge(left, right):
    result = []
    i, j = 0, 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])
    return result

n = int(input())
arr = list(map(int, input().split()))
arr = merge_sort(arr, n)
print(*arr)