function A = feedForwardlayer(weights,p)
%FEEDFORWARDLAYER Primera capa de la red
%   Esta primera capa hace el primer filtro para obtener a(0)
auxRes = weights * p;
A = auxRes;
end

