% RUNS ON mzn20_fd
% RUNS ON mzn20_fd_linear
%% has no solution in strict and Kleene 
%% solution x = 0 in relational 

var 0..1: x; 

constraint not (1 div x = 1); 

solve satisfy;

output ["x = ", show(x), ";\n"];
