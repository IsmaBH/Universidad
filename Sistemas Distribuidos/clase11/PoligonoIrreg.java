import java.util.*;
import java.util.List;
import java.util.ArrayList;

public class PoligonoIrreg{
    //Atributos de la clase
    public List<Coordenada> vertices;

    //Constructor de la clase
    public PoligonoIrreg(){
        vertices = new ArrayList<Coordenada>();
    }

    //Metodo para agregar vertices: Permite añadir la coordenada de un vertice del Poligono
    public void anadeVertice(Coordenada vertice){
        vertices.add(vertice);
    }

    //Metodo de ordenamiento de vertices: Permite ordenar los vertices dde acuerdo a su distancia con el origen
    public void ordenaVertices(){
	    Collections.sort(vertices, new SortDistance());
	    System.out.println(vertices);
    }
    
    @Override
    public String toString(){
        String cadena = "Los vertices del poligono son : ";
        for (Coordenada v : vertices) {
            cadena +=  v + " ";
        }
        return cadena;
    }
}
