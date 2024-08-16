%Practica 2 red de hamming
%En esta practica se implementa la funcion de clasificacion de la red de
%hamming
%Se piden los archivos de pesos y el vector a ser clasificado
load w1.txt
load p_new.txt
%Como paso intermedio se genera el bias
[m,n] = size(w1);
bias = zeros(1,m);
for i = 1:m
    bias(i) = n;
end
%Empieza la clasificacion de datos
%Capa feedforward
A0 = zeros(1,m);
for b = 1:m
    aux = feedForwardlayer(w1(b,1:n),p_new);
    A0(b) = aux + bias(b);
end
%disp(A0)
%Seleccion de Epsilon
rng(0,'twister');
limSup = 1/(m-1);
a = 0;
epsilon = (limSup-a).*rand(1,1) + a;
%Capa recurrente
At = A0';
auxA = zeros(1,m);
%Se creara la matriz w2
w2 = recurrentWeights(epsilon,m);
[x,y] = size(w2);
convergencia = false;
comprobacion = 0;
iteracion = 1;
save at_vals.txt iteracion -ascii
while convergencia ~= true
    isCero = 0;
    %disp(At)
    save at_vals.txt At -ascii -append
    for c = 1:y
        auxA(c) = recurrentLayer(w2(c,1:x),At);
    end
    hold on
    plot(iteracion,At,'b--o')
    title("Red de Hamming")
    for d = 1:y
        if auxA(d) == 0
            isCero = isCero + 1;
        else
            continue
        end
    end
    if isCero == x-1
        comprobacion = comprobacion + 1;
        if comprobacion == 2
            convergencia = true;
            At = auxA';
        else
            At = auxA';
            iteracion = iteracion + 1;
            save at_vals.txt iteracion -ascii -append
        end
    else
        At = auxA';
        iteracion = iteracion + 1;
        save at_vals.txt iteracion -ascii -append
    end
end
hold off
%Se le informa al usuario en que clase quedo el vector prototipo
disp(At)
%Se muestra la grafica de como evolucionaron las clases