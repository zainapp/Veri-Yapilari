
package hashtable;


public class Tablo {
  
    Node dizi[];
    int size;
    
    public Tablo(int size){
        
        this.size=size;
      dizi = new Node[size]; 
      
      for(int i=0 ; i<size ; i++){
          
          dizi[i]=new Node();    
      }
    } 
      int indexUret(int key){
        
       
        return key % size ;
        
    }
      
       void Ekle(int key, String isim){
        
        int index= indexUret(key);
        
        Node eleman=new Node(key,isim);
        
        Node temp = dizi[index];
     
        while(temp.next!=null){ //ilgili bağlı listenin sonuna ekleme yaptı
    
        temp=temp.next;
        
        temp.next=eleman; 
        }
        
       System.out.println(eleman.isim +"eklendi");
 
    }
         
    }
       
    
            
    
    
