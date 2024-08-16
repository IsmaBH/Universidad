function [Wnew,Bnew] = reglaAprendizaje(Wold,Bold,error,p)
%REGLAAPRENDIZAJE Wnew = Wold+error*pT , Bnew = Bold+error
%   Aqui se implementa la regla de aprendizaje del perceptron
auxW = error * p';
Wnew = Wold + auxW;
Bnew = Bold + error;
end

