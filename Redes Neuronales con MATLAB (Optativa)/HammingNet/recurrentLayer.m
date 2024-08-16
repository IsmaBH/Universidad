function Atn = recurrentLayer(W,At)
%RECURRENTLAYER Capa recurrente de la red
%   Esta funcion realiza la funcion de la capa recurrente de hamming
aux = W * At;
if aux > 0
    Atn = aux;
elseif aux < 0
    Atn = 0;
else
    Atn = aux;
end
end