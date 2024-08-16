function eaux = validationRound(wk,bk,G,a0,out,v2,n,eaux)
%VALIDATIONROUND Epoca de validación
%   Esta función cumple el proposito de hacer solo la propagacion hacia
%   adelante para una epoca de validación, esto quiere decir que no habra
%   aprendizaje y solo devuelve el error de la epoca para su posterior uso
%   en el algoritmo de early stopping
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
end
end

