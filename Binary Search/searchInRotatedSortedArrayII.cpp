// https://practice.geeksforgeeks.org/problems/search-in-rotated-array-2/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-rotated-array

    bool Search(int N, vector<int>& A, int Key) {
        // Code here
        for(int i=0; i<N; i+=1){
            if(A[i]==Key){
                return true;
            }
        }
        return false;
    }
