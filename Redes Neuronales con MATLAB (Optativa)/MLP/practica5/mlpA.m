%Practica 5A Aproximación de señales
%En esta practica se plantea implementar el MLP para la aproximación de
%diferentes señales y la implementación del algoritmo de early stopping
disp("Red MLP")
%Lo primero sera construir nuestros datasets
load input_p.txt
load target_p.txt
%Por conveniencia guardaremos estos targets en una variable G que sera un
%vector 1xn, de igual forma haremos con p
p = input_p';
G = target_p';
%Ahora que tenemos el total de datos de entrada los separamos preguntamos
%el tipo de división que se desea de estos datos y el rango de la señal
disp("Opciones:")
disp("1.- 70% entrenamiento, 15% validación, 15% prueba")
disp("2.- 80% entrenamiento, 10% validación, 10% prueba")
opc = input("Eliga la opción de división que desee: ");
r = input("Introduzca el rango de la función: ");
%Ya que se tiene la opción de división se procede a separar el dataset
[dS,dG] = creaConjuntos(p,G,opc);
%Creamos el vector del rango
rango = generaRango(dS(3),r);
%Ahora pediremos los vectores V1 y V2
v1 = input("Indique los valores del vector V1: ");
v2 = input("Indique los valores del vector V2: ");
%Pedimos que nos indique el intervalo de epocas para la comprobación
intVal = input("Indique el intervalo de epocas de validación: ");
%Ahora pedimos los valores de epochmax, EEpochmax y alfa
epochmax = input("Introduzca el número de epocas maxima: ");
EEPOCHMAX = input("Introduzca el valor maximo de error en cada epoca: ");
alfa = input("Introduzca el valor de la tasa de aprendizaje: ");
%Inicializamos las matrices de pesos y bias
%Se utilizara el tipo de dato cell para poder obtener todas las matrices de
%pesos necesarios desde el principio
[m,n] = size(v1);
%R es el valor de los datos de entrada en este caso es 1
R = v1(1);
wk = cell(1,n-1);
bk = cell(1,n-1);
%Utilizaremos una funcion propia para llenar los valores de pesos y bias
wk = setWeights(wk,v1,n);
bk = setBias(bk,v1,R,n);
%Ahora iniciamos las epocas
epoch = 1;
text1 = 'Epoca ';
text2 = 'El error de la epoca fue de ';
out = cell(1,n);
%Declaramos algunas variables que nos ayudaran con los calculos
[~,colT] = size(cell2mat(dS(1)));
etrain = zeros(colT,1);
[~,colVal] = size(cell2mat(dS(2)));
eval = zeros(colVal,1);
EVALACTUAL = 0;
EVALANTERIOR = 0;
numval = 0;
while epoch <= epochmax
    x = [text1,num2str(epoch)];
    disp(x)
    %Se plantea hacer el procedimiento de propagación hacia adelante y
    %propagacion hacia atras en una función separada
    if mod(epoch,intVal) == 0
        %Solo se propaga hacia adelante
        auxG = cell2mat(dG(2));
        auxP = cell2mat(dS(2));
        %Graficamos los pesos actuales antes de empezar
%         hold on
%         figure(1)
%         title("Evolución de pesos capa 1");
%         xlabel('epocas')
%         ylabel('W')
%         drawW(cell2mat(wk(1)),epoch);
%         hold on
%         figure(2)
%         title("Evolución de pesos capa 2");
%         xlabel('epocas')
%         ylabel('W')
%         drawW(cell2mat(wk(2)),epoch);
%         hold on
%         figure(3)
%         title("Evolución de pesos capa 3");
%         xlabel('epocas')
%         ylabel('W')
%         drawW(cell2mat(wk(3)),epoch);
%         hold on
%         figure(4)
%         title("Evolución de bias capa 1");
%         xlabel('epocas')
%         ylabel('B')
%         drawW(cell2mat(bk(1)),epoch);
%         hold on
%         figure(5)
%         title("Evolución de bias capa 2");
%         xlabel('epocas')
%         ylabel('B')
%         drawW(cell2mat(bk(2)),epoch);
%         hold on
%         figure(6)
%         title("Evolución de bias capa 3");
%         xlabel('epocas')
%         ylabel('B')
%         drawW(cell2mat(bk(3)),epoch);
        %Se empieza la propagación hacia adelante
        eval = validationRound(wk,bk,auxG,auxP,out,v2,n,eval);
        %Ahora el error de la epoca
        epochaux = sum(eval);
        epochaux2 = (1/colVal)*epochaux;
        EVALACTUAL = abs(epochaux2);
        x2 = [text2,num2str(EVALACTUAL)];
        disp(x2)
%         hold on
%         figure(7)
%         plot(epoch,EVALACTUAL,'b*')
        if EVALACTUAL > EVALANTERIOR
            numval = numval + 1;
            EVALANTERIOR = EVALACTUAL;
        else
            numval = 0;
        end
    else
        %Se aplican las reglas de aprendizaje
        auxG = cell2mat(dG(1));
        auxP = cell2mat(dS(1));
        [wk,bk,out,etrain] = backPropagation(wk,bk,auxG,v1,v2,auxP,alfa,out,n,etrain);
        %Ahora el error de la epoca
        epochaux = sum(etrain);
        epochaux2 = (1/colT)*epochaux;
        EEPOCH = abs(epochaux2);
        x2 = [text2,num2str(EEPOCH)];
        disp(x2)
%         hold on
%         figure(7)
%         title("Evolucion del error de aprendizaje y evaluación");
%         xlabel('epocas')
%         ylabel('error')
%         plot(epoch,EEPOCH,'r*')
    end
    %Aqui aplicamos las condiciones de termino y/o early stopping
    if EEPOCH == 0
        disp("El error de la epoca fue de 0")
        %Guardamos los valores finales de W
        %save valores_finales_RNA.txt wk -ascii
        break;
    elseif EEPOCH < EEPOCHMAX
        disp("El error de la epoca fue menor al maximo dado")
        %Guardamos los valores finales de W
        %save valores_finales_RNA.txt wk -ascii
        break;
    elseif numval == 3
        disp("Se ha activado EARLY STOPPING, porfavor intente otra arquitectura")
        break;
    end
    epoch = epoch+1;
end
% hold off
% hold off
% hold off
% hold off
% hold off
% hold off
% hold off
%Una vez terminado el aprendizaje por cualquiera de los metodos de
%finalización hacemos una propagación hacia adelante mas con el conjunto de
%prueba y graficamos los resultados
ptest = cell2mat(dS(3));
gtest = cell2mat(dG(3));
[~,colTest] = size(ptest);
for i = 1:colTest
    out(1) = num2cell(ptest(i));
    auxP = ptest(i);
    for j = 1:n-1
        Waux = cell2mat(wk(j));
        Baux = cell2mat(bk(j));
        auxOut = transferFunction(Waux,Baux,auxP,v2(j));
        [outx,outy] = size(auxOut);
        out(j+1) = mat2cell(auxOut,outx,outy);
        auxP = cell2mat(out(j+1));
    end
    saveWB(1,wk,bk);
    hold on
    figure(1)
    title('Aproximación de G(p)');
    xlabel('P')
    ylabel('a2')
    plot(rango(i),cell2mat(out(n)),'bx')
    plot(rango(i),gtest(i),'ko')
end
hold off