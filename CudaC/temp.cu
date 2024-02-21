
#include<stdio.h>
void helloCPU(){
    printf("Hello from CPU\n");
}

__global__ void helloGPU(){
    printf("Hello from GPU\n");
}

__global__ void add(int a , int b , int *c){
    *c = a + b;
}

int main(){
    // helloCPU();
    // helloGPU<<<1,8>>>();
    // cudaDeviceSynchronize();

    // float *d_A;
    // int n; scanf("%d",&n);
    // int size = n*sizeof(float)*100;
    // cudaMalloc((void**)&d_A,size);
    // cudaFree(d_A);
    
    int a , b, c;
    int *dev_c;
    a=3;
    b=4;
    cudaMalloc((void**)&dev_c,sizeof(int));
    //1024 is the max no. of GPU threads
    //if you want more, increase the no of block count(on the left)
    add<<<1,1024>>>(a,b,dev_c);
    // cudaDeviceSynchronize();
    cudaMemcpy(&c , dev_c , sizeof(int),cudaMemcpyDeviceToHost);
    printf("%d + %d = %d",a,b,c);
    cudaFree(dev_c);
    

    return 0;
}