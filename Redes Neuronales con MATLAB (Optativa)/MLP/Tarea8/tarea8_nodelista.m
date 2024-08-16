%Tarea 8: Aproximaciones
%En esta tarea se propone implementar las ecuaciones de propagacion hacia
%adelante de la red MLP y con estas generar las graficas vistas en el
%ejercicio del libro Neural Networks
disp("Red MLP")
%Empezamos creando los vectores V1 y V2
v1 = input("Indique los valores del vector V1: ");
[rowV1,colV1] = size(v1);
v2 = zeros(1,colV1-1);
for i = 2:colV1
    v2(1,i-1) = v1(1,i);
end
%Se crea el vector de entrada p en el rango de (-2,2)
p = -2:0.01:2;
[rowP,colP] = size(p);
%Se crearan los pesos y bias para la primera capa
[W1,B1] = setWeightsBiases(v2(1,1),v1(1,1),1);
B1(2,1) = 10;
%Creamos el rango de valores para las variaciones
var = -1:0.6:1;
%Iniciamos el proceso de las funciones de transferencia
W2 = ones(1,2);
B2 = 0;
%for j = 1:5
%     if j > 1
%         W1(2,1) = var(j-1);
%     end
    for i = 1:colP
        %Primero hacemos uso de la funcion logsig
        a = transferFunction(W1,B1,p(i),1);
        [rowa1,cola1] = size(a);
        %Una vez obtenido el resultado de esta capa
        %Enviamos el resultado a la siguiente capa con la funcion purelin
        a2 = transferFunction(W2,B2,a,3);
        %Una vez obtenido este ultimo resultado graficamos
%         if j <= 1
            hold on
            title('Funcion Original')
            xlabel('P')
            ylabel('a2')
            plot(p(i),a2,'--gs','linewidth',1)
%         else
%             plot(p(i),a2,'--rs','linewidth',1)
%         end
    end
%end
hold off