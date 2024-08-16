%Practica 3 Red Perceptron
%En esta practica se implementa el uso de la red perceptron de la 
%clasificacion
disp("Red perceptron")
%Se piden los archivos de pesos y el vector a ser clasificado
load input_p.txt
load target.txt
maxepoch = input("Introduzca el numero maximo de epocas ");
%Generamos la matriz inicial de pesos y bias (Aleatorio)
%rng(0,'twister');
[rowX,colY] = size(input_p);
[rowA,colB] = size(target);
neurons = colB / 2;
weights = randi([-5 5],neurons,rowX);
bias = randi([-5 5],neurons,1);
%Se inicia el proceso de aprendizaje
epoch = 1;
comprobacion = 0;
aprendizaje = false;
while (epoch <= maxepoch)
    for i = 1:colY
        resAux = transferFunction(input_p(:,i),weights,bias);
        if resAux == target(:,i)
            comprobacion = comprobacion + 1;
            %continue
        else
            %Calculamos el error e = t-a
            Error = target(:,i) - resAux;
            %Aplicamos la regla de aprendizaje
            [weights,bias] = reglaAprendizaje(weights,bias,Error,input_p(:,i));
        end
    end
    if comprobacion == colY
        aprendizaje = true;
        break;
    else
        epoch = epoch + 1;
        comprobacion = 0;
    end
end
if aprendizaje == true
    disp("Se termino por aprendizaje")
    disp("Pesos obtenidos")
    disp(weights)
    disp("Bias obtenidos")
    disp(bias)
    dibujaFrontera(weights,bias,input_p);
    save valores_finales_wyb.txt weights -ascii
    save valores_finales_wyb.txt bias -ascii -append
else
    disp("Se termino por rebasar las epocas, no se logro el aprendizaje")
    save valores_finales_fallo_wyb.txt weights -ascii
    save valores_finales_fallo_wyb.txt bias -ascii -append
end