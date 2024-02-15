
package hashtable;


public class Node {
 
    int key;
    String isim;
    Node next;
    
    public Node(int key,String isim){
        
        this.isim=isim;
        this.key=key;
        
    }
    public Node(){
        next = null;
        
    }
    
    
}
