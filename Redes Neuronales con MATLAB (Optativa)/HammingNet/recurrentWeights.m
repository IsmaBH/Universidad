function W = recurrentWeights(epsilon,m)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
v = ones(1,m);
w = diag(v);
[x,y] = size(w);
for i = 1:x
    for j = 1:y
        if(w(i,j) == 0)
            w(i,j) = -epsilon;
        else
            continue
        end
    end
end
W = w;
end

