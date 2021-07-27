function rn3b()
%Funcao rn3b: cria, treina e testa uma RN feedforward
%usando as funcoes da NNTool

% limpar
clear all;
close all;

% inicializar entrada
p = [0 0 1 1; 0 1 0 1];

%informacao sobre operador logico 
fprintf('Introduza operador logico desejado:\n');
fprintf('1 - AND\n');
fprintf('2 - OR\n');
fprintf('3 - NAND\n');
fprintf('4 - XOR\n');
tmp =  input('                        operador? (default 1) = ');

% inicializar targets
if isempty(tmp)
    t = [0 0 0 1];
    op='AND';
else
    switch tmp
        case 1
            t = [0 0 0 1];
            op='AND';
        case 2
            t = [0 1 1 1];
            op='OR';
        case 3
            t = [1 1 1 0];
            op='NAND';
        case 4
            t = [0 1 1 0];
            op='XOR';
        otherwise
            t = [0 0 0 1];
            op='AND';
    end
end


% COMPLETAR: criar RN chamada net
net = feedforwardnet( [5 5] );

% COMPLETAR: ajustar os parametros seguintes

% FUNCAO DE ATIVACAO DA CAMADA DE SAIDA
net.layers{3}.transferFcn = 'tansig';

% FUNCAO DE TREINO
net.trainFcn = 'traingdx';

% NUMERO DE EPOCAS DE TREINO
net.trainParam.epochs = 100;

% TODOS OS EXEMPLOS DE INPUT SAO USADOS NO TREINO
net.divideFcn = '';                 

% COMPLETAR: treinar a rede
net = train(net, p, t);

% visualizar a rede
view(net)

% COMPLETAR simular a rede e guardar o resultado na variavel y
y = sim(net, p);

% Mostrar resultado
y = (y >= 0.5);
fprintf('Saida da RN para %s:', op);
disp(y);
fprintf('Saida desejada para %s:', op);
disp(t);

end
