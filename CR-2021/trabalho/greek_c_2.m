function greek_c_2()

clc;
clear all;
close all;

IMG_RES = [28 28];

%% Ler e redimensionar as imagens e preparar os targets

folderImg = dir('Pasta3\\letter_bnw_test_*.jpg');
imgFiles = natsort({folderImg.name});

letrasBW = zeros(IMG_RES(1) * IMG_RES(2), length(imgFiles));
letrasTarget = [];
letrasBWCol = 1;
for i=1:length(imgFiles)/10  
    for j=1:10
        img = imread(sprintf('Pasta3\\%s', char(imgFiles(((j - 1) * 4) + i))));
        img = imresize(img, IMG_RES);
        binarizedImg = imbinarize(img);
        letrasBW(:, letrasBWCol) = reshape(binarizedImg, 1, []);
        letrasBWCol = letrasBWCol + 1;
    end
    
    letrasTarget = [letrasTarget eye(10)];
end

%% Escolha de rede

redeTreino = 29;    % Alterar o valor para a rede desejada

switch redeTreino
    case 29
        %% Rede 29
        net = feedforwardnet([10]);

        net.trainFcn = 'trainlm';
        net.layers{1}.transferFcn = 'purelin';
        net.layers{2}.transferFcn = 'purelin';
        net.divideFcn = 'dividerand';
        net.divideParam.trainRatio = 0.7;
        net.divideParam.valRatio = 0.15;
        net.divideParam.testRatio = 0.15;
    
    case 47
        %% Rede 47
        net = feedforwardnet([10 10]);

        net.trainFcn = 'trainlm';
        net.layers{1}.transferFcn = 'logsig';
        net.layers{2}.transferFcn = 'tansig';
        net.layers{3}.transferFcn = 'purelin';
        net.divideFcn = 'divideblock';
        net.divideParam.trainRatio = 0.7;
        net.divideParam.valRatio = 0.15;
        net.divideParam.testRatio = 0.15;
        
    case 48
        %% Rede 48

        net = feedforwardnet([10]);

        net.trainFcn = 'trainlm';
        net.layers{1}.transferFcn = 'purelin';
        net.layers{2}.transferFcn = 'purelin';
        net.divideFcn = 'divideblock';
        net.divideParam.trainRatio = 0.7;
        net.divideParam.valRatio = 0.15;
        net.divideParam.testRatio = 0.15;
        
    case 51
        %% Rede 51

        net = feedforwardnet([10]);

        net.trainFcn = 'trainlm';
        net.layers{1}.transferFcn = 'purelin';
        net.layers{2}.transferFcn = 'purelin';
        net.divideFcn = 'divideblock';
        net.divideParam.trainRatio = 0.9;
        net.divideParam.valRatio = 0.05;
        net.divideParam.testRatio = 0.05;
        
    case 52
        %% Rede 52

        net = feedforwardnet([20 20 20 20 20 20]);

        net.trainFcn = 'trainlm';
        net.layers{1}.transferFcn = 'logsig';
        net.layers{2}.transferFcn = 'purelin';
        net.layers{3}.transferFcn = 'purelin';
        net.layers{4}.transferFcn = 'tansig';
        net.layers{5}.transferFcn = 'logsig';
        net.layers{6}.transferFcn = 'logsig';
        net.layers{7}.transferFcn = 'purelin';
        net.divideFcn = 'divideblock';
        net.divideParam.trainRatio = 0.9;
        net.divideParam.valRatio = 0.05;
        net.divideParam.testRatio = 0.05;
        
    otherwise
        disp('ERROR 404: NEURAL NETWORK NOT FOUND');
        return;
end

%% TREINAR REDE

%view(net)

% TREINAR
[net, ~] = train(net, letrasBW, letrasTarget);

out = sim(net, letrasBW);

r = 0;
for i = 1: size(out,2)                  % Para cada classificação:
    [~, b] = max(out(:,i));             % b guarda a linha onde encontrou valor mais alto da saída obtida
    [~, d] = max(letrasTarget(:,i));    % d guarda a linha onde encontrou valor mais alto da saída desejada
    if b == d                           % Se estão na mesma linha, a classificação foi correta (incrementa 1)
      r = r+1;
    end
end

plotconfusion(letrasTarget, out)
%plotperf(tr)

