int singleNumber(int* nums, int numsSize){
int unq,flag=0;
for(int i=0;i<numsSize;i++){
    for(int j=0;j<numsSize;j++){
        if(nums[i]==nums[j] && i!=j){
            flag=1;
            break;
        }
        else{
            flag=0;
 
       }
        
    }
    if(flag==0){
     unq=nums[i];
    }
    
}
return unq;
}
