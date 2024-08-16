public class listaDoble{
    private Node tail;
    private Node head;

    public listaDoble(){}
    public listaDoble(Node e){
        tail = e;
        head = e;
    }
 
    public void addLast(Integer x,Integer y) {
        Node node = new Node(x,y);
        if (tail == null && head == null) {
            tail = node;
            head = node;
        } else {
            tail.setNextElement(node);
            node.setPreviousElement(tail);
            tail = node;
        }
    }
 
    public void addFirst(Integer x,Integer y) {
        Node node = new Node(x,y);
        if (tail == null && head == null) {
            tail = node;
            head = node;
        } else {
            node.setNextElement(head);
            head.setPreviousElement(node);
            head = node;
        }
    }
    public boolean find(int x,int y) {
        boolean c = false;
        for (Node i = head; i != null; i = i.getNextElement()) {
            if (i.getValueX() == x && i.getValueY() == y) {
                c = true;
                break;
            }else{
                c = false;
            }
        }
        return c;
    }
    public void print() {
        for (Node i = head; i != null; i = i.getNextElement()) {
            System.out.printf("\t %s ", i.toString());
        }
        System.out.println();
    }
}
class Node {
    private int coorX;
    private int coorY;
    private Node nextElement;
    private Node previousElement;
 
    public Node(int x,int y) {
        this.coorX = x;
        this.coorY = y;
    }
 
    public Integer getValueX() {
        return coorX;
    }

    public Integer getValueY() {
        return coorY;
    }

    public void setValueX(Integer value) {
        this.coorX = value;
    }

    public void setValueY(Integer value) {
        this.coorY = value;
    }
 
    public Node getNextElement() {
        return nextElement;
    }
 
    public void setNextElement(Node nextElement) {
        this.nextElement = nextElement;
    }
 
    public Node getPreviousElement() {
        return previousElement;
    }
 
    public void setPreviousElement(Node previousElement) {
        this.previousElement = previousElement;
    }
    @Override
    public String toString() {
        return "Node [values= " +coorX+","+coorY+"]";
    }
}