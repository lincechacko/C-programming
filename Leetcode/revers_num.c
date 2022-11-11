int reverse(long int x){
int temp,temp1=x;

long int sum=0;

if(x<0){
    x=-x;
}

while(x>0){

    temp=x%10;
    sum=(sum*10)+temp;
    x=x/10;
}

  if(sum < -2147483648 || sum > 2147483647){
    return 0;
  }    
if(temp1<0){
    sum=-sum;
    return sum;
  
}
else {
    return sum;
}
}
