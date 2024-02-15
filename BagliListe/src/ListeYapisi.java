
package bagliliste;


public class ListeYapisi {
    
    Class head = null;
    Class tail = null;
    
    void ekle(int x){
        
        Class eleman=new Class();
        eleman.data=x;
        eleman.next=null;
        
        if( head== null){
            
            head = eleman;
            tail = eleman;
            System.out.println("liste olusturuldu ve ilk dugum eklendi ");
            
        }else{
            
         tail.next=eleman;
         tail=eleman;
         System.out.println("listenin sonuna yeni bir eleman eklendi");
        }
        
        
    }
    void yazdir(){
        
        if(head==null){
            
            System.out.println("liste boş");
            
        }else{
            
            Class temp = head;
            while( temp != null){
                
                
                System.out.println(temp.data);
                temp = temp.next;
            }
            
        }
    }
    
}
