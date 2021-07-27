function greek_b()

clc;
clear all;
close all;

IMG_RES = [28 28];

%% Ler e redimensionar as imagens e preparar os targets

folderImg = dir('Pasta2\\letter_bnw_*.jpg');
imgFiles = natsort({folderImg.name});

letrasBW = zeros(IMG_RES(1) * IMG_RES(2), length(imgFiles));
letrasTarget = [];
letrasBWCol = 1;
for i=1:length(imgFiles)/10   
    for j=1:10
        img = imread(sprintf('Pasta2\\%s', char(imgFiles(((j - 1) * 10) + i))));
        img = imresize(img, IMG_RES);
        binarizedImg = imbinarize(img);
        letrasBW(:, letrasBWCol) = reshape(binarizedImg, 1, []);
        letrasBWCol = letrasBWCol + 1;
    end
    
    letrasTarget = [letrasTarget eye(10)];
end

% Ordem alfabética
letrasTarget = flip(letrasTarget, 1);

%% Preparar e treinar rede

net = feedforwardnet([10]);

net.trainFcn = 'trainlm';
net.layers{1}.transferFcn = 'purelin';
net.layers{2}.transferFcn = 'purelin';
net.divideFcn = 'dividerand';
net.divideParam.trainRatio = 0.7;
net.divideParam.valRatio = 0.15;
net.divideParam.testRatio = 0.15;

[net,tr] = train(net, letrasBW, letrasTarget);

%% Simular e analisar resultados

out = sim(net, letrasBW)

disp(tr);

r = 0;
for i=1:size(out,2)               % Para cada classificacao  
    [a b] = max(out(:,i));        %b guarda a linha onde encontrou valor mais alto da saida obtida
    [c d] = max(letrasTarget(:,i)); %d guarda a linha onde encontrou valor mais alto da saida desejada
    if b == d                       % se estao na mesma linha, a classificacao foi correta (incrementa 1)
      r = r+1;
    end
end

plotconfusion(letrasTarget, out)

accuracy = r/size(out,2);
fprintf('Precisao total de treino %f\n', accuracy)

%% Guardar a rede

save('net.mat', 'net');

end

