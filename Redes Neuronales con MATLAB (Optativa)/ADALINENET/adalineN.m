%Practica 4 Red de ADALINE
%En esta practica se implementa la red ADALINE con función regresora (sin
%bias) y clasificadora (con bias)
disp("Red de ADALINE")
%Se pregunta que función se usara y otros datos
epochmax = input("Indique el número maximo de epocas: ");
Eepoch = input("Indique el número maximo de error de las epocas: ");
alfa = input("Indique la tasa de aprendizaje: ");
func = input("Modo regresor:1 | Modo clasificador:2, Elija una: ");
%Se crean las matrices w y b segun el modo seleccionado
%Que la variable func sea 1 significa que es modo regresor por lo que solo
%se creara la matriz de pesos
if func == 1
    %Para el modo regresor se usara como dataset codificadores de n bits
    %Preguntamos de cuantos bits sera el codificador a usar
    bits = input("Introduzca el número de bits para el codificador: ");
    dataset = setCoder(bits);
    save input_regresor.txt dataset -ascii
    [m,n] = size(dataset);
    W = setWeights(bits);
    b = 0;
    %Empezamos las epocas de aprendizaje
    epoch = 1;
    text1 = 'Epoca ';
    text2 = 'El error de la epoca fue de ';
    eaux = zeros(m,1);
    while epoch <= epochmax
        x = [text1,num2str(epoch)];
        disp(x)
        hold on
        figure(1)
        dibujaPesos(W,epoch);
        for i = 1:m
            a = transferFunction(W,dataset(i,1:n-1)',b);
            error = dataset(i,n) - a;
            eaux(i) = error;
            if error == 0
                continue
            else
                [W,b] = reglaAprendizaje(W,b,error,alfa,dataset(i,1:n-1));
                disp("Pesos actualizados")
                disp(W)
            end
        end
        %Aqui calculamos el error de la epoca
        epochaux = sum(eaux);
        epochaux2 = (1/m)*epochaux;
        EEPOCH = abs(epochaux2);
        x2 = [text2,num2str(EEPOCH)];
        disp(x2)
        if EEPOCH == 0
            disp("Todos los datos fueron clasificados con exito")
            %Guardamos los valores finales de W
            save valores_finales_RNA.txt W -ascii
            break;
        elseif EEPOCH < Eepoch
            disp("El error de la epoca fue menor al maximo dado")
            figure(2)
            plot(epoch,EEPOCH,'r*')
            hold off
            %Guardamos los valores finales de W
            save valores_finales_RNA.txt W -ascii
            break;
        end
        hold on
        figure(2)
        plot(epoch,EEPOCH,'r*')
        title('Evolución del error en las epocas')
        epoch = epoch + 1;
    end
    if epoch > epochmax
        disp("No se logro el aprendizaje en las epocas dadas")
        hold off
    end
    hold off
%Que sea 2 significa que es modo clasificador y es necesario crear la
%matriz de pesos y de bias
else
    %Se cargan los archivos necesarios para el clasificador
    load input_p.txt
    load target.txt
    [rowX,colY] = size(input_p);
    [rowA,colB] = size(target);
    %neurons = colB / 2;
    limSup = 1;
    a = -1;
    W = setWeights(rowX);
    b = setBias(1);
    %Empezamos las epocas de aprendizaje
    epoch = 1;
    text1 = 'Epoca ';
    text2 = 'El error de la epoca fue de ';
    eaux = zeros(colY,1);
    disp(W)
    disp(b)
    while epoch <= epochmax
        x = [text1,num2str(epoch)];
        disp(x)
        hold on
        figure(1)
        dibujaPesos(W,epoch);
        figure(3)
        dibujaBias(b,epoch);
        for i = 1:colY
            a = transferFunction(W,input_p(:,i),b);
            error = target(:,i) - a;
            eaux(i) = sum(error);
            if error == 0
                continue
            else
                [W,b] = reglaAprendizaje(W,b,error,alfa,input_p(:,i)');
                disp("Pesos actualizados")
                disp(W)
                disp("Bias actualizado")
                disp(b)
            end
        end
        %Calculamos el error de la epoca
        epochaux = sum(eaux);
        epochaux2 = (1/colY)*epochaux;
        EEPOCH = abs(epochaux2);
        x2 = [text2,num2str(EEPOCH)];
        disp(x2)
        if EEPOCH == 0
            disp("Todos los datos fueron clasificados con exito")
            dibujaFrontera(W,b,input_p);
            %Guardamos los valores finales de W y b
            save valores_finales_RNA.txt W -ascii
            save valores_finales_RNA.txt b -ascii -append
            break;
        elseif EEPOCH < Eepoch
            disp("El error de la epoca fue menor al maximo dado")
            figure(2)
            plot(epoch,EEPOCH,'r*')
            hold off
            figure(4)
            dibujaFrontera(W,b,input_p);
            %Guardamos los valores finales de W y b
            save valores_finales_RNA.txt W -ascii
            save valores_finales_RNA.txt b -ascii -append
            break;
        end
        hold on
        figure(2)
        plot(epoch,EEPOCH,'r*')
        title('Evolución del error en las epocas')
        epoch = epoch + 1;
    end
    if epoch > epochmax
        disp("No se logro el aprendizaje en las epocas dadas")
        hold off
    end
end