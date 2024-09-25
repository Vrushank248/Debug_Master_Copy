class MergeSort : 
    def  __init__(self) : 
        self.count = 0

    def merge(self, arr, left, middle, right) :
        arr1 = arr [left:middle + 1] 
        arr2 = arr [middle + 1:right + 1]

        i = j = 0 
        k = left


        while i < len(arr1) and j < len(arr2) : 
            if arr1[i] <= arr2[j] : 
                arr[k] = arr1[i] 
                i+= 1 
                
            else : 
                arr[k] = arr2[j] 
                j += 1 
                self.count += (len(arr1) - i) 
                k+= 1


        while i < len(arr1) : 
            arr[k] = arr1[i] 
            i+= 1 
            k+= 1


        while j < len(arr2) :
            arr[k] = arr2[j] 
            j+= 1 
            k+= 1

                                                               
    def merge_sort(self, arr, left, right) : 
        if left < right : 
            middle = left + (right - left) // 2
            self.merge_sort(arr, left, middle)
            self.merge_sort(arr, middle + 1, right)
            self.merge(arr, left, middle, right)

    def inversion_count(self, arr) : 
        self.count = 0 
        self.merge_sort(arr, 0, len(arr) - 1) 
        return self.count

