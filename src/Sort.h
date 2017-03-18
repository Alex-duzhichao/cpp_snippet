#ifndef CPP_SNIPPET_SRC_SORT_H_
#define CPP_SNIPPET_SRC_SORT_H_
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void printVec(const vector<T> &vec)
{
    cout << endl;

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << "  ";
    }

    cout << endl;
}

template<typename T>
inline void BubbleSort(vector<T> &vec)
{
    for (int i = vec.size() - 1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            if(vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

template<typename T>
inline void SelectSort(vector<T> &vec)
{
    for (int i = vec.size() - 1; i >= 0; --i) {
        int maxIndex = i;

        for (int j = 0; j < i; ++j) {
            if(vec[j] > vec[maxIndex]) {
                maxIndex = j;
            }
        }

        swap(vec[i], vec[maxIndex]);
    }
}

template<typename T>
inline void InsertSort(vector<T> &vec)
{
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if(vec[j] > vec[i]) {
                T temp = vec[i];
                copy(&vec[j], &vec[i], &vec[j + 1]);
                vec[j] = temp;
                break;
            }
        }
    }
}

#if 0
template<typename T>
inline void ShellBubbleSort(vector<T> &vec)
{
    for (int gap = vec.size() / 2; gap >= 1; gap /= 2) {
        for (int i = vec.size() - 1; i >= 0; --i) {
            for (int j = 0; j < i; j += gap) {
                if(vec[j] > vec[j + gap]) {
                    swap(vec[j], vec[j + gap]);
                }
            }
        }
    }
}

template<typename T>
inline void ShellSelectSort(vector<T> &vec)
{
    for (int gap = vec.size() / 2; gap >= 1; gap /= 2) {
        for (int i = 0; i < vec.size(); ++i) {
            int minIndex = i;

            for (int j = i; j < vec.size(); j += gap) {
                if(vec[j] < vec[minIndex]) {
                    minIndex = j;
                }
            }

            swap(vec[i], vec[minIndex]);
        }
    }
}

template<typename T>
inline void ShellInsertSort(vector<T> &vec)
{
    for (int gap = vec.size() / 2; gap >= 1; gap /= 2) {
        for (int i = 0; i < vec.size(); ++i) {
            for (int j = 0; j < i; j += gap) {
                if(vec[j] > vec[i]) {
                    T temp = vec[i];

                    for (int x = i; x > j; x -= gap) {
                        vec[x] = vec[x - gap];
                    }

                    vec[j] = temp;
                    break;
                }
            }
        }
    }
}

#endif

template<typename T>
int ShellSort(vector<T> &vec)
{
    // Start with a big gap, then reduce the gap
    for (int gap = vec.size() / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire vecay is
        // gap sorted
        for (int i = gap; i < vec.size(); i += 1) {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            T temp = vec[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;

            for (j = i; j >= gap && vec[j - gap] > temp; j -= gap) {
                vec[j] = vec[j - gap];
            }

            //  put temp (the original a[i]) in its correct location
            vec[j] = temp;
        }
    }

    return 0;
}

class Heap
{
public:
    void insert(int val)
    {
        m_vec.push_back(val);

        for (int n = m_vec.size() - 1; n > 0; n = (n - 1) / 2) {
            if(m_vec[n] < m_vec[(n - 1) / 2]) {
                break;
            }

            swap(m_vec[n], m_vec[(n - 1) / 2]);
        }
    }

    int getMin()
    {
        return m_vec[0];
    }

    int extractMin()
    {
        int max = m_vec[0];
        m_vec[0] = m_vec[m_vec.size() - 1];
        m_vec.pop_back();

        for (int n = 0; static_cast<vector<int>::size_type>((2 * (n + 1))) < m_vec.size();) {
            int left = m_vec[2 * n + 1];
            int right = m_vec[2 * (n + 1)];

            if(m_vec[n] >= left && m_vec[n] >= right) {
                break;
            }

            if(left > right) {
                swap(m_vec[2 * n + 1], m_vec[n]);
                n = 2 * n + 1;
            } else {
                swap(m_vec[2 * (n + 1)], m_vec[n]);
                n = 2 * (n + 1);
            }
        }

        return max;
    }
    vector<int> m_vec;
}; // class Heap

// To heapify a subtree rooted with node i which is
// an index in vec[]. n is size of heap
void heapify(vector<int> &vec, int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && vec[l] > vec[largest]) {
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < n && vec[r] > vec[largest]) {
        largest = r;
    }

    // If largest is not root
    if (largest != i) {
        swap(vec[i], vec[largest]);

        // Recursively heapify the affected sub-tree
        heapify(vec, n, largest);
    }
}

// main function to do heap sort
void HeapSort(vector<int> &vec)
{
    int n = vec.size();

    // Build heap (revecange vecay)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(vec, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(vec[0], vec[i]);

        // call max heapify on the reduced heap
        heapify(vec, i, 0);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int arr1[m - l + 1];
    int arr2[r - m];

    for(int n = l, i = 0; n <= m; ++n, ++i) {
        arr1[i] = arr[n];
    }

    for(int n = m + 1, i = 0; n <= r; ++n, ++i) {
        arr2[i] = arr[n];
    }

    int n = l;
    int i = 0, j = 0;

    while(i < m - l + 1 && j < r - m) {
        if(arr1[i] < arr2[j]) {
            arr[n++] = arr1[i++];
        } else {
            arr[n++] = arr2[j++];
        }
    }

    while(i < m - l + 1) {
        arr[n++] = arr1[i++];
    }

    while(j < r - m) {
        arr[n++] = arr2[j++];
    }
}

void MergeSort(int arr[], int begin, int end)
{
    if(begin < end) {
        int middle = begin + (end - begin) / 2;
        MergeSort(arr, begin, middle);
        MergeSort(arr, middle + 1, end);
        merge(arr, begin, middle, end);
    }
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void QuickSort(int arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}
#endif /* CPP_SNIPPET_SRC_SORT_H_ */
