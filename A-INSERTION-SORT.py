def insertionSort(arr):
   for index in range(1,len(arr)):

     currentvalue = arr[index]
     position = index

     while position>0 and arr[position-1]>currentvalue:
         arr[position]=arr[position-1]
         position = position-1

     arr[position]=currentvalue

user_input = input("Input numbers separated a coma:\t").strip()
arr = [int(item) for item in user_input.split(',')]
print("Array before sorting: \t", arr)
insertionSort(arr)
print("Array After sorting: \t", arr)


