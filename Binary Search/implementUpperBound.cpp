// https://practice.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    pair<int, int> ans;
    int tmp1=-1, tmp2=INT_MAX;
    for(int i=0; i<n; i+=1){
        if(arr[i]<=x and arr[i]>tmp1){
            tmp1=arr[i];
        }
        if(arr[i]>=x and arr[i]<tmp2){
            tmp2=arr[i];
        }
    }
    if(tmp2==INT_MAX){
        tmp2=-1;
    }
    ans.first=tmp1;
    ans.second=tmp2;
    return ans;
}
