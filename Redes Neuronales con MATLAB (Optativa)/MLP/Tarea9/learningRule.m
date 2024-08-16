function [wk,bk] = learningRule(alfa,wk,bk,S,out,layers)
%LEARNINGRULE Implementación de las reglas de aprendizaje
%   Esta función es la que actualiza los valores de pesos y bias de la red
%   por medio de las sensitividades previamente calculadas
%Empezaremos actualizando los pesos
Waux = fliplr(wk);
Baux = fliplr(bk);
Oux = fliplr(out);
wk = fliplr(wk);
for i = 1:layers
    aux1 = cell2mat(Waux(i));
    aux2 = alfa*(cell2mat(S(i)));
    aux3 = cell2mat(Oux(i+1));
    aux4 = aux1 - aux2*aux3';
    [m,n] = size(aux4);
    wk(i) = mat2cell(aux4,m,n);
end
wk = fliplr(wk);
%Ahora actualizamos los bias
bk = fliplr(bk);
for i = 1:layers
    aux1 = cell2mat(Baux(i));
    aux2 = alfa*(cell2mat(S(i)));
    aux3 = aux1 - aux2;
    [x,y] = size(aux3);
    bk(i) = mat2cell(aux3,x,y);
end
bk = fliplr(bk);
end

