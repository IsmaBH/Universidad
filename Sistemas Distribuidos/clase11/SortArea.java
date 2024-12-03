import java.util.*;

class SortArea implements Comparator<PoligonoReg>{
	public int compare(PoligonoReg a, PoligonoReg b){
		return (int)Math.round(a.obtieneArea()) - (int)Math.round(b.obtieneArea());
	}
}
