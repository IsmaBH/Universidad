function res = transferFunction(p,W,b)
%TRANSFERFUNCTION a = hardlim(W*p+b)
%   esta funcion implementa el modelo de hardlim para el perceptron
aux = W * p;
auxA = aux + b;
rows = size(auxA,1);
tam = size(auxA);
res = zeros(tam);
for i = 1:rows
    if auxA(i) >= 0
        res(i) = 1;
    else
        res(i) = 0;
    end
end
end

