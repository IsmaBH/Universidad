function tabV = tabla_de_verdad(op,n)
%TABLA_DE_VERDAD funcion que recibe un tipo de compuerta y su dimension
%   Con los datos de entrada va a generar una matriz que sera el conjunto
%   de entranamiento
rows = 2^n;
cols = n+1;
%Si la opcion fue 1 tendremos una tabla estatica para la compuerta
%NOT ya que esta es sencilla si 1 en la entrada 0 a la salida y
%viceversa
if op == 1
    tnot = zeros(2,2);
    tnot(2,1) = 1;
    tnot(1,2) = 1;
    tabV = tnot;
else
    %En caso de ser 2 o 3 debe prepararse una tabla diferente
    %Inicializamos la matriz en 0's
    z = zeros(rows,cols);
    for i = 1:n
        bit = 0;
        for j = 1:2^n
            %Asignacion para la tabla de verdad
            z(j,i) = bit;
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
    if op == 2
        z(rows,cols) = 1;
        tabV = z;
    else
        z(2:end,cols) = 1;
        tabV = z;
    end
end
end