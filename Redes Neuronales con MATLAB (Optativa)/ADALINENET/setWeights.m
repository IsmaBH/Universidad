function w = setWeights(cols)
%SETWEIGHTS Obtiene una matriz de pesos valida
%   La matriz de pesos debe cumplir que sea de tamaño 1xR y ademas sus
%   valores deben oscilar entre 1 y -1
limSup = 1;
a = -1;
w = zeros(1,cols);
for i = 1:cols
    epsilon = (limSup-a).*rand(1,1) + a;
    w(i) = epsilon;
end
end