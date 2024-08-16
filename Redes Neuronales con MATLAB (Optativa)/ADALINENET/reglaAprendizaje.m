function [w,b] = reglaAprendizaje(wold,bold,e,alfa,p)
%REGLAAPRENDIZAJE Esta función implementa la regla de aprendizaje
%   Se implementa la regla de aprendizaje para los pesos y bias que estan
%   dados por las ecuaciones:
%   w_i(k+1) = w_i(k) + 2(alfa)(error)p^T
%   b(k+1) = b(k) + 2(alfa)(error)
if bold == 0
    aux1 = alfa*e;
    aux2 = 2*aux1;
    aux3 = aux2*p;
    w = wold + aux3;
    b = 0;
else
    aux1 = alfa*e;
    aux2 = 2*aux1;
    aux3 = aux2*p;
    w = wold + aux3;
    auxb1 = alfa*e;
    auxb2 = auxb1*2;
    b = bold + auxb2;
end
end

