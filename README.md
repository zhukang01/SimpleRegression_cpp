# SimpleRegression_cpp

version 1.Just a test.Make a simple regression model.The data was fixed.The result is True.
version 2.0 in the description of code file 'simpleReg.cpp'.Matrix class was finished.Reference by 

https ://blog.csdn.net/m0_37772174/article/details/83018940

Matrix class problem:1.operator* return a local obj and before return, it get desturcted? So operator= get a ptr with nothin.
2.If i make obj temp in function operator* ,when it return the result to main(),the static obj gone, not get destruced(true）.But at the end of main(),when destructing, it still need to destruct temp.And its p has nothing.
