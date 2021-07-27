function paridade1( )
%usando as funcoes da NNTool

% limpar
clear all;
close all;

% inicializar entrada
p = [0 1 0 0 0 1 0 1 1 0 0 1 0 1 1;
     0 0 1 0 0 1 1 0 0 0 1 1 1 0 1;
     0 0 0 1 0 0 1 1 0 1 0 1 1 1 1;
     0 0 0 0 1 0 0 0 1 1 1 0 1 1 1];
 
t = [0 0 0 0 0 1 1 1 1 1 1 0 0 0 1];

% COMPLETAR: criar RN chamada net
net = feedforwardnet;

% COMPLETAR: ajustar os parametros seguintes

% FUNCAO DE ATIVACAO DA CAMADA DE SAIDA
net.layers{2}.transferFcn = 'tansig';

% FUNCAO DE TREINO
net.trainFcn = 'trainlm';

% NUMERO DE EPOCAS DE TREINO
net.trainParam.epochs = 100;

% TODOS OS EXEMPLOS DE INPUT SAO USADOS NO TREINO
net.divideFcn = '';                 

% COMPLETAR: treinar a rede
net = train(net, p, t);

% Simular rede
y = sim(net, p);
y = (y >= 0.5);

% Mostrar resultado
fprintf('Saida da RN: ');
disp(y);
fprintf('Saida desejada:      ');
disp(t);

% visualizar a arquitetura da rede criada
view(net)

end