accuracy = r/size(out,2);
fprintf('Precisao total de treino %f\n', accuracy)

%% Testar rede com pasta 1

letrasBW = zeros(IMG_RES(1) * IMG_RES(2), 10);

for i = 1: 10
    img = imread(sprintf('Pasta1\\%d.jpg', i));
    img = imresize(img, IMG_RES);
    binarizedImg = imbinarize(img);
    letrasBW(:, i) = reshape(binarizedImg, 1, []);
end

letrasTarget1 = [eye(10)];
out1 = sim(net, letrasBW);

r = 0;
for i = 1: size(out1, 2)                % Para cada classificação:
    [~, b] = max(out1(:, i));           % b guarda a linha onde encontrou valor mais alto da saída obtida
    [~, d] = max(letrasTarget1(:, i));  % d guarda a linha onde encontrou valor mais alto da saída desejada
    if b == d                           % Se estão na mesma linha, a classificação foi correta (incrementa 1)
      r = r+1;
    end
end

accuracy = r/size(out1, 2);
fprintf('Precisão total de simulação para a pasta 1: %f\n', accuracy);

%% Testar rede com pasta 2

folderImg = dir('Pasta2\\letter_bnw_*.jpg');
imgFiles = natsort({folderImg.name});

letrasBW = zeros(IMG_RES(1) * IMG_RES(2), length(imgFiles));
letrasTarget2 = [];
letrasBWCol = 1;

for i = 1: length(imgFiles) / 10   
    for j = 1: 10
        img = imread(sprintf('Pasta2\\%s', char(imgFiles(((j - 1) * 10) + i))));
        img = imresize(img, IMG_RES);
        binarizedImg = imbinarize(img);
        letrasBW(:, letrasBWCol) = reshape(binarizedImg, 1, []);
        letrasBWCol = letrasBWCol + 1;
    end
    
    letrasTarget2 = [letrasTarget2 eye(10)];
end

% Ordem alfabética
letrasTarget2 = flip(letrasTarget2, 1);

out2 = sim(net, letrasBW);

r = 0;
for i = 1: size(out2, 2)                % Para cada classificação:
    [~, b] = max(out2(:, i));           % b guarda a linha onde encontrou valor mais alto da saída obtida
    [~, d] = max(letrasTarget2(:, i));  % d guarda a linha onde encontrou valor mais alto da saída desejada
    if b == d                           % Se estão na mesma linha, a classificação foi correta (incrementa 1)
      r = r+1;
    end
end

accuracy = r/size(out2, 2);
fprintf('Precisão total de simulação para a pasta 2: %f\n', accuracy);

%% Testar rede com pasta 3

folderImg = dir('Pasta3\\letter_bnw_test_*.jpg');
imgFiles = natsort({folderImg.name});

letrasBW = zeros(IMG_RES(1) * IMG_RES(2), length(imgFiles));
letrasTarget3 = [];
letrasBWCol = 1;
for i = 1: length(imgFiles) / 10  
    for j = 1: 10
        img = imread(sprintf('Pasta3\\%s', char(imgFiles(((j - 1) * 4) + i))));
        img = imresize(img, IMG_RES);
        binarizedImg = imbinarize(img);
        letrasBW(:, letrasBWCol) = reshape(binarizedImg, 1, []);
        letrasBWCol = letrasBWCol + 1;
    end
    
    letrasTarget3 = [letrasTarget3 eye(10)];
end

out3 = sim(net, letrasBW);

r = 0;
for i = 1: size(out3, 2)                % Para cada classificação:
    [~, b] = max(out3(:, i));           % b guarda a linha onde encontrou valor mais alto da saída obtida
    [~, d] = max(letrasTarget3(:, i));  % d guarda a linha onde encontrou valor mais alto da saída desejada
    if b == d                           % Se estão na mesma linha, a classificação foi correta (incrementa 1)
      r = r+1;
    end
end

accuracy = r/size(out3, 2);
fprintf('Precisão total de simulação para a pasta 3: %f\n', accuracy);

%% Plotconfusion para todas as simulações

plotconfusion(letrasTarget1, out1, 'Pasta 1', letrasTarget2, out2, 'Pasta 2', letrasTarget3, out3, 'Pasta 3');

% Mudar tamanho da letra
set(findall(gcf, '-property', 'FontSize'), 'FontSize', 6);

end

