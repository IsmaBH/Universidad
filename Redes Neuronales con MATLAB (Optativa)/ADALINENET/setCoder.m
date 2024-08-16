function dS = setCoder(n)
%SETCODER Esta función crea el dataset para el modo regresor
%   creara la tabla de verdad para un codificador de n-bits
rows = 2^n;
cols = n + 1;
%Inicializamos la matriz en 0's
dS = zeros(rows,cols);
for i = 1:n
    bit = 0;
    for j = 1:2^n
    %Asignacion para la tabla de verdad
    dS(j,i) = bit;
    %Determina cada cuando debe cambiar el bit
    if (mod(j,rows/2^(i)) == 0)
       if (bit == 0)
          bit = 1;
       else
          bit = 0;
       end
    end
    end
end
count = 0;
for j = 1:rows
    dS(j,cols) = count;
    count = count + 1;
end
end