import java.util.*;

public class Coordenada{

    private double x, y, d;
    
    public Coordenada(double x, double y){
        this.x = x;
        this.y = y;
	this.d = Math.sqrt(Math.pow((x - 400),2) + Math.pow((y - 300),2));
    }
    
    public double abcisa(){
        return x;
    }
    
    public double ordenada(){
        return y;
    }

    public double distancia(){
	    return d;
    }
    
    @Override
    public String toString(){
        return "[" + x + "," + y + "]";
    }
}
