	/*soldan ilerleyin ve biti�ik elemanlar� kar��la�t�r�n; daha y�ksek olan sa� tarafa yerle�tirilir. 
	Bu �ekilde ilk �nce en b�y�k eleman en sa�daki uca ta��n�r.
	daha sonra bu i�leme ikinci en b�y�k olan� bulmak ve yerle�tirmek i�in devam edilir ve veriler s�ralanana kadar  
	bu �ekilde devam eder. */
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
