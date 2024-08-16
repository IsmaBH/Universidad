function saveWB(opc,wk,bk,layers)
%SAVEWB Guarda los valores de w y b en archivos
%   la variable text contiene el nombre del archivo donde se guardaran los
%   valores de pesos y bias segun su proposito
if opc == 1
    for i = 1:layers
        auxW = cell2mat(wk(i));
        save pesos_y_bias_finales.txt auxW -ascii -append
        auxB = cell2mat(bk(i));
        save pesos_y_bias_finales.txt auxB -ascii -append
    end
else
    for i = 1:layers
        auxW = cell2mat(wk(i));
        save w_y_b.txt auxW -ascii -append
        auxB = cell2mat(bk(i));
        save w_y_b.txt auxB -ascii -append
    end
end
end

