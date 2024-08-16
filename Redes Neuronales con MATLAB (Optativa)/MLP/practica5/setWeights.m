function wk = setWeights(wk,v1,n)
%SETWEIGHTS Esta función inicializa las matrices de pesos de la red
%   Esta función incializa los valores de las matrices de pesos de todas
%   las capas de la red en un rango determinado y devuelve el arreglo de
%   celulas para su uso posterior
%Aqui se crea el espacio para las matrices de pesos
for j = 1:n-1
    wi = zeros(v1(j+1),v1(j));
    wk(j) = mat2cell(wi,v1(j+1),v1(j));
end
%Ahora empezaremos a llenar los valores de wk en el rango de (-3,3)
limSup = 2;
a = -2;
for i = 1:n-1
    aux = cell2mat(wk(i));
    [x,y] = size(aux);
    for j = 1:y
        for k = 1:x
           epsilon = (limSup-a).*rand(1,1) + a;
            aux(k,j) = epsilon; 
        end
    end
    wk(i) = mat2cell(aux,x,y);
end
end

