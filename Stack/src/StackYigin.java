
package stack;

public class StackYigin {
   
    int dizi[];
    int size;
    int indis;
    
    public StackYigin(int size){
        
        this.size=size;
        dizi=new int[size];
        indis=-1;
        
    }
    
    void push(int data ){ //ekle
        
     if( isFull()){
         
         System.out.println("stack dolu");
         
     }else{
         indis++;
        dizi[indis]=data;
        System.out.println("push ():"+ dizi[indis]);  
        
    }
    
    }
    int pop(){
        
        
        if( isEmpty()){
            
          return dizi[--indis];
          
        }else{
        
       //indis--;
        System.out.println("stack boş");
     
            return -1;
        }
    }
    
    Boolean isFull(){
        
        return (indis == size-1);
    }
    
    Boolean isEmpty(){
        
        
        return (indis == -1);
    }
}