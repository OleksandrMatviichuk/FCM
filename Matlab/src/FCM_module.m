function FCM_module
clc; clear all; close all;
%console
file_name=input('input name datafile \n','s');
%f=fopen(file_name);
%fclose(f);
tmp=importdata(file_name);
data_matrix=tmp.data;
%/console
%gui
    %Number title -show number figure
    figh=figure('Name','FCM module','NumberTitle', 'off');
    % control buttons group
    h1=uibuttongroup('visible','on','Position',[0 0 .25 1]);

        %number claster menu
        uicontrol('Style','text',...
                   'Position',[5 185 100 30],...
                    'String','Number claster',...
                    'parent',h1);
        n_cluster=uicontrol('Style','edit',...
                  'Position',[5 165 100 20],...
                  'String', 2,...
                   'parent', h1);

        %number iteration menu
        uicontrol('Style','text',...
                   'Position',[5 125 100 40],...
                    'String','Number iterations',...
                    'parent', h1);
        n_iterations=uicontrol('Style','edit',...
                  'Position',[5 105 100 20],...
                  'String', 50,...
                  'parent', h1);
        %end number iteration menu

        %radio buttons group
            uicontrol('style','text',...
                      'string', 'FCM realization',...
                      'pos', [5 85 100 20],...
                      'parent', h1);
            u0=uicontrol('Style','radiobutton',...
                         'String','discrete',...
                         'pos', [5 65 100 20],...
                         'parent',h1);
            u1=uicontrol('Style','radiobutton',...
                         'String','module',...
                         'pos', [5 45 100 20],...
                         'parent',h1);
        %end radio buttons group 
    h2=uibuttongroup('visible','on','Position',[0.25 0 .75 1]);
    h2axe=axes('parent',h2);
    plot(h2axe,1,1);
        %run button
              pushBtnRun = uicontrol('Style', 'pushbutton', ...
             'Position', [5 5 100 20],...
            'String', 'Run',...
            'Callback', {@pushBtnRunCallback,data_matrix,u1,n_iterations,n_cluster,h2axe},...
            'parent',h1);
        % text edit for iteration number
    %end controll button group

    %end gui

    %gui Callback
        %run button function
        function pushBtnRunCallback(src,evt,data_matrix,u1,n_iter,n_clust,h2axe)
            clasters=str2num((get(n_clust,'string')));
            iteration=str2num((get(n_iter,'string')));
            if get(u1,'value')==0
                opts=[nan; iteration; nan; nan];
                [Centr, U]=fcm(data_matrix,clasters,opts)
            else
                [Centr, U]=FCM_calculate(data_matrix,clasters,iteration);
            end;
               plot(h2axe,data_matrix,'ro'); 
               disp(Centr);
%end gui Callback










