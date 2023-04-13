// https://practice.geeksforgeeks.org/problems/largest-element-in-array4009/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-element-in-array

    int largest(vector<int> &arr, int n)
    {
        int max=0;
        for(int i=0; i<n; i+=1){
            if(max<arr[i]){
                max=arr[i];
            }
        }
        return max;
    }
