function dibujaPesos(weights,epoch)
%DIBUJAPESOS Se pinta la grafica de los pesos
%   Esta función dibujará la evolucion de los pesos en cada epoca
[m,n] = size(weights);
title('Evolución de los pesos')
for i = 1:m
    for j = 1:n
        plot(epoch,weights(i,j),'b*')
    end
end
end

