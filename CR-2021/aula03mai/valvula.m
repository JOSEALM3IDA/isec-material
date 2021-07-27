function [ fis ] = valvula()

fis = newfis('tanque');

fis = addvar(fis, 'input', 'nivel', [-1 1]);
fis = addvar(fis, 'input', 'fluxo', [-0.4 0.4]);
fis = addvar(fis, 'output', 'valvula', [-1 1]);

fis = addmf(fis, 'input', 1, 'alto', 'gaussmf', [0.25 0]);
fis = addmf(fis, 'input', 1, 'ok', 'gaussmf', [0.25 0]);
fis = addmf(fis, 'input', 1, 'baixo', 'gaussmf', [0.25 1]);

fis = addmf(fis, 'input', 2, 'negativo', 'gaussmf', [0.03 -0.1]);
fis = addmf(fis, 'input', 2, 'ok', 'gaussmf', [0.03 0]);
fis = addmf(fis, 'input', 2, 'positivo', 'gaussmf', [0.03 0.1]);

fis = addmf(fis, 'output', 1, 'fecha-rapido', 'gaussmf', [-1 -0.9 -0.8]);
fis = addmf(fis, 'output', 1, 'fecha-devagar', 'gaussmf', [-0.6 -0.5 -0.4]);
fis = addmf(fis, 'output', 1, 'nada', 'gaussmf', [-0.1 0 0.1]);
fis = addmf(fis, 'output', 1, 'abre-devagar', 'trimf', [0.2 0.3 0.4]);
fis = addmf(fis, 'output', 1, 'abre-rapido', 'trimf', [0.8 0.9 1]);

% 1. Se o nível da água estiver bom, não ajuste a válvula.
% 2. Se o nível da água estiver baixo, abra a válvula rapidamente.
% 3. Se o nível da água estiver alto, feche a válvula rapidamente.
% 4. Se o nível da água estiver bom e aumentando(positivo), feche a válvula lentamente.
% 5. Se o nível da água estiver bom e diminuindo(negativo), abra a válvula lentamente.

regras = [2 0 3 1 1;
          3 0 5 1 1;
          1 0 1 1 1;
          2 3 2 1 1;
          2 1 4 1 1];
    
fis = addrule(fis, regras);
entrada = [1 1];
out = evalfis(entrada, fis);
fprintf('nivel = %f\nfluxo %f\nvalvula = %f', entrada(1), entrada(2), out);
 
end