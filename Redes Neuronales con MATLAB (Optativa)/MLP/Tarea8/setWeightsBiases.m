function [w,b] = setWeightsBiases(neurons,input,capa)
%SETWEIGHTSBIASES Obtiene una matriz de pesos y bias
%   Esta función obtiene los pesos y bias de una capa
%Se empieza creando la matriz de pesos
%Apartamos el espacio de la matriz
w = zeros(neurons,input);
if capa == 1
    for i = 1:neurons
        w(i,1) = 10;
    end
else
    for i = 1:input
        w(1,i) = 1;
    end
end
%Ahora obtendremos los bias
if capa == 1
    b = zeros(neurons,input);
    for i = 1:neurons
        b(i,1) = -10;
    end
else
    inputs = input/input;
    b = zeros(neurons,inputs);
    for i = 1:neurons
        b(i,1) = 0;
    end
end
end

