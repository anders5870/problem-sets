%Testmodule, not used for anything except testing stuff

-module(test).

-export([double/1,sum/2,sum/3]).

double(X) -> X*2.

sum(X,Y) -> X+Y.
sum(X,Y,Z) -> sum(X,Y)+Z.
