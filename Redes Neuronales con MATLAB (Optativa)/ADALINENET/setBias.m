function b = setBias(neurons)
%SETBIAS selecciona un bias valido
%   se selecciona un bias valido con valores en el rango de -1 a 1
limSup = 1;
a = -1;
b = zeros(neurons,1);
for i = 1:neurons
    epsilon = (limSup-a).*rand(1,1) + a;
    b(i,1) = epsilon;
end
end