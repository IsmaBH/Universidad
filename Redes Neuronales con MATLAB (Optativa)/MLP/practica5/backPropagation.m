function [wk,bk,out,eaux] = backPropagation(wk,bk,G,v1,v2,a0,alfa,out,n,eaux)
%BACKPROPAGATION Implementación del algoritmo de backpropagation
%   En esta función se implementa todo el proceso de backpropagation con la
%   modificación de pesos,bias y error en cada iteración.
[~,colP] = size(a0);
for i = 1:colP
    out(1) = num2cell(a0(i));
    auxP = a0(i);
    for j = 1:n-1
        Waux = cell2mat(wk(j));
        Baux = cell2mat(bk(j));
        auxOut = transferFunction(Waux,Baux,auxP,v2(j));
        [outx,outy] = size(auxOut);
        out(j+1) = mat2cell(auxOut,outx,outy);
        auxP = cell2mat(out(j+1));
    end
    %Aqui calculamos el error de la iteracion
    eaux(i) = G(i) - cell2mat(out(n));
    %Preguntamos si el error obtenido es igual o diferente de 0
    if eaux(i) == 0
        continue
    else
        %Se empieza con la propagación hacia atras
        %Esta celula obtendra los valores de las derivadas
        Fp = cell(1,n-1);
        %Usamos una función propia para llenar esta celula
        Fp = setDerivates(Fp,v1,v2,out);
        %Ahora que tenemos las derivadas procedemos a calcular las
        %sensitividades de la red
        %Usaremos una celula para tener todas las sesitividades
        S = cell(1,n-1);
        %Con una función propia llenaremos los valores
        S = setSens(S,n-1,Fp,eaux(i),wk);
        %Ahora que tenemos las sensitividades podemos actualizar los
        %valores de los pesos y bias
        [wk,bk] = learningRule(alfa,wk,bk,S,out,n-1);
    end
end
end

