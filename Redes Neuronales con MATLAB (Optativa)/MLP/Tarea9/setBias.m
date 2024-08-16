function bk = setBias(bk,v1,R,n)
%SETBIAS Función que inicializa los bias de la red
%   Esta función inicializa los bias de toda la red de acuerdo al número de
%   neuronas en cada capa, en un rango determinado
%Aqui se crea el espacio para las matrices de bias
for j = 1:n-1
    bi = zeros(v1(j+1),R);
    bk(j) = mat2cell(bi,v1(j+1),R);
end
%Ahora empezaremos a llenar los valores de bk en el rango de (-1,1)
limSup = 1;
a = -1;
for i = 1:n-1
    aux = cell2mat(bk(i));
    [x,y] = size(aux);
    for j = 1:x
        epsilon = (limSup-a).*rand(1,1) + a;
        aux(j) = epsilon;
    end
    bk(i) = mat2cell(aux,x,y);
end
end

