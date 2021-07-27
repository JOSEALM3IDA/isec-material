function iris_ex()
%IRIS_DATASET Summary of this function goes here
%   Detailed explanation goes here

clear all;
close all;

% Carrega o dataset
load iris_dataset;
load fisheriris;
clear meas;
species = species';

% Mostra grafico simplificado (3D) com a distribuicao dos exemplos
idx_setosa = strcmp(species, 'setosa');
idx_virginica = strcmp(species, 'virginica');
idx_versicolor = strcmp(species, 'versicolor');
setosa = irisInputs([1:3], idx_setosa);
virgin = irisInputs([1:3], idx_virginica);
versi = irisInputs([1:3], idx_versicolor);
scatter3(setosa(1,:), setosa(2,:),setosa(3,:));
hold on;
scatter3(virgin(1,:), virgin(2,:),virgin(3,:), 'rs');
scatter3(versi(1,:), virgin(2,:),versi(3,:), 'gx');
legend('setosa', 'virginica', 'versicolor')
grid on
rotate3d on



% CRIAR E CONFIGURAR A REDE NEURONAL
% INDICAR: N? camadas escondidas e nos por camada escondida
% INDICAR: Funcao de treino: {'trainlm', 'trainbfg', traingd'}
% INDICAR: Funcoes de ativacao das camadas escondidas e de saida: {'purelin', 'logsig', 'tansig'}
% INDICAR: Divisao dos exemplos pelos conjuntos de treino, validacao e teste

net = feedforwardnet();

% COMPLETAR A RESTANTE CONFIGURACAO

%net.trainFcn = 'trainbfg';
%net.layers{1}.transferFcn = 'logsig';
%net.layers{2}.transferFcn = 'tansig';
%net.layers{2}.transferFcn = 'purelin';
net.divideFcn = 'dividerand';
net.divideParam.trainRatio = 0.9;
net.divideParam.valRatio = 0.05;
net.divideParam.testRatio = 0.05;


% TREINAR
[net,tr] = train(net, irisInputs, irisTargets);
%view(net);
disp(tr)
% SIMULAR
out = sim(net, irisInputs);


%VISUALIZAR DESEMPENHO

%plotconfusion(irisTargets, out) % Matriz de confusao

%plotperf(tr)         % Grafico com o desempenho da rede nos 3 conjuntos           


%Calcula e mostra a percentagem de classificacoes corretas no total dos exemplos
r=0;
for i=1:size(out,2)               % Para cada classificacao  
  [a b] = max(out(:,i));          %b guarda a linha onde encontrou valor mais alto da saida obtida
  [c d] = max(irisTargets(:,i));  %d guarda a linha onde encontrou valor mais alto da saida desejada
  if b == d                       % se estao na mesma linha, a classificacao foi correta (incrementa 1)
      r = r+1;
  end
end

accuracy = r/size(out,2)*100;
fprintf('Precisao total %f\n', accuracy)


% SIMULAR A REDE APENAS NO CONJUNTO DE TESTE
TInput = irisInputs(:, tr.testInd);
TTargets = irisTargets(:, tr.testInd);

out = sim(net, TInput);


%Calcula e mostra a percentagem de classificacoes corretas no conjunto de teste
r=0;
for i=1:size(tr.testInd,2)               % Para cada classificacao  
  [a b] = max(out(:,i));          %b guarda a linha onde encontrou valor mais alto da saida obtida
  [c d] = max(TTargets(:,i));  %d guarda a linha onde encontrou valor mais alto da saida desejada
  if b == d                       % se estao na mesma linha, a classificacao foi correta (incrementa 1)
      r = r+1;
  end
end
accuracy = r/size(tr.testInd,2)*100;
fprintf('Precisao teste %f\n', accuracy)


end

