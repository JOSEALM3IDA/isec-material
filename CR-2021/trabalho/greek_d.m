function greek_d()

clc;
clear all;
close all;

IMG_RES = [28 28];

%% Escolha de rede

redeTreino = 51;    % Alterar o valor para a rede desejada
letra = 19;       % Alterar o valor para o caracter desejado

netFileStr = strcat('net', int2str(redeTreino), 'c3.mat');
net = load(netFileStr, 'net').net;

%% Testar rede com caracter dado

img = imread(sprintf('Pasta4\\%d.jpg', letra));
img = imresize(img, IMG_RES);
binarizedImg = imbinarize(img);
letraBW(:, 1) = reshape(binarizedImg, 1, []);

identity = eye(10);

if (rem(letra, 10) == 0)
    letraTarget = identity(:, 10);
else
    letraTarget = identity(:, rem(letra, 10));
end

out = sim(net, letraBW)

[~, b] = max(out(:, 1));      
[~, d] = max(letraTarget(:, 1));

%% Analisar resultado

possibleCharacters = ['α' 'β' 'γ' 'ε' 'η' 'θ' 'π' 'ρ' 'ψ' 'ω'];

fprintf('Caracter correto: %c\n', possibleCharacters(d));
fprintf('Caracter escolhido pela rede: %c\n', possibleCharacters(b));

if (b == d)
    disp('Correto!');
else
    disp('Errado!');
end

end