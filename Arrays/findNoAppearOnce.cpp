// https://practice.geeksforgeeks.org/problems/element-appearing-once2552/0?company[]=Qualcomm&company[]=Qualcomm&difficulty[]=1&page=1&query=company[]Qualcommdifficulty[]1page1company[]Qualcomm&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=element-appearing-once

  int search(int A[], int N){
	    //code
	    unordered_map<int, int> tmp;
	    for(int i=0; i<N; i+=1){
	        tmp[A[i]]+=1;
	    }
	    for(int i=0; i<N; i+=1){
	        if(tmp[A[i]]==1){
	            return A[i];
	        }
	    }
	    return -1;
	}
