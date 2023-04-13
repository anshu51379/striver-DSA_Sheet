// https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=union-of-two-sorted-arrays

    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> ans;
        // int i=0, j=0;
        // while(i<n and j<m){
        //     if(arr1[i]<arr2[j]){
        //         i+=1;
        //     }else if(arr1[i]>arr2[j]){
        //         j+=1;
        //     }else{
        //         ans.push_back(arr1[i]);
        //         i+=1;
        //         j+=1;
        //     }
        // }
        // return ans;
        set<int> tmp;
        for(int i=0; i<n; i+=1){
            tmp.insert(arr1[i]);
        }
        for(int i=0; i<m; i+=1){
            tmp.insert(arr2[i]);
        }
        for(auto &x:tmp){
            ans.push_back(x);
        }
        return ans;
    }
