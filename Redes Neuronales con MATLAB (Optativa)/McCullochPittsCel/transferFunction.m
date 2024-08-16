function [cellOutput, umbralizedOutput] = transferFunction(inputs,weights,umbral)
%TRANSFERFUNCTION Esta funcion realiza las operaciones de la celula
%   Esta funcion obedece a la exprecion matematica: n = Suma(Wi*Pi)
% Realizamos la multiplicacion de matrices
cellOutput = inputs * weights;    
% Determinamos el valor de la salida con relacion al umbral
if(cellOutput > umbral)
    umbralizedOutput = 1;
else
    umbralizedOutput = 0;
end
end

