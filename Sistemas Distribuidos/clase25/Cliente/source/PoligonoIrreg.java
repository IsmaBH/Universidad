import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class PoligonoIrreg implements java.io.Serializable{

    private List<Coordenada> vertices;
    private int posicionLista;

    public PoligonoIrreg(){
        vertices = new ArrayList<Coordenada>();
        posicionLista = 0;
    }

    public void anadeVertice(Coordenada vertice){
        vertices.add(posicionLista, vertice);
        posicionLista++;
    }

    public void ordenaVertices(){
        Collections.sort(vertices, new SortMagnitud());
    }

    @Override
    public String toString(){
        String cadena = "Los vertices del poligono son : \n";
        for (Coordenada v : vertices) {
            cadena +=  v + "\n";
        }
        return cadena;
    }
}

class SortMagnitud implements Comparator<Coordenada>{
    @Override
    public int compare(Coordenada a, Coordenada b){
        return (int) (a.getMagnitud() - b.getMagnitud());
    }
}