void sortColors(vector<int>nums){
    mergeSort(nums,0,nums.size()-1);
    return;
}
void mergeSort(vector<int>& nums, int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
}
void merge(vector<int>& nums, int left, int mid, int right){
    int lSize = mid - left + 1
    int rSize = right - mid;
    vector<int>leftArray(lSize);
    vector<int>rightArray(rSize);
    for(int i = 0; i < lSize; i++){
        leftArray[i] = nums[left + i];
    }
    for(int i = 0; i < rSize; i++){
        rightArray[i]= nums[mid+1+i];
    }
    int ptr1 = 0; 
    int ptr2 = 0; 
    int k = left;
     while (ptr1 < lSize && ptr2 < rSize){
        if(leftArray[ptr1] <= rightArray[ptr2]){
           nums[k] = leftArray[ptr1];
            ptr1++;
        }
        else {
            nums[k] = rightArray[ptr2];
            ptr2++;
        }
        k++;
     }
     while(ptr1<lSize){
        nums[k]= leftArray[ptr1];
        ptr1++;
        k++;
     }
     while(ptr2 < rSize){
        nums[k] = rightArray[ptr2];
        ptr2++;
        k++;
     }
 }