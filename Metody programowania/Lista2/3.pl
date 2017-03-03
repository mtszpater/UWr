?- append(X,X,Y).
X = Y, Y = [] ;
X = [_G2407],
Y = [_G2407, _G2407] ;
X = [_G2407, _G2413],
Y = [_G2407, _G2413, _G2407, _G2413] ;
X = [_G2407, _G2413, _G2419],

?- select(X, [a,b,c,d], [a,c,d]).
X = b .

?- append([a,b,c], X, [a,b,c,d,e]).
X = [d, e].