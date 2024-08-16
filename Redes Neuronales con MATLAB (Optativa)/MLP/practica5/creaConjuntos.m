function [dse,dsg] = creaConjuntos(p,G,opc)
%CREACONJUNTOS Divide en subconjuntos un vector dado
%   Esta función divide el vector de entrada p en 3 subconjuntos de datos
%   para su posterior uso de acuerdo a la opción que se haya elegido
[~,n1] = size(p);
dse = cell(1,3);
dsg = cell(1,3);
subTP = [];
subVP = [];
subTSP = [];
subTG = [];
subVG = [];
subTSG = [];
index1 = [];
index2 = [];
if opc == 1
    %Opcion 70/15/15
    train = round(n1*0.7);
    val = round(n1*0.15);
    test = round(n1*0.15);
    %Aqui empezamos la separación
    Q1 = n1/train;
    index1 = [];
    index2 =[];
    for i = 1:train
        index1 = [index1,round(Q1*i)];
    end
    subTP = p(index1);
    subTG = G(index1);
    p(index1) = [];
    G(index1) = [];
    [~,n2] = size(p);
    Q2 = n2/val;
    for j = 1:val
        index2 = [index2,round(Q2*j)];
    end
    subVP = p(index2);
    subVG = G(index2);
    p(index2) = [];
    G(index2) = [];
    subTSP = p;
    subTSG = G;
else
    %Opcion 80/10/10
    train = round(n1*0.8);
    val = round(n1*0.1);
    test = round(n1*0.1);
    %Aqui empezamos la separación
    Q1 = n1/train;
    index1 = [];
    index2 =[];
    for i = 1:train
        index1 = [index1,round(Q1*i)];
    end
    subTP = p(index1);
    subTG = G(index1);
    p(index1) = [];
    G(index1) = [];
    [~,n2] = size(p);
    Q2 = n2/val;
    for j = 1:val
        index2 = [index2,round(Q2*j)];
    end
    subVP = p(index2);
    subVG = G(index2);
    p(index2) = [];
    G(index2) = [];
    subTSP = p;
    subTSG = G;
end
%Aqui juntamos los resultados de entrenamiento
[rowT,colT] = size(subTP);
[rowV,colV] = size(subVP);
[rowTS,colTS] = size(subTSP);
dse(1) = mat2cell(subTP,rowT,colT);
dse(2) = mat2cell(subVP,rowV,colV);
dse(3) = mat2cell(subTSP,rowTS,colTS);
%Ahora juntamos los resultados del target
[rowTG,colTG] = size(subTG);
[rowVG,colVG] = size(subVG);
[rowTSG,colTSG] = size(subTSG);
dsg(1) = mat2cell(subTG,rowTG,colTG);
dsg(2) = mat2cell(subVG,rowVG,colVG);
dsg(3) = mat2cell(subTSG,rowTSG,colTSG);
end

