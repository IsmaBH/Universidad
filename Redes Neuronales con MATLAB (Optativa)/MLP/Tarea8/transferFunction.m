function a = transferFunction(W,B,P,OPC)
%TRANSFERFUNCTION Funciones de transferencia
%   Aqui se describen las funciones de transferencia que podrian llegar a
%   usar las diferentes capas de la red
%Se empieza por obtener a n
aux1 = W*P;
n = aux1+B;
[x,y] = size(n);
a = zeros(x,y);
%Ahora elegimos por que tipo de funcion se pasara a n
if OPC == 1
    for i = 1:x
        a(i) = 1/(1+exp(-n(i)));
    end
elseif OPC ==2
    a = (exp(n) - exp(-n))/(exp(n) + exp(-n));
else
    a = n;
end
end

