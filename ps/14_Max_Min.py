def maxMin(arr, k):
    # Write your code here
    arr.sort()
    unfairness = []
    p1 = 0
    p2 = k - 1
    
    while p2 < len(arr):
        unfairness.append(arr[p2] - arr[p1])
        p1 += 1
        p2 += 1
    return min(unfairness)
n = int(input())
k = int(input())
arr = []
for i in range(n):
    num = int(input())
    arr.append(num)
    
print(maxMin(arr,k))