from random import randint

def quick_sort(arr, left, right):
	if left < right:
		value = arr[randint(left, right)]
		l = left
		r = right
		while l <= r:
			while arr[l] < value:
				l += 1
			while arr[r] > value:
				r -= 1
			if l <= r:
				arr[l], arr[r] = arr[r], arr[l]
				l += 1
				r -= 1
		if (left < r):
			quick_sort(arr, left, r)
		if (right > l):
			quick_sort(arr, l, right)

n = int(input())
arr = list(map(int, input().split()))
quick_sort(arr, 0, n - 1) 
print(*arr)
