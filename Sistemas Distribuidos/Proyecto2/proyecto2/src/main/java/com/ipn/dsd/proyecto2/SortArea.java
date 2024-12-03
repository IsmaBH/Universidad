/**
 * Proyecto No.2
 * Autor: Diego Ismael Barón Hernández
 * Grupo: 4CM14
 */
package com.ipn.dsd.proyecto2;

import java.util.*;

class SortArea implements Comparator<PoligonoReg>{
        @Override
        public int compare(PoligonoReg a, PoligonoReg b){
                return (int)Math.round(a.obtieneArea()) - (int)Math.round(b.obtieneArea());
        }
}