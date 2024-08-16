function a = transferFunction(W,B,P,func)
%TRANSFERFUNCTION Esta funcion implementa ecuaciones de propagacion
%hacia adelante
aux1 = W*P;
n = aux1+B;
[x,y] = size(n);
a = zeros(x,y);
switch func
    case 1
        a = n;
    case 2
        for i = 1:x
            a(i) = 1/(1+exp(-n(i)));
        end
    case 3
        for i = 1:x
            a(i) = (exp(n(i)) - exp(-n(i)))/(exp(n(i)) + exp(-n(i)));
        end
end
end

