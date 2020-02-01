def heapify(nums, index, heap_size):
    largest_num = index
    left_index = 2 * index + 1
    right_index = 2 * index + 2
    if left_index < heap_size and nums[left_index] > nums[largest_num]:
        largest_num = left_index

    if right_index < heap_size and nums[right_index] > nums[largest_num]:
        largest_num = right_index
    if largest_num != index:
        nums[largest_num], nums[index] = nums[index], nums[largest_num]
        heapify(nums, largest_num, heap_size)
        
def heapSort(nums):
    n = len(nums)
    for i in range(n // 2 - 1, -1, -1):
        heapify(nums, i, n)
    for i in range(n - 1, 0, -1):
        nums[0], nums[i] = nums[i], nums[0]
        heapify(nums, 0, i)
    return nums
    
nums= [20, 16, 5, 9, 2, 12, 4, 10]
print (nums, "\n")
heapSort(nums)
print("Sorted array is ", nums)
