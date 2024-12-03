import java.util.*;

class SortDistance implements Comparator<Coordenada>{
	public int compare(Coordenada a, Coordenada b){
		return (int)Math.round(a.distancia()) - (int)Math.round(b.distancia());
	}
}
