function Fp = setDerivates(Fp,v1,v2,out)
%SETDERIVATES Prepara las derivadas de la red
%   Esta función prepara las matrices que requerira la red para el calculo
%   de las sensitividades, creando la matriz cuadrada correspondiente a la
%   funcion de transferencia de cada capa, el primer espacio sera para la
%   capa de salida y asi sucesivamente
[~,n] = size(v1);
auxV1 = fliplr(v1);
auxV2 = fliplr(v2);
auxO = fliplr(out);
for i = 1:n-1
    tam = auxV1(i);
    func = auxV2(i);
    if func == 1
        purelin = ones(1,tam);
        aux = diag(purelin);
        Fp(i) = mat2cell(aux,tam,tam);
    elseif func == 2
        logsigD = zeros(1,tam);
        a = cell2mat(auxO(i));
        for l = 1:tam
            logsigD(l) = (1-a(l))*a(l);
        end
        aux = diag(logsigD);
        [a,b] = size(aux);
        Fp(i) = mat2cell(aux,a,b);
    elseif func == 3
        tansigD = zeros(1,tam);
        a = cell2mat(auxO(i));
        for l = 1:tam
           tansigD(l) = (1-a(l)^2);
        end
        aux = diag(tansigD);
        [a,b] = size(aux);
        Fp(i) = mat2cell(aux,a,b);
    end
end

