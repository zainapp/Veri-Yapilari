
package bagliliste;


public class BagliListe {

   
    public static void main(String[] args) {
     
       /* Class node1=new Class();
        Class node2=new Class();
        Class node3=new Class();
        Class node4=new Class();*/
        
     /*   node1.data=11;
        node2.data=23;
        node3.data=30;
        node4.data=45;*/
        
      /*  node1.next=node2;
        node2.next=node3;
        node3.next=node4;
        node4.next=null;*/
        
      /*  Class temp = node1;
        
        while(temp!= null){
            
      
            System.out.println(temp.data);
            temp=temp.next;
            
        }*/
        
        ListeYapisi liste =new ListeYapisi();
     
        liste.ekle(12);
        liste.ekle(22);
        liste.ekle(35);
        liste.yazdir();
           
        
    }
    
}
