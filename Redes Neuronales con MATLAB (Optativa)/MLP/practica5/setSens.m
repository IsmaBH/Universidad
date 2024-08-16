function S = setSens(S,layers,Fp,e,wk)
%SETSENS Calculo de las sensitividades de la red
%   Esta función calcula los valores de sensitividad de cada capa de la
%   red, el orden de S sera de la capa de salida a la primera capa
for i = 1:layers
    if i == 1
        df = cell2mat(Fp(i));
        aux1 = -2*df*e;
        [x,y] = size(aux1);
        S(i) = mat2cell(aux1,x,y);
    else
        Waux = fliplr(wk);
        df = cell2mat(Fp(i));
        wf = cell2mat(Waux(i-1));
        sA = cell2mat(S(i-1));
        aux1 = df*wf';
        aux2 = aux1*sA;
        [x,y] = size(aux2);
        S(i) = mat2cell(aux2,x,y);
    end
end
end

