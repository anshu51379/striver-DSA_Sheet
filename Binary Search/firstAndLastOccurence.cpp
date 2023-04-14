// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=first-and-last-occurrences-of-x

vector<int> find(int arr[], int n , int x )
{
    // code here
    int flag=0;
    int i=0, j=n-1;
    vector<int> ans, tmp;
    while(i<n){
        if(arr[i]==x){
            ans.push_back(i);
            i+=1;
            flag=1;
            break;
        }else{
            i+=1;
        }
    }
    while(j>0){
        if(arr[j]==x){
            ans.push_back(j);
            flag=1;
            j-=1;
            break;
        }else{
            j-=1;
        }
    }
    sort(ans.begin(), ans.end());
    if(flag){
        return ans;
    }else{
        tmp.push_back(-1);
        tmp.push_back(-1);
        return tmp;
    }
}
