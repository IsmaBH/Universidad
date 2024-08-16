%Practica 1 (Celula de McCulloch-Pitts)
%En esta practica se implementa la funcionalidad de la celula
%de McCulloch-Pitts con compuertas logicas
disp('Celula de McCulloch-Pitts')
disp('Compuertas disponibles:')
disp('1.- Not')
disp('2.- And')
disp('3.- Or')
op = input("Seleccione el numero de compuerta: ");
if op == 1
    n = 1;
    dataset = tabla_de_verdad(op,n);
else
    n = input("Introduzca la dimension de la compuerta: ");
    dataset = tabla_de_verdad(op,n);
end
%Las epocas deben cumplir que epoch > 50 para n > 4
epoch = input("Introduzca el numero de epocas deseadas: ");
%Creamos aleatoriamente el vector de pesos
rng(0,'twister');
weights = randi([-10 10],n,1);
%Creamos aleatoriamente el vector del umbral
umbral = randi([-10 10],1,1);
%Mostramos cuales son los valores iniciales
disp("Pesos Iniciales")
disp(weights)
disp("Umbral Inicial")
disp(umbral)
%Empezamos el proceso de aprendizaje
era = 1;
%Se repite el proceso  asignacion de pesos hasta que se cumla alguna de las
%condiciones siguientes:
%aprendizaje = true || reintento = false
aprendizaje = false;
reintento = true;
while((aprendizaje == false) || (reintento == true))
    disp("Epoca: ")
    disp(era)
    disp("Pesos actuales")
    disp(weights)
    disp("Umbral actual")
    disp(umbral)
    for b = 1:2^n
        % Operamos con la celula
        [cellOutput, actualTarget] = transferFunction(dataset(b,1:n),weights,umbral);
        if actualTarget ~= dataset(b,n+1)
           disp("El aprendizaje fallo")
           disp("Recalculando los pesos y umbral")
           weights = randi([-10 10],n,1);
           umbral = randi([-10 10],1,1);
           era = era + 1;
           break
        else
            continue
        end
    end
    if era > epoch
        disp("No se pudo completar el aprendizaje en las epocas dadas")
        disp("¿Desea reintentarlo?")
        r = input("Y=1 n=2: ");
        if r == 2
            reintento = false;
            save val_fallo.txt weights -ascii
            break
        else
            reintento = true;
            era = 1;
            weights = randi([-10 10],n,1);
            umbral = randi([-10 10],1,1);
            continue
        end
    elseif (actualTarget == dataset(2^n,n+1)) && b == 2^n
        aprendizaje = true;
        save val_finales.txt weights -ascii
        break
    end
end
disp("Pesos y umbral finales guardados")