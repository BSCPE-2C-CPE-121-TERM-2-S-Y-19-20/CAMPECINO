def selectionSort(nlist):
   for fillslot in range(len(nlist)-1,0,-1):
       maxpos=0
       for location in range(1,fillslot+1):
           if nlist[location]>nlist[maxpos]:
               maxpos = location

       temp = nlist[fillslot]
       nlist[fillslot] = nlist[maxpos]
       nlist[maxpos] = temp

user_input = input("Input numbers separated a coma:\t").strip()
nlist = [int(item) for item in user_input.split(',')]
print("Array before sorting: \t", nlist)
selectionSort(nlist)
print("Array After sorting: \t", nlist)

