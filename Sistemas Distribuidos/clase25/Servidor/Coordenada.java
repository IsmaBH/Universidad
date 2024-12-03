public class Coordenada implements java.io.Serializable{

    private double x, y;
    private double magnitud;
    
    public Coordenada(double x, double y){
        this.x = x;
        this.y = y;
        magnitud = Math.round(Math.sqrt((y*y)+(x*x))*1000d)/1000d;
    }
    
    public double abcisa(){
        return x;
    }
    
    public double ordenada(){
        return y;
    }
    
    public double getMagnitud(){
        return magnitud;
    }
    
    @Override
    public String toString(){
        return "[" + x + "," + y + "], Magnitud : " + magnitud;
    }
}