function a = transferFunction(w,p,b)
%TRANSFERFUNCTION Se implementa el funcionamiento de ADALINE
%   Se tiene que la funci�n de ADALINE esta dada por la ecuaci�n a =
%   purelin(Wp + b) donde a = n
if b == 0
    a = w*p;
else
    aux = w*p;
    a = aux + b;
end
end

