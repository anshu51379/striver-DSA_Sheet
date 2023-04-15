// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array

    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int> tmp;
        for(int i=0; i<n; i+=1){
            tmp.push_back(arr1[i]);
        }
        for(int i=0; i<m; i+=1){
            tmp.push_back(arr2[i]);
        }
        sort(tmp.begin(), tmp.end());
        return tmp[k-1];
    }
