
import java.util.*;

class MergeSort
{
    long count = 0;

    // Merge two subarrays and count inversions
    void merge(long[] arr, int left, int middle, int right)
    {
        int a1 = middle - left + 1;
        int a2 = right - middle;

        // Create temporary subarrays
        long[] arr1 = new long[a1];
        long[] arr2 = new long[a2];

        // Copy data to temporary arrays
        System.arraycopy(arr, left, arr1, 0, a1);
        System.arraycopy(arr, middle + 1, arr2, 0, a2);

        int i = 0, j = 0, k = left;

        // Merge the two halves and count inversions
        while (i < a1 && j < a2)
        {
            if (arr1[i] <= arr2[j])
            {
                arr[k] = arr1[i];
                i++;
            }
            else
            {
                arr[k] = arr2[j];
                j++;
                count += (a1 - i); // Count inversions
            }
            k++;
        }

        // Copy remaining elements of arr1
        while (i < a1)
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }

        // Copy remaining elements of arr2
        while (j < a2)
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }

    // Recursive divide function
    void mergeSort(long[] arr, int left, int right)
    {
        if (left < right)
        {
            int middle = left + (right - left) / 2;
            mergeSort(arr, left, middle);
            mergeSort(arr, middle + 1, right);
            merge(arr, left, middle, right);
        }
    }

    // Function to count inversions in the array
    long inversionCount(long[] arr)
    {
        count = 0; // Reset count
        mergeSort(arr, 0, arr.length - 1);
        return count;
    }
}

public class CountInversion{
    public static void main(String[] args){
        long[] arr = {5, 3, 2, 4, 1};
        MergeSort ms = new MergeSort();
        System.out.println("Number of inversions: " + ms.inversionCount(arr));
    }
}

