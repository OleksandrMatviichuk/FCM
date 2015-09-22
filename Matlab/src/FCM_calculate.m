function [Centr_matrix,Rand_matrix]=FCM_calculate(data_matrix,num_claster,num_iter)
%calculate size data matrix
data_matrix=data_matrix';
[S_x, S_y]=size(data_matrix);
%create normalised random matrix
Rand_matrix=rand(num_claster,S_x);
s=sum(Rand_matrix);
Rand_matrix=Rand_matrix./s(ones(num_claster,1),:);

Centr_matrix=zeros(num_claster,S_x);
Dist_matrix=zeros(S_y, num_claster);
Rand_matrix=Rand_matrix';
for count = 0:num_iter;
    for j = 1:num_claster
        for z = 1:S_y;
            t1 = 0.0;
            t2 = 0.0;
            for i = 1:S_x
                t1 = t1 + Rand_matrix(i,j) * Rand_matrix(i,j) * data_matrix(i,z);
                t2 = t2 + Rand_matrix(i,j) * Rand_matrix(i,j);
            end;
            Centr_matrix(j,z) = t1/t2; 
        end;
    end;
    for i = 1:S_x
        for j=1:num_claster
           Dist_matrix(i,j)=FCM_distance(data_matrix(i,:), Centr_matrix(j,:));
        end;
    end;
    for i = 1: S_x
        for j = 1:num_claster;
            t3=0.0;
            if Dist_matrix(i,j)==0
                Rand_matrix(i,j)=1.0;
            else
                for z = 1: num_claster
                    t3 = t3 + (Dist_matrix(i,j) * Dist_matrix(i,j))/(Dist_matrix(i,z)*Dist_matrix(i,z));
                end;
            end
            Rand_matrix(i,j)=1.0/t3;    
        end;
    end;
end;