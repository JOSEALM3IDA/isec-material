function greek_a()

clc;
clear all;
close all;

IMG_RES = [28 28];

%% Ler e redimensionar as imagens e preparar os targets

letrasBW = zeros(IMG_RES(1) * IMG_RES(2), 10);

for i=1:10
    img = imread(sprintf('Pasta1\\%d.jpg', i));
    img = imresize(img, IMG_RES);
    binarizedImg = imbinarize(img);
    letrasBW(:, i) = reshape(binarizedImg, 1, []);
end

letrasTarget = [eye(10)];

%% Preparar e treinar rede

net = feedforwardnet([10]);

net.trainFcn = 'trainlm';
net.layers{1}.transferFcn = 'tansig';
net.layers{2}.transferFcn = 'purelin';
net.divideFcn = 'dividerand';
net.divideParam.trainRatio = 1;
net.divideParam.valRatio = 0;
net.divideParam.testRatio = 0;

[net,tr] = train(net, letrasBW, letrasTarget);

%% Simular e analisar resultados

out = sim(net, letrasBW)

disp(tr);

r = 0;
for i=1:size(out,2)
    [a b] = max(out(:,i));
    [c d] = max(letrasTarget(:,i));
    if b == d
      r = r+1;
    end
end

accuracy = r/size(out,2);
fprintf('Precisao total de treino %f\n', accuracy)

end

