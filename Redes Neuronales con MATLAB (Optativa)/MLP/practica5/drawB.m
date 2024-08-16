function drawB(b,epoch)
%DRAWB Evolucion de los bias
%   Esta función dibuja la evolucion de los bias a lo largo de las epocas
[m,n] = size(b);
%title('Evolución de los bias')
for i = 1:m
    plot(epoch,b(i,n),'g*')
end
end

