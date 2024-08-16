function dibujaFrontera(weights,bias,inputs)
%DIBUJAFRONTERA Visualizacion de datos
%   Esta funcion plottea la frontera de decision y los datos
[m,n] = size(weights);
[a,b] = size(inputs); 
hold on
for i = 1:m
    auxA = -bias(i) / weights(i,1);
    auxB = -bias(i) / weights(i,2);
    P1 = [auxA 0];
    P2 = [0 auxB];
    plot([P1(1) P2(1)],[P1(2) P2(2)],'r')
end
for j = 1:b
    u = inputs(1,j);
    v = inputs(2,j);
    plot(u,v,'b--o')
    title("Perceptron Net")
end
hold off
end

