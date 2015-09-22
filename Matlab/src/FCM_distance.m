function d=FCM_distance( X, Y)
sum=0;
len=length(X);
for i=1:len
    sum=sum+(X(i)-Y(i))^2;
end;
d=sum^0.5;
