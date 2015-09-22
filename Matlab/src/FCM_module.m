function FCM_module
clc; clear all; close all;
%gui
%end gui
%FCM_calculate(data_matrix, number clasters, number iteration for calculare)

X=[1 1; 1 4; 1 7; 3 2; 3 4; 3 6; 5 4; 7 4; 9 4; 11 2; 11 4; 11 6; 13 1; 13 4; 13 7];
[U,V,D]=FCM_calculate(X,2,50);






