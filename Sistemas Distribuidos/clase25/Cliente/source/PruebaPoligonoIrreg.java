import java.util.Random;

public class PruebaPoligonoIrreg{

    public static void main (String[] args){

        Random rnd = new Random();
        
        Coordenada c1 = new Coordenada(rnd.nextInt(201)-100, rnd.nextInt(201)-100);
        Coordenada c2 = new Coordenada(rnd.nextInt(201)-100, rnd.nextInt(201)-100);
        Coordenada c3 = new Coordenada(rnd.nextInt(201)-100, rnd.nextInt(201)-100);
        Coordenada c4 = new Coordenada(rnd.nextInt(201)-100, rnd.nextInt(201)-100);
        Coordenada c5 = new Coordenada(rnd.nextInt(201)-100, rnd.nextInt(201)-100);
        Coordenada c6 = new Coordenada(rnd.nextInt(201)-100, rnd.nextInt(201)-100);
        Coordenada c7 = new Coordenada(rnd.nextInt(201)-100, rnd.nextInt(201)-100);
        Coordenada c8 = new Coordenada(rnd.nextInt(201)-100, rnd.nextInt(201)-100);
        Coordenada c9 = new Coordenada(rnd.nextInt(201)-100, rnd.nextInt(201)-100);
        Coordenada c10 = new Coordenada(rnd.nextInt(201)-100, rnd.nextInt(201)-100);

        PoligonoIrreg poligono = new PoligonoIrreg();

        poligono.anadeVertice(c1);
        poligono.anadeVertice(c2);
        poligono.anadeVertice(c3);
        poligono.anadeVertice(c4);
        poligono.anadeVertice(c5);
        poligono.anadeVertice(c6);
        poligono.anadeVertice(c7);
        poligono.anadeVertice(c8);
        poligono.anadeVertice(c9);
        poligono.anadeVertice(c10);

        System.out.println("\nVertices desordenados\n\n" + poligono + "\n");

        poligono.ordenaVertices();

        System.out.println("Vertices ordenados\n\n" + poligono + "\n");
    }
}