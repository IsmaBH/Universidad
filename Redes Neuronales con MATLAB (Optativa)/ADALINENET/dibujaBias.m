function dibujaBias(b,epoch)
%DIBUJABIAS Evolucion de los bias
%   Esta funci�n dibuja la evolucion de los bias a lo largo de las epocas
[m,n] = size(b);
title('Evoluci�n de los bias')
for i = 1:m
    plot(epoch,b(i,n),'g*')
end
end

