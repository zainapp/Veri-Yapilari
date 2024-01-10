	/*soldan ilerleyin ve bitiþik elemanlarý karþýlaþtýrýn; daha yüksek olan sað tarafa yerleþtirilir. 
	Bu þekilde ilk önce en büyük eleman en saðdaki uca taþýnýr.
	daha sonra bu iþleme ikinci en büyük olaný bulmak ve yerleþtirmek için devam edilir ve veriler sýralanana kadar  
	bu þekilde devam eder. */
#include<stdio.h>
#define MAX 50

void bubblesort(int arr[],int size){
	
	int i,j,temp;
	
	for(i=0;i<size;i++){
		
		for(j=1;j<size-i;j++){
		
			if(arr[j-1]>arr[j]){
				
				temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			}
		}
	}
}
int main(){
	
	int array[MAX],size,i;
		printf("kac eleman girilecegini giriniz :");
		scanf("%d",&size);
	
	for(i=0;i<size;i++){
		
		printf(" %d.ci elemani giriniz :",i+1);
		scanf("%d",&array[i]);
	}
	bubblesort(array,size);
	
	for(i=0;i<size;i++){
		
		printf("%d ",array[i]);	
	}
	
	return 0;
}
