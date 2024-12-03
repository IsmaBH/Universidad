/**
 * Proyecto No.2
 * Autor: Diego Ismael Barón Hernández
 * Grupo: 4CM14
 */
package com.ipn.dsd.proyecto2;

import java.util.*;

class SortDistance implements Comparator<Coordenada>{
        @Override
        public int compare(Coordenada a, Coordenada b){
                return (int)Math.round(a.distancia()) - (int)Math.round(b.distancia());
        }
}
