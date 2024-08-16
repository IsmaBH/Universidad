%Tarea 9 Aproximación de una función
%En esta tarea se utilizara el modelo MLP de la tarea anterior pero
%implementando las ecuaciones de sensitividad y reglas de aprendizaje para
%la aproximación de una función G(p)
disp("Red MLP")
%Empezaremos generando nuestro set de entrenamiento G(p), p y a0
p = -2:0.1:2;
G = 1 + sin((pi*p/4));
[rowP,colP] = size(p);
a0 = cell(1,colP);
for i = 1:colP
    a0(i) = num2cell(p(i));
end
%Ahora pediremos los vectores V1 y V2
v1 = input("Indique los valores del vector V1: ");
v2 = input("Indique los valores del vector V2: ");
%Ahora pedimos los valores de epochmax y EEpochmax
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
%Ahora empezamos con el ciclo de entrenamiento
epoch = 1;
text1 = 'Epoca ';
text2 = 'El error de la epoca fue de ';
out = cell(1,n);
eaux = zeros(colP,1);
while epoch <= epochmax
    x = [text1,num2str(epoch)];
    disp(x)
    %Este ciclo for hace la función de la propagación hacia adelante
    for i = 1:colP
        out(1) = a0(i);
        auxP = cell2mat(a0(i));
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
        %Preguntamos si el error obtenido es igual o diferente de 0
        if eaux(i) == 0
            continue
        else
            %Se empieza con la propagación hacia atras
            %Esta celula obtendra los valores de las derivadas
            Fp = cell(1,n-1);
            %Usamos una función propia para llenar esta celula
            Fp = setDerivates(Fp,v1,v2,out);
            %Ahora que tenemos las derivadas procedemos a calcular las
            %sensitividades de la red
            %Usaremos una celula para tener todas las sesitividades
            S = cell(1,n-1);
            %Con una función propia llenaremos los valores
            S = setSens(S,n-1,Fp,eaux(i),wk);
            %Ahora que tenemos las sensitividades podemos actualizar los
            %valores de los pesos y bias
            [wk,bk] = learningRule(alfa,wk,bk,S,out,n-1);
        end
    end
    %Ahora el error de la epoca
    epochaux = sum(eaux);
    epochaux2 = (1/colP)*epochaux;
    EEPOCH = abs(epochaux2);
    x2 = [text2,num2str(EEPOCH)];
    disp(x2)
    %Comprobamos si el error obtenido es igual o menor al maximo dado
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
    end
    epoch = epoch+1;
end
disp(wk)
disp(bk)
%Sea que haya terminado por que logro un error menor al dado o que se hayan
%acabado las epocas, usando los ultimos valores de pesos y bias se propaga
%hacia adelante para obtener la grafica final
for i = 1:colP
    out(1) = a0(i);
    auxP = cell2mat(a0(i));
    for j = 1:n-1
        Waux = cell2mat(wk(j));
        Baux = cell2mat(bk(j));
        auxOut = transferFunction(Waux,Baux,auxP,v2(j));
        [outx,outy] = size(auxOut);
        out(j+1) = mat2cell(auxOut,outx,outy);
        auxP = cell2mat(out(j+1));
    end
    hold on
    title('Aproximación de G(p)');
    xlabel('P')
    ylabel('a2')
    plot(p(i),cell2mat(out(n)),'bx')
    plot(p(i),G(i),'ko')
end
hold off