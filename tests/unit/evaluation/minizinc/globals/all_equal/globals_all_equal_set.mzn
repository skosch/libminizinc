% RUNS ON mzn20_fd
% RUNS ON mzn20_fd_linear

% Test the set all_equal global constraint.

include "all_equal.mzn";

array[1..10] of var set of 1..5: x;

constraint all_equal([]);
constraint all_equal([{1, 2}, {1, 2}, {1, 2}, {1, 2}]);
constraint x[1] = {1, 2};
constraint all_equal(x);
constraint all_equal([{}, {1}, {1, 2}]) == false;

solve satisfy;

output ["x = ", show(x), ";\n"];
